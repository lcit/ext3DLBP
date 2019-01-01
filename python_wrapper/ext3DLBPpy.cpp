/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: ext3DLBPpy.cpp
    Last modifed:   31.12.2018 by Leonardo Citraro
    Description:    Boost-Python wrappers
    *
    Please cite the article:    L. Citraro, S. Mahmoodi, A. Darekar, B. Vollmer,
                                Extended three-dimensional rotation invariant local binary patterns,
                                Image and Vision Computing (2017),
                                http://dx.doi.org/10.1016/j.imavis.2017.03.004

    ==========================================================================================
    Copyright (c) 2017 Leonardo Citraro <ldo.citraro@gmail.com>

    Permission is hereby granted, free of charge, to any person obtaining a copy of this
    software and associated documentation files (the "Software"), to deal in the Software
    without restriction, including without limitation the rights to use, copy, modify,
    merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
    permit persons to whom the Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be included in all copies
    or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
    INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
    PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
    FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
    OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
    ==========================================================================================
*/
#include <Python.h>
#include <boost/python/numpy.hpp>
#include <numpy/ndarrayobject.h>
#include <numpy/arrayobject.h>
#include "ext3DLBP.hpp"

using namespace std;
using namespace ext3DLBP;
namespace p = boost::python;
namespace np = boost::python::numpy;

/**
  *   @brief  This function deletes dynamically allocated memory
  *           from python side when the data is no loguer required.
  */
template<typename T>
inline void CapsuleDestructor(PyObject *ptr){
    T *tmp = reinterpret_cast<T*>(PyCapsule_GetPointer(ptr, NULL));
    if(tmp){
        delete tmp;
    }
}

template<typename T>
inline np::ndarray make_ndarray(T* const ptr, const int H, const int W=0, const int D=0){

    // figuring out the size of the array
    int L;
    if(W<=0 && D<=0){
        L = H;
    }else if(W<=0 && H<=0){
        L = D;
    }else if(H<=0 && D<=0){
        L = H;
    }else if(H<=0){
        L = W*D;
    }else if(W<=0){
        L = H*D;
    }else if(D<=0){
        L = H*W;
    }else{
        L=H*W*D;
    }

    // The object owner is responsible for deleting the dynamic array from the python side
    // This is the trick to prevent memory leaks!
    p::object owner(p::handle<>((PyCapsule_New((void*)ptr, NULL,
                                (PyCapsule_Destructor)&CapsuleDestructor<T>))));

    // Creates a boost numpy array, this is the actual object we return to python
    np::ndarray py_array = np::from_data(ptr,
                                         np::dtype::get_builtin<T>(),
                                         p::make_tuple(L),
                                         p::make_tuple(sizeof(T)),
                                         owner);

    p::tuple shape;
    if(H<=0){
        shape = p::make_tuple(W,D);
    }else if(W<=0){
        shape = p::make_tuple(H,D);
    }else if(D<=0){
        shape = p::make_tuple(H,W);
    }else{
        shape = p::make_tuple(H,W,D);
    }

    py_array = py_array.reshape(shape);

    return py_array;
}

template<typename T, size_t K>
Array3D<T,K,K,K> convert_numpy_to_STL(const np::ndarray& py_array) {
    int H = py_array.shape(0);
    int W = py_array.shape(1);
    int D = py_array.shape(2);
    int L = H*W*D;
    Array3D<T,K,K,K> array;
    T* p_vector;
    for(int k=0; k<D; ++k) {
        for(int j=0; j<W; ++j) {
            np::ndarray py_vector = p::extract<np::ndarray>(py_array[k][j]);
            p_vector = reinterpret_cast<T*>(py_vector.get_data());
            std::copy(p_vector, p_vector+H, array[k][j].begin());
        }
    }
    delete p_vector;
    return array;
}

template<typename T, size_t K>
Array3D<T,K,K,K> my_slice(const np::ndarray& py_volume, const int istart, const int jstart, const int kstart) {
    Array3D<T,K,K,K> array;
    for(int k=0; k<K; ++k) {
        for(int j=0; j<K; ++j) {
            for(int i=0; i<K; ++i) {
                array[i][j][k] = p::extract<T>(py_volume[i+istart][j+jstart][k+kstart]);
            }
        }
    }
    return array;
}

p::tuple convert_to_tuple(const Array1D<int,2>& data) {
    return p::make_tuple(data[0], data[1]);
}
p::tuple convert_to_tuple(const Array1D<int,3>& data) {
    return p::make_tuple(data[0], data[1], data[2]);
}

