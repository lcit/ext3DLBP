/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: types.hpp
    Last modifed:   03.04.2017 by Leonardo Citraro
    Description:    Ensemble of structures defining the LBPs
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
#ifndef __TYPES_HPP__
#define __TYPES_HPP__

// Vertexes
struct P42g {
    const static int P = 42;
    const static int O = 6;
    const static int bins = 44;
};
struct P92g {
    const static int P = 92;
    const static int O = 6;
    const static int bins = 94;
};
struct P252g {
    const static int P = 252;
    const static int O = 6;
    const static int bins = 254;
};

// Radius
struct R1 {
    const static int R = 1;
    const static int K = R*2+1;
};
struct R2 {
    const static int R = 2;
    const static int K = R*2+1;
};
struct R3 {
    const static int R = 3;
    const static int K = R*2+1;
};

#endif
