/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: interpolation.hpp
    Last modifed:   04.04.2017 by Leonardo Citraro
    Description:    Hard coded trilinear interpolations for geodesic spheres
                    of 42, 92 and 252 vertexes with different radii.
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

#ifndef __INTERPOLATION_HPP__
#define __INTERPOLATION_HPP__

#include "types.hpp"

#include "interpolation_3d_r0_kx.hpp"

#include "interpolation_3d_42_r1_k3.hpp"
#include "interpolation_3d_42_r1_k5.hpp"
#include "interpolation_3d_42_r2_k5.hpp"

#include "interpolation_3d_92_r1_k3.hpp"
#include "interpolation_3d_92_r1_k5.hpp"
#include "interpolation_3d_92_r2_k5.hpp"
#include "interpolation_3d_92_r2_k7.hpp"
#include "interpolation_3d_92_r3_k7.hpp"

#include "interpolation_3d_252_r1_k5.hpp"
#include "interpolation_3d_252_r2_k5.hpp"
#include "interpolation_3d_252_r2_k7.hpp"
#include "interpolation_3d_252_r3_k7.hpp"

template<typename Vertexes, typename Radius>
struct Interpolation {};

template<>
struct Interpolation<P42g, R1> {
    static Array1D<double,42> _extern(const Array3D<int,3,3,3>& array) {
        return interpolation_3d_42_r1_k3(array);
    }
    static double _intern(const Array3D<int,3,3,3>& array) {
        return interpolation_3d_r0_k3(array);
    }
};

template<>
struct Interpolation<P42g, R2> {
    static Array1D<double,42> _extern(const Array3D<int,5,5,5>& array) {
        return interpolation_3d_42_r2_k5(array);
    }
    static Array1D<double,42> _intern(const Array3D<int,5,5,5>& array) {
        return interpolation_3d_42_r1_k5(array);
    }
};

template<>
struct Interpolation<P42g, R3>;

template<>
struct Interpolation<P92g, R1> {
    static Array1D<double,92> _extern(const Array3D<int,3,3,3>& array) {
        return interpolation_3d_92_r1_k3(array);
    }
    static double _intern(const Array3D<int,3,3,3>& array) {
        return interpolation_3d_r0_k3(array);
    }
};

template<>
struct Interpolation<P92g, R2> {
    static Array1D<double,92> _extern(const Array3D<int,5,5,5>& array) {
        return interpolation_3d_92_r2_k5(array);
    }
    static Array1D<double,92> _intern(const Array3D<int,5,5,5>& array) {
        return interpolation_3d_92_r1_k5(array);
    }
};

template<>
struct Interpolation<P92g, R3> {
    static Array1D<double,92> _extern(const Array3D<int,7,7,7>& array) {
        return interpolation_3d_92_r3_k7(array);
    }
    static Array1D<double,92> _intern(const Array3D<int,7,7,7>& array) {
        return interpolation_3d_92_r2_k7(array);
    }
};

template<>
struct Interpolation<P252g, R1>;

template<>
struct Interpolation<P252g, R2> {
    static Array1D<double,252> _extern(const Array3D<int,5,5,5>& array) {
        return interpolation_3d_252_r2_k5(array);
    }
    static Array1D<double,252> _intern(const Array3D<int,5,5,5>& array) {
        return interpolation_3d_252_r1_k5(array);
    }
};

template<>
struct Interpolation<P252g, R3> {
    static Array1D<double,252> _extern(const Array3D<int,7,7,7>& array) {
        return interpolation_3d_252_r3_k7(array);
    }
    static Array1D<double,252> _intern(const Array3D<int,7,7,7>& array) {
        return interpolation_3d_252_r2_k7(array);
    }
};

#endif
