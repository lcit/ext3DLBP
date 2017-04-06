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
#include <iomanip>
#include <chrono>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

template<size_t K>
Array2D<int,K,K> opencvMat_to_2Darray(const cv::Mat& mat) {
    Array2D<int,K,K> array;
    for(int i=0; i<mat.rows; ++i) {
        const uchar* ptr = mat.ptr<uchar>(i);
        for(int j=0; j<mat.cols; ++j) {
            array[i][j] = static_cast<int>(ptr[j]);
        }
    }
    return array;
}

template<typename Vector, size_t bins>
auto histogram(const Vector& v) {
    Array1D<long long int, bins+1> histogram{};
    for(int i=0; i<v.size(); ++i) {
        histogram[v[i]]++;
    }
    return histogram;
}

template<typename Vector>
void plot_histogram(const Vector& histogram) {
 
    // draw the histograms
    int hist_w = 512; 
    int hist_h = 400;
    int bin_w = cvRound((double)hist_w/(histogram.size()+1));
 
    cv::Mat histImage(hist_h, hist_w, CV_8UC1, cv::Scalar(255, 255, 255));
 
    // find the maximum intensity element from histogram
    long long int max = *std::max_element(std::begin(histogram), std::end(histogram));
    
    // normalize the histogram between 0 and histImage.rows
    Vector histogram_n;
    std::transform(std::begin(histogram), std::end(histogram),std::begin(histogram_n), [&](const int h){
        return (static_cast<double>(h)/max)*(hist_h/1.25);
    });
    
    // draw the intensity line for histogram
    for(int i=0; i<histogram_n.size(); i++){
        cv::line(histImage, cv::Point(bin_w*(i), hist_h), cv::Point(bin_w*(i), hist_h - histogram_n[i]), cv::Scalar(0,0,0), bin_w*0.75, 8, 0);
    }
    
    // display histogram
    cv::namedWindow("Intensity Histogram", CV_WINDOW_AUTOSIZE);
    cv::imshow("Intensity Histogram", histImage);
    cv::waitKey();
}

int main(int argc, char* argv[]){
    
    auto start = std::chrono::steady_clock::now();
    
    // load images into a "3D array"
    std::array<cv::Mat,64> img3D;
    for(int i=0; i<img3D.size(); ++i){
        std::stringstream filename;
        filename << "../img/Blobs01/" << std::setfill('0') << std::setw(4) << std::to_string(i) << ".bmp";
        std::cout << filename.str() << "\n";
        cv::Mat img = cv::imread(filename.str(), CV_8U);
        img3D[i] = img;
    }
    
    int cols = img3D[0].cols;
    int rows = img3D[0].rows;
    
    // setting up the LBP object
    double mur = 128.0;
    int V = 3;
    ext3DLBP::NI_LBP<P42g,R1> lbp(mur,V);
    
    // iterate over all the 3D image
    std::vector<int> LBPcodes;
    for(int z=lbp.R; z<img3D.size()-lbp.R; ++z) {
        for(int y=lbp.R; y<rows-lbp.R; ++y) {
            for(int x=lbp.R; x<cols-lbp.R; ++x) {
                
                // extraction of a small 3D chuck (3x3x3, 5x5x5 or 7x7x7)
                Array3D<int,lbp.K,lbp.K,lbp.K> array;
                for(int k=0; k<lbp.K; ++k) {
                    cv::Mat roi = img3D[z-lbp.R+k](cv::Range(y-lbp.R, y+lbp.R+1), cv::Range(x-lbp.R, x+lbp.R+1));
                    array[k] = opencvMat_to_2Darray<lbp.K>(roi);
                }
                
                // get the LBP codes
                int LBPcode = lbp.convert(array);
                
                LBPcodes.push_back(LBPcode);
            }
        }
    }
    
    // get time elapsed
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
    std::cout << "Time elapsed: " << duration.count() << " [ms]\n";
    
    // plot a (rough) histogram
    plot_histogram(histogram<std::vector<int>, lbp.P+1>(LBPcodes));
    
    return 0;
}