//=========================================================================
// CI-LBP
//=========================================================================
struct CI_LBP_ : public CI_LBP {
    const static int bins = CI_LBP::bins;
    CI_LBP_(const double mur) : CI_LBP(mur) {}
    // converts a volume of size 3, 5 or 7 voxels
    auto convert(const np::ndarray py_volume) {
        int H = py_volume.shape(0);
        if(H == 3)
            return CI_LBP::convert(convert_numpy_to_STL<int,3>(py_volume));
        else if(H == 5)
            return CI_LBP::convert(convert_numpy_to_STL<int,5>(py_volume));
        else if(H == 7)
            return CI_LBP::convert(convert_numpy_to_STL<int,7>(py_volume));
    }
    // converts a full volume
    auto convert_3d_image(const np::ndarray& py_volume) {
        int H = py_volume.shape(0);
        int W = py_volume.shape(1);
        int D = py_volume.shape(2);

        int* out = new int[H*W*D];

        for(int k=0; k<(D); ++k) {
            for(int j=0; j<(W); ++j) {
                for(int i=0; i<(H); ++i) {
                    int chunk = p::extract<int>(py_volume[i][j][k]);
                    out[k*D*W + j*W + i] = CI_LBP::convert(chunk);
                }
            }
        }

        np::ndarray py_out = make_ndarray(out,H,W,D);

        return py_out;
    }
};
const int CI_LBP_::bins;

//=========================================================================
// NI-LBP
//=========================================================================

#define wrapper_class_1     struct fullname : public parent {\
                                const static int P = parent::P;\
                                const static int O = parent::O;\
                                const static int bins = parent::bins;\
                                const static int R = parent::R;\
                                const static int K = parent::K;\
                                fullname(const double mur, const int V) : parent(mur,V) {}\
                                auto convert(const np::ndarray& py_volume) {\
                                    return parent::convert(convert_numpy_to_STL<int,K>(py_volume));\
                                }\
                                auto convert_3d_image(const np::ndarray& py_volume) {\
                                    int H = py_volume.shape(0);\
                                    int W = py_volume.shape(1);\
                                    int D = py_volume.shape(2);\
                                    \
                                    int H_ = H-2*R;\
                                    int W_ = W-2*R;\
                                    int D_ = D-2*R;\
                                    int* out = new int[H_*W_*D_];\
                                    \
                                    for(int k=0; k<D_; ++k) {\
                                        for(int j=0; j<W_; ++j) {\
                                            for(int i=0; i<H_; ++i) {\
                                                auto chunk = my_slice<int,K>(py_volume,i,j,k);\
                                                out[k*D_*W_ + j*W_ + i] = parent::convert(chunk);\
                                            }\
                                        }\
                                    }\
                                    np::ndarray py_out = make_ndarray(out,H_, W_, D_);\
                                    return py_out;\
                                }\
                            };\
                            const int fullname::P;\
                            const int fullname::bins;\
                            const int fullname::O;\
                            const int fullname::R;\
                            const int fullname::K;\

#define wrapper_class_2     struct fullname : public parent {\
                                const static int P = parent::P;\
                                const static int O = parent::O;\
                                const static int bins = parent::bins;\
                                const static int R = parent::R;\
                                const static int K = parent::K;\
                                fullname(const double mur, const int V) : parent(mur,V) {}\
                                auto convert(const np::ndarray& py_volume) {\
                                    return convert_to_tuple(parent::convert(convert_numpy_to_STL<int,K>(py_volume)));\
                                }\
                                auto convert_3d_image(const np::ndarray& py_volume) {\
                                    int H = py_volume.shape(0);\
                                    int W = py_volume.shape(1);\
                                    int D = py_volume.shape(2);\
                                    \
                                    int H_ = H-2*R;\
                                    int W_ = W-2*R;\
                                    int D_ = D-2*R;\
                                    int* out1 = new int[H_*W_*D_];\
                                    int* out2 = new int[H_*W_*D_];\
                                    \
                                    for(int k=0; k<D_; ++k) {\
                                        for(int j=0; j<W_; ++j) {\
                                            for(int i=0; i<H_; ++i) {\
                                                auto chunk = my_slice<int,K>(py_volume,i,j,k);\
                                                Array1D<int,2> codes = parent::convert(chunk);\
                                                out1[k*D_*W_ + j*W_ + i] = codes[0];\
                                                out2[k*D_*W_ + j*W_ + i] = codes[1];\
                                            }\
                                        }\
                                    }\
                                    np::ndarray py_out1 = make_ndarray(out1, H_, W_, D_);\
                                    np::ndarray py_out2 = make_ndarray(out2, H_, W_, D_);\
                                    return p::make_tuple(py_out1, py_out2);\
                                }\
                            };\
                            const int fullname::P;\
                            const int fullname::bins;\
                            const int fullname::O;\
                            const int fullname::R;\
                            const int fullname::K;\

