/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: ext3DLBPpy.cpp
    Last modifed:   06.04.2017 by Leonardo Citraro
    Description:    Boost-Python wrapper
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
#include <boost/python.hpp>
#include "boost/python/extract.hpp"
#include "boost/python/numeric.hpp"
#include "ext3DLBP.hpp"

using namespace ext3DLBP;
using namespace boost::python;

template<typename T, size_t K>
Array3D<T,K,K,K> convert_numpy_to_STL(const boost::python::numeric::array& data) {
    Array3D<T,K,K,K> array;
    for(int k=0; k<K; ++k) {
        for(int j=0; j<K; ++j) {
            for(int i=0; i<K; ++i) {
                array[k][j][i] = extract<T>(data[k][j][i]);
            }
        }
    }
    return array;
}

boost::python::tuple STL_to_python_tuple(const Array1D<int,2>& data) {
    return boost::python::make_tuple(data[0], data[1]);
}
boost::python::tuple STL_to_python_tuple(const Array1D<int,3>& data) {
    return boost::python::make_tuple(data[0], data[1], data[2]);
}

//=========================================================================
// CI-LBP
//=========================================================================
struct CI_LBP_ : public CI_LBP {
    CI_LBP_(const double mur) : CI_LBP(mur) {}
    auto convert(const boost::python::numeric::array data) {
        int shape0 = extract<int>(data.attr("shape")[0]);
        if(shape0 == 3)
            return CI_LBP::convert(convert_numpy_to_STL<int,3>(data));
        else if(shape0 == 5)
            return CI_LBP::convert(convert_numpy_to_STL<int,3>(data));
        else if(shape0 == 7)
            return CI_LBP::convert(convert_numpy_to_STL<int,3>(data));
    }
};
/*
int (CI_LBP_::*convert3)(Array3D<int,3,3,3>) = &CI_LBP_::convert;
int (CI_LBP_::*convert5)(Array3D<int,5,5,5>) = &CI_LBP_::convert;
int (CI_LBP_::*convert7)(Array3D<int,7,7,7>) = &CI_LBP_::convert;
*/

//=========================================================================
// NI-LBP
//=========================================================================
struct NI_LBP_P42g_R1 : public NI_LBP<P42g, R1> {
    NI_LBP_P42g_R1(const double mur, const int V) : NI_LBP<P42g, R1>(mur,V) {}
    auto convert(const boost::python::numeric::array& data) {
        return NI_LBP<P42g, R1>::convert(convert_numpy_to_STL<int,3>(data));
    }
};

struct NI_LBP_P42g_R2 : public NI_LBP<P42g, R2> {
    NI_LBP_P42g_R2(const double mur, const int V) : NI_LBP<P42g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return NI_LBP<P42g, R2>::convert(convert_numpy_to_STL<int,5>(data));
    }
};




struct NI_LBP_P92g_R1 : public NI_LBP<P92g, R1> {
    NI_LBP_P92g_R1(const double mur, const int V) : NI_LBP<P92g, R1>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return NI_LBP<P92g, R1>::convert(convert_numpy_to_STL<int,3>(data));
    }
};
struct NI_LBP_P92g_R2 : public NI_LBP<P92g, R2> {
    NI_LBP_P92g_R2(const double mur, const int V) : NI_LBP<P92g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return NI_LBP<P92g, R2>::convert(convert_numpy_to_STL<int,5>(data));
    }
};
struct NI_LBP_P92g_R3 : public NI_LBP<P92g, R3> {
    NI_LBP_P92g_R3(const double mur, const int V) : NI_LBP<P92g, R3>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return NI_LBP<P92g, R3>::convert(convert_numpy_to_STL<int,7>(data));
    }
};




struct NI_LBP_P252g_R2 : public NI_LBP<P252g, R2> {
    NI_LBP_P252g_R2(const double mur, const int V) : NI_LBP<P252g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return NI_LBP<P252g, R2>::convert(convert_numpy_to_STL<int,5>(data));
    }
};
struct NI_LBP_P252g_R3 : public NI_LBP<P252g, R3> {
    NI_LBP_P252g_R3(const double mur, const int V) : NI_LBP<P252g, R3>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return NI_LBP<P252g, R3>::convert(convert_numpy_to_STL<int,7>(data));
    }
};

