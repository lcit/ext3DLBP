/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: 
    Last modifed:   04.04.2017 by Leonardo Citraro
    Description:    

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

#ifndef __INTERPOLATION_3D_R0_HPP__
#define __INTERPOLATION_3D_R0_HPP__

#include "utils.hpp"

static double interpolation_3d_r0_k3(const Array3D<int,3,3,3>& array) {
    return array[1][1][1];
}

static double interpolation_3d_r0_k5(const Array3D<int,5,5,5>& array) {
    return array[2][2][2];
}

static double interpolation_3d_r0_k7(const Array3D<int,7,7,7>& array) {
    return array[3][3][3];
}

#endif