#define wrapper_class_3     struct fullname : public parent {\
                                const static int P = parent::P;\
                                const static int O = parent::O;\
                                const static int bins = parent::bins;\
                                const static int R = parent::R;\
                                const static int K = parent::K;\
                                fullname(const double mur, const int V) : parent(mur,V) {}\
                                auto convert(const np::ndarray& py_volume) {\
                                    return convert_to_tuple(parent::convert(convert_numpy_to_STL<int,K>(py_volume)));\
                                }\
                                auto convert_3d_image(const np::ndarray& py_volume) {\
                                    int H = py_volume.shape(0);\
                                    int W = py_volume.shape(1);\
                                    int D = py_volume.shape(2);\
                                    \
                                    int H_ = H-2*R;\
                                    int W_ = W-2*R;\
                                    int D_ = D-2*R;\
                                    int* out1 = new int[H_*W_*D_];\
                                    int* out2 = new int[H_*W_*D_];\
                                    int* out3 = new int[H_*W_*D_];\
                                    \
                                    for(int k=0; k<D_; ++k) {\
                                        for(int j=0; j<W_; ++j) {\
                                            for(int i=0; i<H_; ++i) {\
                                                auto chunk = my_slice<int,K>(py_volume,i,j,k);\
                                                Array1D<int,3> codes = parent::convert(chunk);\
                                                out1[k*D_*W_ + j*W_ + i] = codes[0];\
                                                out2[k*D_*W_ + j*W_ + i] = codes[1];\
                                                out3[k*D_*W_ + j*W_ + i] = codes[2];\
                                            }\
                                        }\
                                    }\
                                    np::ndarray py_out1 = make_ndarray(out1,H_, W_, D_);\
                                    np::ndarray py_out2 = make_ndarray(out2,H_, W_, D_);\
                                    np::ndarray py_out3 = make_ndarray(out3,H_, W_, D_);\
                                    return p::make_tuple(py_out1, py_out2, py_out3);\
                                }\
                            };\
                            const int fullname::P;\
                            const int fullname::bins;\
                            const int fullname::O;\
                            const int fullname::R;\
                            const int fullname::K;\

// P42g
#define fullname NI_LBP_P42g_R1
#define parent NI_LBP<P42g, R1>
wrapper_class_1

#define fullname NI_LBP_P42g_R2
#define parent NI_LBP<P42g, R2>
wrapper_class_1

// P92g
#define fullname NI_LBP_P92g_R1
#define parent NI_LBP<P92g, R1>
wrapper_class_1

#define fullname NI_LBP_P92g_R2
#define parent NI_LBP<P92g, R2>
wrapper_class_1

#define fullname NI_LBP_P92g_R3
#define parent NI_LBP<P92g, R3>
wrapper_class_1

// P252g
#define fullname NI_LBP_P252g_R2
#define parent NI_LBP<P252g, R2>
wrapper_class_1

#define fullname NI_LBP_P252g_R3
#define parent NI_LBP<P252g, R3>
wrapper_class_1

//=========================================================================
// RD-LBP
//=========================================================================
// P42g
#define fullname RD_LBP_P42g_R1
#define parent RD_LBP<P42g, R1>
wrapper_class_1

#define fullname RD_LBP_P42g_R2
#define parent RD_LBP<P42g, R2>
wrapper_class_1

// P92g
#define fullname RD_LBP_P92g_R1
#define parent RD_LBP<P92g, R1>
wrapper_class_1

#define fullname RD_LBP_P92g_R2
#define parent RD_LBP<P92g, R2>
wrapper_class_1

#define fullname RD_LBP_P92g_R3
#define parent RD_LBP<P92g, R3>
wrapper_class_1



// P252g
#define fullname RD_LBP_P252g_R2
#define parent RD_LBP<P252g, R2>
wrapper_class_1

#define fullname RD_LBP_P252g_R3
#define parent RD_LBP<P252g, R3>
wrapper_class_1

//=========================================================================
// NI-RD-LBP
//=========================================================================
//P42g
#define fullname NI_RD_LBP_P42g_R1
#define parent NI_RD_LBP<P42g, R1>
wrapper_class_2

#define fullname NI_RD_LBP_P42g_R2
#define parent NI_RD_LBP<P42g, R2>
wrapper_class_2

//P92g
#define fullname NI_RD_LBP_P92g_R1
#define parent NI_RD_LBP<P92g, R1>
wrapper_class_2

#define fullname NI_RD_LBP_P92g_R2
#define parent NI_RD_LBP<P92g, R2>
wrapper_class_2

#define fullname NI_RD_LBP_P92g_R3
#define parent NI_RD_LBP<P92g, R3>
wrapper_class_2

