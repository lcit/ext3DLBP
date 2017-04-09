/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: ext3DLBPpy.cpp
    Last modifed:   09.04.2017 by Leonardo Citraro
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
#include <boost/python.hpp>
#include <boost/python/extract.hpp>
#include <boost/python/numeric.hpp>
#include <numpy/ndarrayobject.h>
#include "ext3DLBP.hpp"

using namespace ext3DLBP;
using namespace boost::python;

template<typename T, size_t K>
Array3D<T,K,K,K> convert_numpy_to_STL(const numeric::array& data) {
    Array3D<T,K,K,K> array;
    for(int k=0; k<K; ++k) {
        for(int j=0; j<K; ++j) {
            for(int i=0; i<K; ++i) {
                array[i][j][k] = extract<T>(data[i][j][k]);
            }
        }
    } 
    return array;
}

template<typename T, size_t K>
Array3D<T,K,K,K> my_slice(const numeric::array& data, const int istart, const int jstart, const int kstart) {
    Array3D<T,K,K,K> array;
    for(int k=0; k<K; ++k) {
        for(int j=0; j<K; ++j) {
            for(int i=0; i<K; ++i) {
                array[i][j][k] = extract<T>(data[i+istart][j+jstart][k+kstart]);
            }
        }
    } 
    return array;
}

boost::python::tuple convert_to_python_return(const Array1D<int,2>& data) {
    return boost::python::make_tuple(data[0], data[1]);
}
boost::python::tuple convert_to_python_return(const Array1D<int,3>& data) {
    return boost::python::make_tuple(data[0], data[1], data[2]);
}
int convert_to_python_return(const int data) {
    return data;
}

