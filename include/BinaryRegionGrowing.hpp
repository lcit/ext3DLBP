/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: BinaryRegionGrowing.hpp
    Last modifed:   03.04.2017 by Leonardo Citraro
    Description:    Binary Region Growing

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
#ifndef __BINARY_REGION_GROWING_HPP__
#define __BINARY_REGION_GROWING_HPP__

#include <array>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

template<typename T, int M, int N, int O>
using Array3D = std::array<std::array<std::array<T,O>,N>,M>;
template<typename T, int M, int N>
using Array2D = std::array<std::array<T,N>,M>;
template<typename T, int M>
using Array1D = std::array<T,M>;

template<int M, int N>
class BinaryRegionGrowing{
private:
    const Array2D<int,M,N> _neighbour_indexes;
    unsigned _nb_regions;

public:
    BinaryRegionGrowing(const Array2D<int,M,N>& neighbour_indexes)
        : _neighbour_indexes(neighbour_indexes){}
    ~BinaryRegionGrowing(){}

    auto run(const Array1D<bool,M>& values){

        // the vector containing the region identifier for each element in the mesh.
        // this is also the return value for this funtion
        Array1D<int,M> regions;
        regions.fill(-1);

        // the current region number/identifier, it will increase by one at a time
        unsigned current_region_n = 0;

        for(size_t current_node=0; current_node<M; ++current_node){

            // run region growing only if the current node has not been assigned yet
            if(regions[current_node] == -1){

                std::vector<int> index_covered;

                // assign region to current node
                regions[current_node] = current_region_n;

                // mark nodes as covered so we do not assign a region twice to the same node
                index_covered.push_back(current_node);

                // start recursion from current node
                recursive_assignation(regions, values, current_node, current_region_n, index_covered);

                // init new region number
                current_region_n++;
            }
        }
        _nb_regions = current_region_n;
        return regions;
    }

    auto get_nb_regions() const {
        return _nb_regions;
    }

private:

    void recursive_assignation(Array1D<int,M>& regions, const Array1D<bool,M>& values, int current_node, unsigned current_region_n, std::vector<int>& index_covered){

        // walk throuh the neighbours of current_node
        for(size_t i=0;i<N;++i){

            int new_node = _neighbour_indexes[current_node][i];

            // if we reach the end of the interconnected node ( in other words if we hit a -1) we can terminate this function
            if(new_node < 0)
                return;

            // make sure the node has the same binary value than the other before it
            if(values[new_node] == values[current_node]){

                // check if the node has been covered yet, if not, assign it the current region number
                if(std::find(index_covered.begin(), index_covered.end(), new_node) == index_covered.end()){

                    // assign region to node
                    regions[new_node] = current_region_n;

                    // mark node as covered
                    index_covered.push_back(new_node);

                    // continue recursion from current node
                    recursive_assignation(regions, values, new_node, current_region_n, index_covered);
                }
            }
        }
    }
};

#endif
