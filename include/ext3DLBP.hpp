/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: ext3DLBP.hpp
    Last modifed:   09.04.2017 by Leonardo Citraro
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

#ifndef __EXT3DLBP_HPP__
#define __EXT3DLBP_HPP__

#include "types.hpp"
#include "utils.hpp"
#include "mesh.hpp"
#include "interpolation.hpp"
#include "BinaryRegionGrowing.hpp"

namespace ext3DLBP {

    class CI_LBP {
    public:
        //const double mur;
        const int mur;
        const static int bins = 2;
        CI_LBP(const double mur) : mur(mur) {}
        CI_LBP() : mur(128.0) {}
        CI_LBP(const CI_LBP& other) : mur(other.mur) {}
        CI_LBP(CI_LBP&& other) : mur(other.mur) {}
        virtual int convert(const int value) {
            if(value >= mur)
                return 1;
            else
                return 0;
        }
        virtual int convert(const Array3D<int,3,3,3>& array) {
            if(array[1][1][1] >= mur)
                return 1;
            else
                return 0;
        }
        virtual int convert(const Array3D<int,5,5,5>& array) {
            if(array[2][2][2] >= mur)
                return 1;
            else
                return 0;
        }
        virtual int convert(const Array3D<int,7,7,7>& array) {
            if(array[3][3][3] >= mur)
                return 1;
            else
                return 0;
        }
    };
    
    template<typename Vertexes, typename Radius>
    class NI_LBP {
    public:
        const static int P = Vertexes::P;
        const static int O = Vertexes::O;
        const static int bins = Vertexes::bins;
        const static int R = Radius::R;
        const static int K = R*2+1;
        //const double mur;
        const int mur;
        const int V;
        NI_LBP(const double mur, const int V) : mur(mur), V(V) {}
        NI_LBP() : mur(128.0), V(3) {}
        NI_LBP(const NI_LBP<Vertexes,Radius>& other) : mur(other.mur), V(other.V) {}
        NI_LBP(NI_LBP<Vertexes,Radius>&& other) : mur(other.mur), V(other.V) {}
        virtual int convert(const Array3D<int,K,K,K>& array) {
        
            auto voxels_extern = Interpolation<Vertexes,Radius>::_extern(array);
            double mu = compute_mean(voxels_extern);
            
            Array1D<bool,P> g_NI = sampling_NI(voxels_extern, mu);
            
            BinaryRegionGrowing<P,O> bgr(mesh<Vertexes>::data);
            bgr.run(g_NI);
            int nb_regions_NI = bgr.get_nb_regions();
            
            if(nb_regions_NI <= V)
                return sum_active_voxels(g_NI);
            else
                return P+1;
        }
    };
    
    template<typename Vertexes, typename Radius>
    class RD_LBP {
    public:
        const static int P = Vertexes::P;
        const static int O = Vertexes::O;
        const static int bins = Vertexes::bins;
        const static int R = Radius::R;
        const static int K = R*2+1;
        //const double mur;
        const int mur;
        const int V;
        RD_LBP(const double mur, const int V) : mur(mur), V(V) {}
        RD_LBP() : mur(128.0), V(3) {}
        RD_LBP(const RD_LBP<Vertexes,Radius>& other) : mur(other.mur), V(other.V) {}
        RD_LBP(RD_LBP<Vertexes,Radius>&& other) : mur(other.mur), V(other.V) {}
        virtual int convert(const Array3D<int,K,K,K>& array) {
            
            auto voxels_extern = Interpolation<Vertexes,Radius>::_extern(array);
            auto voxels_intern = Interpolation<Vertexes,Radius>::_intern(array);
            
            Array1D<bool,P> g_RD = sampling_RD(voxels_extern, voxels_intern);
            
            BinaryRegionGrowing<P,O> bgr(mesh<Vertexes>::data);
            bgr.run(g_RD);
            int nb_regions_RD = bgr.get_nb_regions();
            
            if(nb_regions_RD <= V)
                return sum_active_voxels(g_RD);
            else
                return P+1;
        }
    };
    