//=========================================================================
// CI-LBP
//=========================================================================
struct CI_LBP_ : public CI_LBP {
    const static int bins = CI_LBP::bins;
    CI_LBP_(const double mur) : CI_LBP(mur) {}
    auto convert(const boost::python::numeric::array data) {
        int shape0 = extract<int>(data.attr("shape")[0]);
        if(shape0 == 3)
            return CI_LBP::convert(convert_numpy_to_STL<int,3>(data));
        else if(shape0 == 5)
            return CI_LBP::convert(convert_numpy_to_STL<int,5>(data));
        else if(shape0 == 7)
            return CI_LBP::convert(convert_numpy_to_STL<int,7>(data));
    }
    auto convert_3d_image(const numeric::array& image) {
        int depth = extract<int>(image.attr("shape")[0]);
        int cols = extract<int>(image.attr("shape")[1]);
        int rows = extract<int>(image.attr("shape")[2]);
        
        npy_intp size[3] = {depth-2, cols-2, rows-2};
        PyObject* arr_3d_1Obj = PyArray_SimpleNew(3, size, NPY_INT);
        
        for(int k=0; k<(depth); ++k) {
            for(int j=0; j<(cols); ++j) {
                for(int i=0; i<(rows); ++i) {
                    int chunk = extract<int>(image[i][j][k]);
                    int* ptr = (int*) PyArray_GETPTR3(arr_3d_1Obj, i, j, k);
                    *ptr = CI_LBP::convert(chunk);
                }
            }
        }
        boost::python::handle<> handle( arr_3d_1Obj );
        boost::python::numeric::array arr_3d_1( handle );
        return arr_3d_1;
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
                                auto convert(const boost::python::numeric::array& data) {\
                                    return convert_to_python_return(parent::convert(convert_numpy_to_STL<int,K>(data)));\
                                }\
                                auto convert_3d_image(const numeric::array& image) {\
                                    int depth = extract<int>(image.attr("shape")[0]);\
                                    int cols = extract<int>(image.attr("shape")[1]);\
                                    int rows = extract<int>(image.attr("shape")[2]);\
                                    \
                                    npy_intp size[3] = {depth-2*R, cols-2*R, rows-2*R};\
                                    PyObject* arr_3d_1Obj = PyArray_SimpleNew(3, size, NPY_INT);\
                                    \
                                    for(int k=0; k<(depth-K+1); ++k) {\
                                        for(int j=0; j<(cols-K+1); ++j) {\
                                            for(int i=0; i<(rows-K+1); ++i) {\
                                                auto chunk = my_slice<int,K>(image,i,j,k);\
                                                int* ptr = (int*) PyArray_GETPTR3(arr_3d_1Obj, i, j, k);\
                                                *ptr = parent::convert(chunk);\
                                            }\
                                        }\
                                    }\
                                    boost::python::handle<> handle( arr_3d_1Obj );\
                                    boost::python::numeric::array arr_3d_1( handle );\
                                    return arr_3d_1;\
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
                                auto convert(const boost::python::numeric::array& data) {\
                                    return convert_to_python_return(parent::convert(convert_numpy_to_STL<int,K>(data)));\
                                }\
                                auto convert_3d_image(const numeric::array& image) {\
                                    int depth = extract<int>(image.attr("shape")[0]);\
                                    int cols = extract<int>(image.attr("shape")[1]);\
                                    int rows = extract<int>(image.attr("shape")[2]);\
                                    \
                                    npy_intp size[3] = {depth-2*R, cols-2*R, rows-2*R};\
                                    PyObject* arr_3d_1Obj = PyArray_SimpleNew(3, size, NPY_INT);\
                                    PyObject* arr_3d_2Obj = PyArray_SimpleNew(3, size, NPY_INT);\
                                    \
                                    for(int k=0; k<(depth-K+1); ++k) {\
                                        for(int j=0; j<(cols-K+1); ++j) {\
                                            for(int i=0; i<(rows-K+1); ++i) {\
                                                auto chunk = my_slice<int,K>(image,i,j,k);\
                                                Array1D<int,2> codes = parent::convert(chunk);\
                                                int* ptr = (int*) PyArray_GETPTR3(arr_3d_1Obj, i, j, k);\
                                                *ptr = codes[0];\
                                                ptr = (int*) PyArray_GETPTR3(arr_3d_2Obj, i, j, k);\
                                                *ptr = codes[1];\
                                            }\
                                        }\
                                    }\
                                    boost::python::handle<> handle1( arr_3d_1Obj );\
                                    boost::python::numeric::array arr_3d_1( handle1 );\
                                    boost::python::handle<> handle2( arr_3d_2Obj );\
                                    boost::python::numeric::array arr_3d_2( handle2 );\
                                    return make_tuple(arr_3d_1, arr_3d_2);\
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
                                auto convert(const boost::python::numeric::array& data) {\
                                    return convert_to_python_return(parent::convert(convert_numpy_to_STL<int,K>(data)));\
                                }\
                                auto convert_3d_image(const numeric::array& image) {\
                                    int depth = extract<int>(image.attr("shape")[0]);\
                                    int cols = extract<int>(image.attr("shape")[1]);\
                                    int rows = extract<int>(image.attr("shape")[2]);\
                                    \
                                    npy_intp size[3] = {depth-2*R, cols-2*R, rows-2*R};\
                                    PyObject* arr_3d_1Obj = PyArray_SimpleNew(3, size, NPY_INT);\
                                    PyObject* arr_3d_2Obj = PyArray_SimpleNew(3, size, NPY_INT);\
                                    PyObject* arr_3d_3Obj = PyArray_SimpleNew(3, size, NPY_INT);\
                                    \
                                    for(int k=0; k<(depth-K+1); ++k) {\
                                        for(int j=0; j<(cols-K+1); ++j) {\
                                            for(int i=0; i<(rows-K+1); ++i) {\
                                                auto chunk = my_slice<int,K>(image,i,j,k);\
                                                Array1D<int,3> codes = parent::convert(chunk);\
                                                int* ptr = (int*) PyArray_GETPTR3(arr_3d_1Obj, i, j, k);\
                                                *ptr = codes[0];\
                                                ptr = (int*) PyArray_GETPTR3(arr_3d_2Obj, i, j, k);\
                                                *ptr = codes[1];\
                                                ptr = (int*) PyArray_GETPTR3(arr_3d_3Obj, i, j, k);\
                                                *ptr = codes[2];\
                                            }\
                                        }\
                                    }\
                                    boost::python::handle<> handle1( arr_3d_1Obj );\
                                    boost::python::numeric::array arr_3d_1( handle1 );\
                                    boost::python::handle<> handle2( arr_3d_2Obj );\
                                    boost::python::numeric::array arr_3d_2( handle2 );\
                                    boost::python::handle<> handle3( arr_3d_3Obj );\
                                    boost::python::numeric::array arr_3d_3( handle3 );\
                                    return make_tuple(arr_3d_1, arr_3d_2, arr_3d_3);\
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
    boost::python::numeric::array::set_module_and_type("numpy", "ndarray");
    
    import_array();
    
    // CI-LBP
    class_<CI_LBP_>("CI_LBP",init<double>())
        .def_readonly("mur", &CI_LBP_::mur)
        .def_readonly("bins", &CI_LBP_::bins)
        .def("convert", &CI_LBP_::convert)
        .def("convert_3d_image", &CI_LBP_::convert_3d_image);

#define STRINGIZE_NX(A) #A
#define STRINGIZE(A) STRINGIZE_NX(A)
#define boost_python_definition class_<fullname>(STRINGIZE(fullname),init<double, int>())\
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