//=========================================================================
// RD-LBP
//=========================================================================
struct RD_LBP_P42g_R1 : public RD_LBP<P42g, R1> {
    RD_LBP_P42g_R1(const double mur, const int V) : RD_LBP<P42g, R1>(mur,V) {}
    auto convert(const boost::python::numeric::array& data) {
        return RD_LBP<P42g, R1>::convert(convert_numpy_to_STL<int,3>(data));
    }
};

struct RD_LBP_P42g_R2 : public RD_LBP<P42g, R2> {
    RD_LBP_P42g_R2(const double mur, const int V) : RD_LBP<P42g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return RD_LBP<P42g, R2>::convert(convert_numpy_to_STL<int,5>(data));
    }
};




struct RD_LBP_P92g_R1 : public RD_LBP<P92g, R1> {
    RD_LBP_P92g_R1(const double mur, const int V) : RD_LBP<P92g, R1>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return RD_LBP<P92g, R1>::convert(convert_numpy_to_STL<int,3>(data));
    }
};
struct RD_LBP_P92g_R2 : public RD_LBP<P92g, R2> {
    RD_LBP_P92g_R2(const double mur, const int V) : RD_LBP<P92g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return RD_LBP<P92g, R2>::convert(convert_numpy_to_STL<int,5>(data));
    }
};
struct RD_LBP_P92g_R3 : public RD_LBP<P92g, R3> {
    RD_LBP_P92g_R3(const double mur, const int V) : RD_LBP<P92g, R3>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return RD_LBP<P92g, R3>::convert(convert_numpy_to_STL<int,7>(data));
    }
};




struct RD_LBP_P252g_R2 : public RD_LBP<P252g, R2> {
    RD_LBP_P252g_R2(const double mur, const int V) : RD_LBP<P252g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return RD_LBP<P252g, R2>::convert(convert_numpy_to_STL<int,5>(data));
    }
};
struct RD_LBP_P252g_R3 : public RD_LBP<P252g, R3> {
    RD_LBP_P252g_R3(const double mur, const int V) : RD_LBP<P252g, R3>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return RD_LBP<P252g, R3>::convert(convert_numpy_to_STL<int,7>(data));
    }
};

//=========================================================================
// NI-RD-LBP
//=========================================================================
struct NI_RD_LBP_P42g_R1 : public NI_RD_LBP<P42g, R1> {
    NI_RD_LBP_P42g_R1(const double mur, const int V) : NI_RD_LBP<P42g, R1>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_LBP<P42g, R1>::convert(convert_numpy_to_STL<int,3>(data)));
    }
};

struct NI_RD_LBP_P42g_R2 : public NI_RD_LBP<P42g, R2> {
    NI_RD_LBP_P42g_R2(const double mur, const int V) : NI_RD_LBP<P42g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_LBP<P42g, R2>::convert(convert_numpy_to_STL<int,5>(data)));
    }
};




struct NI_RD_LBP_P92g_R1 : public NI_RD_LBP<P92g, R1> {
    NI_RD_LBP_P92g_R1(const double mur, const int V) : NI_RD_LBP<P92g, R1>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_LBP<P92g, R1>::convert(convert_numpy_to_STL<int,3>(data)));
    }
};
struct NI_RD_LBP_P92g_R2 : public NI_RD_LBP<P92g, R2> {
    NI_RD_LBP_P92g_R2(const double mur, const int V) : NI_RD_LBP<P92g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_LBP<P92g, R2>::convert(convert_numpy_to_STL<int,5>(data)));
    }
};
struct NI_RD_LBP_P92g_R3 : public NI_RD_LBP<P92g, R3> {
    NI_RD_LBP_P92g_R3(const double mur, const int V) : NI_RD_LBP<P92g, R3>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_LBP<P92g, R3>::convert(convert_numpy_to_STL<int,7>(data)));
    }
};




struct NI_RD_LBP_P252g_R2 : public NI_RD_LBP<P252g, R2> {
    NI_RD_LBP_P252g_R2(const double mur, const int V) : NI_RD_LBP<P252g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_LBP<P252g, R2>::convert(convert_numpy_to_STL<int,5>(data)));
    }
};
struct NI_RD_LBP_P252g_R3 : public NI_RD_LBP<P252g, R3> {
    NI_RD_LBP_P252g_R3(const double mur, const int V) : NI_RD_LBP<P252g, R3>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_LBP<P252g, R3>::convert(convert_numpy_to_STL<int,7>(data)));
    }
};