    template<typename Vertexes, typename Radius>
    class NI_RD_LBP {
    public:
        const static int P = Vertexes::P;
        const static int O = Vertexes::O;
        const static int bins = Vertexes::bins;
        const static int R = Radius::R;
        const static int K = R*2+1;
        //const double mur;
        const int mur;
        const int V;
        NI_RD_LBP(const double mur, const int V) : mur(mur), V(V) {}
        NI_RD_LBP() : mur(128.0), V(3) {}
        NI_RD_LBP(const NI_RD_LBP<Vertexes,Radius>& other) : mur(other.mur), V(other.V) {}
        NI_RD_LBP(NI_RD_LBP<Vertexes,Radius>&& other) : mur(other.mur), V(other.V) {}
        virtual Array1D<int,2> convert(const Array3D<int,K,K,K>& array) {
            
            auto voxels_extern = Interpolation<Vertexes,Radius>::_extern(array);
            auto voxels_intern = Interpolation<Vertexes,Radius>::_intern(array);
            
            double mu = compute_mean(voxels_extern);
            
            Array1D<bool,P> g_NI = sampling_NI(voxels_extern, mu);
            Array1D<bool,P> g_RD = sampling_RD(voxels_extern, voxels_intern);
            
            BinaryRegionGrowing<P,O> bgr(mesh<Vertexes>::data);
                
            bgr.run(g_NI);
            int nb_regions_NI = bgr.get_nb_regions();
            
            bgr.run(g_RD);
            int nb_regions_RD = bgr.get_nb_regions();
            
            Array1D<int,2> LBPcode;
            
            if(nb_regions_NI <= V)
                LBPcode[0] = sum_active_voxels(g_NI);
            else
                LBPcode[0] = P+1;
            
            if(nb_regions_RD <= V)
                LBPcode[1] = sum_active_voxels(g_RD);
            else
                LBPcode[1] = P+1;

            return LBPcode;
        }
    };
    
    template<typename Vertexes, typename Radius>
    class NI_RD_CI_LBP {
    public:
        const static int P = Vertexes::P;
        const static int O = Vertexes::O;
        const static int bins = Vertexes::bins;
        const static int R = Radius::R;
        const static int K = R*2+1;
        //const double mur;
        const int mur;
        const int V;
        NI_RD_CI_LBP(const double mur, const int V) : mur(mur), V(V) {}
        NI_RD_CI_LBP() : mur(128.0), V(3) {}
        NI_RD_CI_LBP(const NI_RD_CI_LBP<Vertexes,Radius>& other) : mur(other.mur), V(other.V) {}
        NI_RD_CI_LBP(NI_RD_CI_LBP<Vertexes,Radius>&& other) : mur(other.mur), V(other.V) {}
        virtual Array1D<int,3> convert(const Array3D<int,K,K,K>& array) {
            
            auto voxels_extern = Interpolation<Vertexes,Radius>::_extern(array);
            auto voxels_intern = Interpolation<Vertexes,Radius>::_intern(array);
            
            double mu = compute_mean(voxels_extern);
            
            auto g_NI = sampling_NI(voxels_extern, mu);
            auto g_RD = sampling_RD(voxels_extern, voxels_intern);
            
            BinaryRegionGrowing<P,O> bgr(mesh<Vertexes>::data);
                
            bgr.run(g_NI);
            int nb_regions_NI = bgr.get_nb_regions();
            
            bgr.run(g_RD);
            int nb_regions_RD = bgr.get_nb_regions();
            
            Array1D<int,3> LBPcode;
            
            if(nb_regions_NI <= V)
                LBPcode[0] = sum_active_voxels(g_NI);
            else
                LBPcode[0] = P+1;
            
            if(nb_regions_RD <= V)
                LBPcode[1] = sum_active_voxels(g_RD);
            else
                LBPcode[1] = P+1;

            if(array[R][R][R] >= mur)
                LBPcode[2] = 1;
            else
                LBPcode[2] = 0;

            return LBPcode;
        }
    };

};
#endif