//P252g
#define fullname NI_RD_LBP_P252g_R2
#define parent NI_RD_LBP<P252g, R2>
wrapper_class_2

#define fullname NI_RD_LBP_P252g_R3
#define parent NI_RD_LBP<P252g, R3>
wrapper_class_2

//=========================================================================
// NI-RD-CI-LBP
//=========================================================================
//P42g
#define fullname NI_RD_CI_LBP_P42g_R1
#define parent NI_RD_CI_LBP<P42g, R1>
wrapper_class_3

#define fullname NI_RD_CI_LBP_P42g_R2
#define parent NI_RD_CI_LBP<P42g, R2>
wrapper_class_3

//P92g
#define fullname NI_RD_CI_LBP_P92g_R1
#define parent NI_RD_CI_LBP<P92g, R1>
wrapper_class_3

#define fullname NI_RD_CI_LBP_P92g_R2
#define parent NI_RD_CI_LBP<P92g, R2>
wrapper_class_3

#define fullname NI_RD_CI_LBP_P92g_R3
#define parent NI_RD_CI_LBP<P92g, R3>
wrapper_class_3

//P252g
#define fullname NI_RD_CI_LBP_P252g_R2
#define parent NI_RD_CI_LBP<P252g, R2>
wrapper_class_3

#define fullname NI_RD_CI_LBP_P252g_R3
#define parent NI_RD_CI_LBP<P252g, R3>
wrapper_class_3

BOOST_PYTHON_MODULE(ext3DLBPpy) {
    Py_Initialize();
    np::initialize();

    // CI-LBP
    p::class_<CI_LBP_>("CI_LBP",p::init<double>())
        .def_readonly("mur", &CI_LBP_::mur)
        .def_readonly("bins", &CI_LBP_::bins)
        .def("convert", &CI_LBP_::convert)
        .def("convert_3d_image", &CI_LBP_::convert_3d_image);

#define STRINGIZE_NX(A) #A
#define STRINGIZE(A) STRINGIZE_NX(A)
#define boost_python_definition p::class_<fullname>(STRINGIZE(fullname),p::init<double, int>())\
                                .def_readonly("P", &fullname::P)\
                                .def_readonly("O", &fullname::O)\
                                .def_readonly("bins", &fullname::bins)\
                                .def_readonly("R", &fullname::R)\
                                .def_readonly("K", &fullname::K)\
                                .def_readonly("mur", &fullname::mur)\
                                .def_readonly("V", &fullname::V)\
                                .def("convert", &fullname::convert) \
                                .def("convert_3d_image", &fullname::convert_3d_image);
// NI-LBP
#define fullname NI_LBP_P42g_R1
boost_python_definition

#define fullname NI_LBP_P42g_R2
boost_python_definition


#define fullname NI_LBP_P92g_R1
boost_python_definition

#define fullname NI_LBP_P92g_R2
boost_python_definition

#define fullname NI_LBP_P92g_R3
boost_python_definition


#define fullname NI_LBP_P252g_R2
boost_python_definition

#define fullname NI_LBP_P252g_R3
boost_python_definition

// RD-LBP
#define fullname RD_LBP_P42g_R1
boost_python_definition

#define fullname RD_LBP_P42g_R2
boost_python_definition


#define fullname RD_LBP_P92g_R1
boost_python_definition

#define fullname RD_LBP_P92g_R2
boost_python_definition

#define fullname RD_LBP_P92g_R3
boost_python_definition


#define fullname RD_LBP_P252g_R2
boost_python_definition

#define fullname RD_LBP_P252g_R3
boost_python_definition

// NI-RD-LBP
#define fullname NI_RD_LBP_P42g_R1
boost_python_definition

#define fullname NI_RD_LBP_P42g_R2
boost_python_definition


#define fullname NI_RD_LBP_P92g_R1
boost_python_definition

#define fullname NI_RD_LBP_P92g_R2
boost_python_definition

#define fullname NI_RD_LBP_P92g_R3
boost_python_definition


#define fullname NI_RD_LBP_P252g_R2
boost_python_definition

#define fullname NI_RD_LBP_P252g_R3
boost_python_definition


// NI-RD-CI-LBP
#define fullname NI_RD_CI_LBP_P42g_R1
boost_python_definition

#define fullname NI_RD_CI_LBP_P42g_R2
boost_python_definition


#define fullname NI_RD_CI_LBP_P92g_R1
boost_python_definition

#define fullname NI_RD_CI_LBP_P92g_R2
boost_python_definition

#define fullname NI_RD_CI_LBP_P92g_R3
boost_python_definition



#define fullname NI_RD_CI_LBP_P252g_R2
boost_python_definition

#define fullname NI_RD_CI_LBP_P252g_R3
boost_python_definition

};