//=========================================================================
// NI-RD-CI-LBP
//=========================================================================
struct NI_RD_CI_LBP_P42g_R1 : public NI_RD_CI_LBP<P42g, R1> {
    NI_RD_CI_LBP_P42g_R1(const double mur, const int V) : NI_RD_CI_LBP<P42g, R1>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_CI_LBP<P42g, R1>::convert(convert_numpy_to_STL<int,3>(data)));
    }
};

struct NI_RD_CI_LBP_P42g_R2 : public NI_RD_CI_LBP<P42g, R2> {
    NI_RD_CI_LBP_P42g_R2(const double mur, const int V) : NI_RD_CI_LBP<P42g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_CI_LBP<P42g, R2>::convert(convert_numpy_to_STL<int,5>(data)));
    }
};




struct NI_RD_CI_LBP_P92g_R1 : public NI_RD_CI_LBP<P92g, R1> {
    NI_RD_CI_LBP_P92g_R1(const double mur, const int V) : NI_RD_CI_LBP<P92g, R1>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_CI_LBP<P92g, R1>::convert(convert_numpy_to_STL<int,3>(data)));
    }
};
struct NI_RD_CI_LBP_P92g_R2 : public NI_RD_CI_LBP<P92g, R2> {
    NI_RD_CI_LBP_P92g_R2(const double mur, const int V) : NI_RD_CI_LBP<P92g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_CI_LBP<P92g, R2>::convert(convert_numpy_to_STL<int,5>(data)));
    }
};
struct NI_RD_CI_LBP_P92g_R3 : public NI_RD_CI_LBP<P92g, R3> {
    NI_RD_CI_LBP_P92g_R3(const double mur, const int V) : NI_RD_CI_LBP<P92g, R3>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_CI_LBP<P92g, R3>::convert(convert_numpy_to_STL<int,7>(data)));
    }
};




struct NI_RD_CI_LBP_P252g_R2 : public NI_RD_CI_LBP<P252g, R2> {
    NI_RD_CI_LBP_P252g_R2(const double mur, const int V) : NI_RD_CI_LBP<P252g, R2>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_CI_LBP<P252g, R2>::convert(convert_numpy_to_STL<int,5>(data)));
    }
};
struct NI_RD_CI_LBP_P252g_R3 : public NI_RD_CI_LBP<P252g, R3> {
    NI_RD_CI_LBP_P252g_R3(const double mur, const int V) : NI_RD_CI_LBP<P252g, R3>(mur,V) {}
    auto convert(const boost::python::numeric::array data) {
        return STL_to_python_tuple(NI_RD_CI_LBP<P252g, R3>::convert(convert_numpy_to_STL<int,7>(data)));
    }
};

