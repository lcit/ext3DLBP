/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: main.cpp
    Last modifed:   06.04.2017 by Leonardo Citraro
    Description:    Extended three-dimensional rotation invariant local binary patterns (LBP)
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
#include "ext3DLBP.hpp"
#include <iostream>
#include <array>

int main(int argc, char* argv[]){
    
    Array3D<int,3,3,3> array3 = {{
            {{{0,0,0},{0,0,0},{0,0,0}}},
            {{{0,0,0},{0,0,0},{0,0,0}}},
            {{{0,0,0},{0,0,0},{0,0,0}}}
        }};
        
    Array3D<int,5,5,5> array5 = {{
            {{{0,0,0},{0,0,0},{0,0,0}}},
            {{{0,0,0},{0,0,0},{0,0,0}}},
            {{{0,0,0},{0,0,0},{0,0,0}}}
        }};
    
    double mur = 128.0;
    int V = 3;
    
    //==============================================
    // NI-LBP_42_r1
    //==============================================
    ext3DLBP::NI_LBP<P42g, R1> NI_lbp(mur, V);
    
    int NI_code = NI_lbp.convert(array3);
    
    std::cout << "codes(NI) = (" << NI_code << ")\n";
    
    //==============================================
    // RD-LBP_92_r1
    //==============================================
    ext3DLBP::RD_LBP<P92g, R1> RD_lbp(mur, V);
    
    int RD_code = RD_lbp.convert(array3);
    
    std::cout << "codes(RD) = (" << RD_code << ")\n";
    
    //==============================================
    // NI-RD-LBP_42_r1
    //==============================================
    ext3DLBP::NI_RD_LBP<P42g, R1> NI_RD_lbp(mur, V);
    
    Array1D<int,2> NI_RD_code = NI_RD_lbp.convert(array3);
    
    std::cout << "codes(NI,RD) = (" << NI_RD_code[0] << "," << NI_RD_code[1] << ")\n";
    
    //==============================================
    // NI-RD-CI-LBP_252_r1
    //==============================================
    ext3DLBP::NI_RD_CI_LBP<P252g, R2> NI_RD_CI_lbp(mur, V);
    
    Array1D<int,3> NI_RD_CI_code = NI_RD_CI_lbp.convert(array5);
    
    std::cout << "codes(NI,RD,CI) = (" << NI_RD_CI_code[0] << "," << NI_RD_CI_code[1] << "," << NI_RD_CI_code[2] << ")\n";

    return 0;
}
