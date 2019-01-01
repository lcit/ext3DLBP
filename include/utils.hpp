/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: utils.hpp
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

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <array>
#include <numeric>
#include <algorithm>
#include <iostream>

template<typename T, int M, int N, int O>
using Array3D = std::array<std::array<std::array<T,O>,N>,M>;


template<typename T, int M, int N>
using Array2D = std::array<std::array<T,N>,M>;


template<typename T, int M>
using Array1D = std::array<T,M>;

template<typename T, size_t N>
auto compute_mean(const Array1D<T,N>& v) {
    T mean = std::accumulate(std::cbegin(v), std::cend(v), 0)/N;
    //T mean = std::accumulate(std::cbegin(v), std::cend(v), T())/N;
    return mean;
}

template<typename T, size_t N>
auto sampling_NI(const Array1D<T,N>& in, const T th) {
    Array1D<bool,N> out;
    std::transform(std::cbegin(in), std::cend(in), std::begin(out), [&th](const T x) {
        if(round(x) >= th)
            return true;
        else
            return false;
    });
    return out;
}

template<typename T, size_t N>
auto sampling_RD(const Array1D<T,N>& in1, const Array1D<T,N>& in2) {
    Array1D<bool,N> out;
    std::transform(std::cbegin(in1), std::cend(in1), std::cbegin(in2), std::begin(out), [](const T x1, const T x2) {
        if(round(x1-x2) >= 0)
            return true;
        else
            return false;
    });
    return out;
}

template<typename T, size_t N>
auto sampling_RD(const Array1D<T,N>& in1, const T in2) {
    return sampling_NI(in1,in2);
}

template<size_t N>
int sum_active_voxels(const Array1D<bool,N>& g) {
    return std::accumulate(std::cbegin(g), std::cend(g), 0, [&](const int init, const bool x){
                if(x)
                    return init + 1;
                else
                    return init;
            });
}

// for debugging
template<typename T, size_t N>
void print(const std::string& name, const Array1D<T,N>& v) {
    std::cout << name << ": [";
    for(const auto& e:v)
        std::cout << e << ",";
    std::cout << "]\n";
}
template<typename T>
void print(const std::string& name, const T v) {
    std::cout << name << ": " << v << "\n";
}

#endif