BOOST_PYTHON_MODULE(ext3DLBPpy) {
    boost::python::numeric::array::set_module_and_type("numpy", "ndarray");
    
    // CI-LBP
    class_<CI_LBP_>("CI_LBP",init<double>())
        .def("convert", &CI_LBP_::convert);
    
    
    // NI-LBP
    class_<NI_LBP_P42g_R1>("NI_LBP_P42g_R1",init<double, int>())
        .def("convert", &NI_LBP_P42g_R1::convert);
    class_<NI_LBP_P42g_R2>("NI_LBP_P42g_R2",init<double, int>())
        .def("convert", &NI_LBP_P42g_R2::convert);
        
    
    class_<NI_LBP_P92g_R1>("NI_LBP_P92g_R1",init<double, int>())
        .def("convert", &NI_LBP_P92g_R1::convert);
    class_<NI_LBP_P92g_R2>("NI_LBP_P92g_R2",init<double, int>())
        .def("convert", &NI_LBP_P92g_R2::convert);
    class_<NI_LBP_P92g_R3>("NI_LBP_P92g_R3",init<double, int>())
        .def("convert", &NI_LBP_P92g_R3::convert);
        
    
    class_<NI_LBP_P252g_R2>("NI_LBP_P252g_R2",init<double, int>())
        .def("convert", &NI_LBP_P252g_R2::convert);
    class_<NI_LBP_P252g_R3>("NI_LBP_P252g_R3",init<double, int>())
        .def("convert", &NI_LBP_P252g_R3::convert);

    // RD-LBP
    class_<RD_LBP_P42g_R1>("RD_LBP_P42g_R1",init<double, int>())
        .def("convert", &RD_LBP_P42g_R1::convert);
    class_<RD_LBP_P42g_R2>("RD_LBP_P42g_R2",init<double, int>())
        .def("convert", &RD_LBP_P42g_R2::convert);
        
    
    class_<RD_LBP_P92g_R1>("RD_LBP_P92g_R1",init<double, int>())
        .def("convert", &RD_LBP_P92g_R1::convert);
    class_<RD_LBP_P92g_R2>("RD_LBP_P92g_R2",init<double, int>())
        .def("convert", &RD_LBP_P92g_R2::convert);
    class_<RD_LBP_P92g_R3>("RD_LBP_P92g_R3",init<double, int>())
        .def("convert", &RD_LBP_P92g_R3::convert);
        
    
    class_<RD_LBP_P252g_R2>("RD_LBP_P252g_R2",init<double, int>())
        .def("convert", &RD_LBP_P252g_R2::convert);
    class_<RD_LBP_P252g_R3>("RD_LBP_P252g_R3",init<double, int>())
        .def("convert", &RD_LBP_P252g_R3::convert);
        
    // NI-RD-LBP
    class_<NI_RD_LBP_P42g_R1>("NI_RD_LBP_P42g_R1",init<double, int>())
        .def("convert", &NI_RD_LBP_P42g_R1::convert);
    class_<NI_RD_LBP_P42g_R2>("NI_RD_LBP_P42g_R2",init<double, int>())
        .def("convert", &NI_RD_LBP_P42g_R2::convert);
        
    
    class_<NI_RD_LBP_P92g_R1>("NI_RD_LBP_P92g_R1",init<double, int>())
        .def("convert", &NI_RD_LBP_P92g_R1::convert);
    class_<NI_RD_LBP_P92g_R2>("NI_RD_LBP_P92g_R2",init<double, int>())
        .def("convert", &NI_RD_LBP_P92g_R2::convert);
    class_<NI_RD_LBP_P92g_R3>("NI_RD_LBP_P92g_R3",init<double, int>())
        .def("convert", &NI_RD_LBP_P92g_R3::convert);
        
    
    class_<NI_RD_LBP_P252g_R2>("NI_RD_LBP_P252g_R2",init<double, int>())
        .def("convert", &NI_RD_LBP_P252g_R2::convert);
    class_<NI_RD_LBP_P252g_R3>("NI_RD_LBP_P252g_R3",init<double, int>())
        .def("convert", &NI_RD_LBP_P252g_R3::convert);
        
    
    // NI-RD-CI-LBP
    class_<NI_RD_CI_LBP_P42g_R1>("NI_RD_CI_LBP_P42g_R1",init<double, int>())
        .def("convert", &NI_RD_CI_LBP_P42g_R1::convert);
    class_<NI_RD_CI_LBP_P42g_R2>("NI_RD_CI_LBP_P42g_R2",init<double, int>())
        .def("convert", &NI_RD_CI_LBP_P42g_R2::convert);
        
    
    class_<NI_RD_CI_LBP_P92g_R1>("NI_RD_CI_LBP_P92g_R1",init<double, int>())
        .def("convert", &NI_RD_CI_LBP_P92g_R1::convert);
    class_<NI_RD_CI_LBP_P92g_R2>("NI_RD_CI_LBP_P92g_R2",init<double, int>())
        .def("convert", &NI_RD_CI_LBP_P92g_R2::convert);
    class_<NI_RD_CI_LBP_P92g_R3>("NI_RD_CI_LBP_P92g_R3",init<double, int>())
        .def("convert", &NI_RD_CI_LBP_P92g_R3::convert);
        
    
    class_<NI_RD_CI_LBP_P252g_R2>("NI_RD_CI_LBP_P252g_R2",init<double, int>())
        .def("convert", &NI_RD_CI_LBP_P252g_R2::convert);
    class_<NI_RD_CI_LBP_P252g_R3>("NI_RD_CI_LBP_P252g_R3",init<double, int>())
        .def("convert", &NI_RD_CI_LBP_P252g_R3::convert);
};









