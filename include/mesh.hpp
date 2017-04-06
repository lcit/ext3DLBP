/*  ==========================================================================================
    Author: Leonardo Citraro
    Company:
    Filename: mesh.hpp
    Last modifed:   03.04.2017 by Leonardo Citraro
    Description:    Ensamble of mesh matrices for the geodesic spheres of
                    42, 92 and 252 vertexes. These 2D arrays define the interconnection between
                    neigbourhoods voxels on the surface of spherical frame. A mesh
                    is used by the region growing algorithm.
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
#ifndef __MESH_HPP__
#define __MESH_HPP__

#include "types.hpp"
#include "utils.hpp"

template<typename P>
struct mesh {};

template<>
struct mesh<P42g> {
    static const Array2D<int,42,6> data;
};

template<>
struct mesh<P92g> {
    static const Array2D<int,92,6> data;
};

template<>
struct mesh<P252g> {
    static const Array2D<int,252,6> data;
};

//=======================================================
const Array2D<int,42,6> mesh<P42g>::data = {{
        { 1,  2,  3,  4,  5,  6},
        { 0,  3,  4,  9, 10, -1},
        { 0,  5,  6, 12, 11, -1},
        { 1,  7,  9, 13,  0,  5},
        { 1,  8, 14, 10,  0,  6},
        { 2,  7, 15, 11,  0,  3},
        { 2,  8, 16, 12,  0,  4},
        {20, 15, 13,  3,  5, -1},
        {21, 14, 16,  4,  6, -1},
        {18,  1,  3, 13, 17, 10},
        {19,  1,  4, 14, 17,  9},
        {22,  2,  5, 15, 24, 12},
        {23,  2, 16,  6, 24, 11},
        { 7, 18,  3,  9, 20, 25},
        { 8, 19,  4, 10, 21, 26},
        { 7, 22,  5, 11, 20, 27},
        { 8, 23,  6, 12, 21, 28},
        {19, 18, 10, 29, 30,  9},
        {17,  9, 29, 25, 13, -1},
        {17, 10, 30, 26, 14, -1},
        { 7, 33, 25, 27, 15, 13},
        { 8, 34, 26, 16, 28, 14},
        {24, 31, 11, 15, 27, -1},
        {24, 32, 12, 28, 16, -1},
        {22, 23, 31, 12, 11, 32},
        {33, 18, 35, 29, 20, 13},
        {34, 19, 30, 36, 21, 14},
        {33, 22, 37, 31, 20, 15},
        {34, 23, 38, 32, 21, 16},
        {18, 39, 35, 25, 17, 30},
        {19, 39, 26, 36, 17, 29},
        {22, 40, 37, 27, 24, 32},
        {23, 40, 28, 38, 24, 31},
        {20, 27, 25, 37, 35, -1},
        {21, 28, 26, 38, 36, -1},
        {39, 33, 29, 25, 41, 37},
        {39, 34, 26, 30, 41, 38},
        {40, 33, 31, 27, 41, 35},
        {40, 34, 28, 32, 41, 36},
        {41, 35, 36, 29, 30, -1},
        {41, 38, 37, 32, 31, -1},
        {39, 40, 38, 37, 36, 35}
    }};
//=======================================================
const Array2D<int,92,6> mesh<P92g>::data = {{
        {17, 76, 14, 63, 72, -1},
        {32, 73, 27, 68, 71, -1},
        {80, 89, 49, 84, 42, -1},
        {36, 39, 45, 51, 43, -1},
        {13, 29, 19, 30, 25, -1},
        {46, 85, 21, 87, 24, -1},
        {64, 69, 55, 66, 59, -1},
        {48, 53, 54, 62, 61, -1},
        {22, 28, 40, 34, 35, -1},
        {88, 20, 82, 16, 83, -1},
        {56, 52, 37, 74, 33, -1},
        {60, 67, 90, 77, 81, -1},
        {71, 72, 27, 14, 29, 13},
        { 4, 14, 15, 12, 19, 29},
        { 0, 13, 15, 12, 17, 72},
        {19, 16, 14, 20, 17, 13},
        { 9, 17, 15, 78, 20, 83},
        { 0, 16, 15, 78, 14, 76},
        {25, 24, 87, 19, 88, 20},
        { 4, 20, 15, 18, 13, 25},
        { 9, 19, 15, 18, 16, 88},
        { 5, 22, 41, 23, 46, 24},
        { 8, 21, 41, 23, 40, 28},
        {24, 25, 30, 21, 28, 22},
        {25,  5, 18, 23, 87, 21},
        {24,  4, 18, 23, 19, 30},
        {30, 27, 34, 32, 29, 28},
        { 1, 29, 26, 12, 32, 71},
        { 8, 30, 26, 23, 34, 22},
        { 4, 27, 26, 12, 30, 13},
        { 4, 28, 26, 23, 29, 25},
        {35, 33, 34, 74, 32, 73},
        { 1, 34, 26, 31, 27, 73},
        {35, 10, 31, 38, 74, 37},
        { 8, 32, 26, 31, 28, 35},
        {33,  8, 31, 38, 34, 40},
        { 3, 37, 50, 38, 51, 39},
        {10, 36, 50, 38, 52, 33},
        {33, 35, 37, 40, 36, 39},
        { 3, 40, 41, 38, 45, 36},
        { 8, 39, 41, 38, 22, 35},
        {45, 40, 21, 39, 46, 22},
        {43,  2, 44, 47, 84, 49},
        {42,  3, 44, 47, 45, 51},
        {42, 43, 84, 45, 85, 46},
        { 3, 46, 41, 44, 39, 43},
        { 5, 45, 41, 44, 21, 85},
        {43, 42, 51, 49, 53, 48},
        { 7, 49, 91, 47, 62, 53},
        { 2, 48, 91, 47, 89, 42},
        {37, 51, 54, 52, 36, 53},
        { 3, 53, 50, 47, 36, 43},
        {10, 54, 50, 57, 37, 56},
        { 7, 51, 50, 47, 54, 48},
        { 7, 52, 50, 57, 53, 61},
        { 6, 56, 75, 57, 69, 59},
        {10, 55, 75, 57, 74, 52},
        {59, 61, 54, 55, 52, 56},
        {59, 61, 62, 66, 60, 67},
        {61,  6, 57, 58, 55, 66},
        {11, 62, 91, 58, 90, 67},
        {59,  7, 57, 58, 54, 62},
        { 7, 60, 91, 58, 48, 61},
        { 0, 64, 65, 70, 76, 72},
        { 6, 63, 65, 70, 66, 69},
        {66, 77, 63, 67, 64, 76},
        { 6, 67, 65, 58, 64, 59},
        {11, 66, 65, 58, 77, 60},
        { 1, 69, 75, 70, 73, 71},
        { 6, 68, 75, 70, 55, 64},
        {72, 71, 63, 68, 64, 69},
        {72,  1, 70, 12, 68, 27},
        {71,  0, 70, 12, 63, 14},
        { 1, 74, 75, 31, 68, 32},
        {10, 73, 75, 31, 56, 33},
        {55, 68, 74, 73, 56, 69},
        { 0, 77, 65, 78, 63, 17},
        {11, 76, 65, 78, 67, 81},
        {81, 83, 77, 16, 76, 17},
        {83, 81, 82, 90, 80, 89},
        { 2, 82, 86, 79, 84, 89},
        {83, 11, 79, 78, 90, 77},
        { 9, 80, 86, 79, 88, 83},
        {81,  9, 79, 78, 82, 16},
        { 2, 85, 86, 44, 80, 42},
        { 5, 84, 86, 44, 87, 46},
        {87, 84, 82, 88, 85, 80},
        { 5, 88, 86, 18, 85, 24},
        { 9, 87, 86, 18, 82, 20},
        { 2, 90, 91, 79, 49, 80},
        {11, 89, 91, 79, 60, 81},
        {90, 49, 62, 89, 48, 60}
}};
//=======================================================
const Array2D<int,252,6> mesh<P252g>::data = {{
        {193, 204,  31, 166,  21,  -1},
        {185,  83, 194, 180,  69,  -1},
        {104, 242, 227, 228, 127,  -1},
        {112,  84,  94, 141, 117,  -1},
        { 55,  66,  15,  68,  41,  -1},
        { 47, 236, 114,  42, 241,  -1},
        {165, 174, 189, 179, 142,  -1},
        {162, 121, 138, 140, 164,  -1},
        { 82,  51,  60,  80, 100,  -1},
        {226,  39, 238,  25, 224,  -1},
        { 74, 148, 132, 200,  90,  -1},
        {218, 156, 176, 248, 210,  -1},
        { 16,  17,  13,  18,  14,  19},
        { 18,  15,  24,  12,  30,  17},
        { 20,  16, 182, 188,  19,  12},
        {  4,  13,  30,  17,  66,  41},
        { 21, 193,  12,  14, 188,  18},
        { 66,  15,  19,  12,  62,  13},
        { 13,  21,  24,  12,  16,  26},
        { 20,  17,  62,  58,  14,  12},
        { 69, 185,  19,  14, 182,  58},
        { 18,   0,  16,  26, 193,  31},
        { 26,  27,  23,  28,  24,  29},
        { 28,  25,  22, 205, 208,  27},
        { 30,  26,  18,  13,  22,  29},
        { 23,   9, 208,  27, 226,  39},
        { 31,  21,  22,  24,  28,  18},
        { 39,  25,  29,  22,  36,  23},
        { 23,  31,  22, 205,  26, 209},
        { 27,  30,  33,  36,  24,  22},
        { 15,  41,  24,  29,  13,  33},
        {  0,  28,  26, 209, 204,  21},
        { 37,  35, 234, 230,  38,  34},
        { 36,  41,  29,  34,  40,  30},
        { 40,  35,  36,  33,  38,  32},
        {238,  39,  32,  34, 234,  36},
        { 33,  39,  29,  34,  27,  35},
        {241,  47,  32,  38,  44, 230},
        { 37,  40,  44,  50,  32,  34},
        {  9,  36,  27,  35, 238,  25},
        { 41,  55,  34,  38,  50,  33},
        { 33,   4,  40,  30,  55,  15},
        { 53,   5,  49,  98,  47, 114},
        { 48,  49,  50,  44,  46,  52},
        { 50,  47,  38,  43,  37,  49},
        { 53,  51,  97,  52, 103,  54},
        { 48,  54,  57,  64,  43,  52},
        {  5,  44,  37,  49, 241,  42},
        { 68,  55,  46,  43,  50,  64},
        { 42,  47,  52,  43,  44,  53},
        { 44,  55,  38,  43,  40,  48},
        {  8,  45, 103,  54,  60, 100},
        { 49,  54,  45,  53,  43,  46},
        { 45,  42,  97,  52,  49,  98},
        { 51,  60,  46,  52,  57,  45},
        {  4,  50,  40,  48,  41,  68},
        { 63,  61,  64,  57,  59,  65},
        { 64,  60,  56,  46,  63,  54},
        { 62,  69,  59,  19,  20,  67},
        { 61,  67,  58,  62,  56,  65},
        {  8,  57,  63,  54,  51,  80},
        { 66,  68,  59,  56,  62,  64},
        { 58,  66,  59,  19,  61,  17},
        { 60,  80,  56,  65,  57,  76},
        { 57,  68,  56,  46,  48,  61},
        { 67,  63,  76,  72,  59,  56},
        {  4,  62,  61,  17,  15,  68},
        { 83,  69,  65,  59,  72,  58},
        { 64,   4,  48,  61,  55,  66},
        { 58,   1,  20,  67, 185,  83},
        { 75,  77,  78,  71,  73,  79},
        { 78,  74,  70,  87,  77,  93},
        { 76,  83,  65,  73,  67,  81},
        { 75,  81,  72,  76,  70,  79},
        { 10,  71,  77,  93, 200,  90},
        { 80,  82,  73,  70,  78,  76},
        { 72,  80,  65,  73,  75,  63},
        {200,  74,  79,  70,  71, 196},
        { 71,  82,  70,  87,  75,  88},
        { 77,  81, 202, 196,  70,  73},
        { 76,   8,  75,  63,  82,  60},
        { 83, 194,  73,  79,  72, 202},
        {  8,  78,  75,  88,  80, 100},
        {  1,  72,  67,  81, 194,  69},
        {  3,  92, 139,  89,  94, 141},
        { 88,  89, 102,  96,  87,  91},
        { 92,  90, 137,  91,  93, 135},
        { 93,  88,  71,  78,  91,  85},
        {100,  82,  85,  87,  78,  96},
        { 84,  94,  91,  85,  92, 102},
        { 86,  10,  93, 135,  74, 132},
        { 93,  89,  92,  86,  87,  85},
        { 86,  84, 137,  91, 139,  89},
        { 90,  74,  91,  87,  71,  86},
        {  3, 102,  99,  89,  84, 117},
        { 98,  99, 106, 110,  97, 101},
        {102, 100, 101,  85,  88, 103},
        {103,  98,  53,  45,  95, 101},
        {114,  42,  95,  97, 110,  53},
        { 94, 117, 101,  95, 102, 106},
        { 96,   8,  88, 103,  82,  51},
        { 99, 103,  96, 102,  95,  97},
        { 96,  94, 101,  85,  99,  89},
        { 51, 100,  97, 101,  45,  96},
        {  2, 115, 111, 122, 228, 127},
        {111, 109, 231, 239, 113, 108},
        {110, 117,  95, 108, 116,  99},
        {115, 112, 113, 120, 116, 126},
        {116, 109, 110, 106, 113, 105},
        {236, 114, 105, 108, 231, 110},
        {106, 114,  95, 108,  98, 109},
        {228, 104, 105, 113, 115, 239},
        {  3, 107, 116, 126, 117, 141},
        {111, 116, 115, 107, 105, 108},
        {  5, 110,  98, 109, 236,  42},
        {107, 104, 113, 120, 111, 122},
        {117, 112, 108, 113, 107, 106},
        {106,   3, 116,  99, 112,  94},
        {122, 123, 119, 124, 120, 125},
        {124, 121, 243, 118, 246, 123},
        {126, 122, 107, 115, 125, 118},
        {  7, 119, 246, 123, 138, 164},
        {127, 104, 118, 120, 115, 124},
        {138, 121, 125, 118, 134, 119},
        {119, 127, 243, 118, 122, 247},
        {126, 123, 134, 130, 120, 118},
        {141, 112, 125, 120, 107, 130},
        {124,   2, 122, 247, 104, 242},
        {135, 133, 136, 129, 131, 137},
        {136, 132, 128, 145, 135, 151},
        {134, 141, 131, 125, 126, 139},
        {133, 139, 130, 134, 128, 137},
        { 10, 129, 135, 151, 148,  90},
        {138, 140, 131, 128, 134, 136},
        {130, 138, 131, 125, 133, 123},
        {132,  90, 128, 137, 129,  86},
        {129, 140, 128, 145, 146, 133},
        {139, 135,  86,  92, 131, 128},
        {  7, 134, 133, 123, 121, 140},
        { 84, 141, 137, 131,  92, 130},
        {136,   7, 146, 133, 162, 138},
        {130,   3, 126, 139, 112,  84},
        {150,   6, 147, 198, 165, 189},
        {146, 147, 158, 154, 145, 149},
        {150, 148, 197, 149, 203, 151},
        {146, 151, 129, 136, 143, 149},
        {140, 162, 145, 143, 158, 136},
        {142, 165, 149, 143, 154, 150},
        { 10, 144, 203, 151, 132, 200},
        {147, 151, 144, 150, 143, 145},
        {144, 142, 197, 149, 147, 198},
        {132, 148, 145, 149, 144, 129},
        {157, 159, 153, 160, 155, 161},
        {160, 156, 245, 152, 251, 159},
        {158, 165, 143, 155, 147, 163},
        {163, 157, 158, 154, 161, 152},
        { 11, 153, 251, 159, 176, 248},
        {164, 162, 152, 155, 158, 160},
        {154, 162, 143, 155, 146, 157},
        {176, 156, 161, 152, 172, 153},
        {153, 164, 245, 152, 157, 246},
        {163, 159, 172, 168, 155, 152},
        {  7, 158, 146, 157, 140, 164},
        {179, 165, 161, 155, 154, 168},
        {160,   7, 157, 246, 162, 121},
        {  6, 154, 147, 163, 142, 179},
        {177,   0, 186, 173, 193, 204},
        {173, 171, 206, 212, 175, 170},
        {172, 179, 170, 161, 163, 178},
        {177, 174, 175, 184, 178, 192},
        {171, 178, 168, 172, 175, 167},
        {176, 210, 170, 167, 172, 206},
        {168, 176, 170, 161, 171, 159},
        {204, 166, 167, 175, 212, 177},
        {  6, 169, 178, 192, 189, 179},
        {178, 173, 177, 169, 167, 170},
        { 11, 172, 171, 159, 156, 210},
        {169, 166, 175, 184, 186, 173},
        {174, 179, 175, 170, 169, 168},
        {168,   6, 163, 178, 165, 174},
        {191,   1, 187, 199, 185, 194},
        {186, 187, 188, 182, 184, 190},
        {188, 185, 181,  14, 187,  20},
        {191, 189, 195, 190, 198, 192},
        {186, 192, 169, 177, 181, 190},
        {  1, 182, 187,  20, 180,  69},
        {166, 193, 184, 181, 188, 177},
        {180, 185, 190, 181, 182, 191},
        {182, 193, 181,  14, 186,  16},
        {  6, 183, 198, 192, 174, 142},
        {187, 192, 183, 191, 181, 184},
        {183, 180, 195, 190, 187, 199},
        {174, 189, 184, 190, 169, 183},
        {  0, 188, 186,  16, 166,  21},
        {  1, 202, 199,  81,  83, 180},
        {198, 199, 191, 183, 201, 197},
        {202, 200, 201,  79,  77, 203},
        {203, 198, 150, 144, 195, 201},
        {189, 142, 195, 197, 183, 150},
        {194, 180, 201, 195, 202, 191},
        {196,  10,  77, 203,  74, 148},
        {199, 203, 196, 202, 195, 197},
        {196, 194, 201,  79, 199,  81},
        {148, 200, 197, 201, 144, 196},
        {  0, 212, 173, 209,  31, 166},
        {208, 209,  28,  23, 207, 211},
        {212, 210, 167, 211, 213, 171},
        {213, 208, 215, 222, 211, 205},
        { 25, 226, 205, 207, 222,  23},
        {204,  31, 211, 205, 212,  28},
        {206,  11, 213, 171, 218, 176},
        {213, 209, 212, 206, 207, 205},
        {206, 204, 167, 211, 173, 209},
        {210, 218, 211, 207, 215, 206},
        {219, 221, 222, 215, 217, 223},
        {222, 218, 214, 207, 221, 213},
        {220, 227, 229, 217, 235, 225},
        {219, 225, 216, 220, 214, 223},
        { 11, 215, 221, 213, 248, 210},
        {224, 226, 217, 214, 222, 220},
        {216, 224, 229, 217, 219, 233},
        {248, 218, 223, 214, 215, 244},
        {215, 226, 214, 207, 219, 208},
        {221, 225, 250, 244, 214, 217},
        {220,   9, 219, 233, 226, 238},
        {227, 242, 217, 223, 216, 250},
        {  9, 222, 219, 208, 224,  25},
        {  2, 216, 235, 225, 242, 228},
        {239,   2, 111, 235, 104, 227},
        {235, 233, 220, 216, 237, 232},
        {234, 241, 232,  32,  37, 240},
        {239, 236, 237, 105, 240, 109},
        {233, 240, 230, 234, 237, 229},
        {238, 224, 232, 229, 234, 220},
        {230, 238, 232,  32, 233,  35},
        {227, 228, 229, 237, 216, 239},
        {  5, 231, 240, 109, 114, 241},
        {240, 235, 239, 231, 232, 229},
        {  9, 234, 233,  35,  39, 224},
        {231, 228, 237, 105, 111, 235},
        {236, 241, 237, 232, 231, 230},
        {230,   5,  37, 240,  47, 236},
        {  2, 250, 247, 225, 227, 127},
        {246, 247, 124, 119, 249, 245},
        {250, 248, 249, 223, 221, 251},
        {251, 246, 160, 153, 243, 249},
        {121, 164, 243, 245, 119, 160},
        {242, 127, 249, 243, 250, 124},
        {244,  11, 221, 251, 218, 156},
        {247, 251, 244, 250, 243, 245},
        {244, 242, 249, 223, 247, 225},
        {156, 248, 245, 249, 153, 244}
}};

#endif
