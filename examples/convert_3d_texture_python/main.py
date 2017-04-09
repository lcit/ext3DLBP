'''
==========================================================================================
Author: Leonardo Citraro
Company:
Filename: test.py
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
'''
import sys
import os
sys.path.insert(0,'../../python_wrapper')
import numpy as np
from PIL import Image
import time
import matplotlib.pyplot as plt
import ext3DLBPpy

def from_images_to_3D_array(directory, size):
    img_3d = np.empty(size, dtype=np.int)
    for dirName, subdirList, fileList in os.walk(directory):
        if len(subdirList) > 1:
            raise AssertionError('There are multiple directories in this path!!') 
        for filename in fileList:
            if ".bmp" in filename.lower():
                index_2d_image = int(filename.split('\\')[-1].split('.')[0])
                img_array = np.array(Image.open(os.path.join(dirName,filename)).convert(mode='L'))
                img_3d[:,:,index_2d_image] = img_array
    return img_3d
    
def construct_histograms(img_3d_NI, img_3d_RD, img_3d_CI, bins):
    (hist1, edges) = np.histogram(img_3d_NI, bins=np.arange(0,bins+1), density=False)       
    (hist2, edges) = np.histogram(img_3d_RD, bins=np.arange(0,bins+1), density=False)
    (hist3, edges) = np.histogram(img_3d_CI, bins=np.arange(0,2+1), density=False)    
    joint_2d = np.outer(hist1,hist2)
    joint_3d = np.repeat(joint_2d[:, :, np.newaxis], len(hist3), axis=2)*hist3
    concat = np.concatenate([hist1,hist2,hist3])
    return joint_3d, concat, hist1, hist2, hist3

if __name__ == "__main__":

    start = time.time()
       
    size = (64,64,64)
    img3D = from_images_to_3D_array('../img/Blobs01/', size)
    
    mur = np.mean(img3D)
    V = 3
    lbp = ext3DLBPpy.NI_RD_CI_LBP_P42g_R2(mur, V)
    
    
    # this produces the same results as lbp.convert_3d_image(img3D) here below
    '''
    img_3d_NI = np.zeros((size[0]-2*lbp.R, size[1]-2*lbp.R, size[2]-2*lbp.R), dtype=np.int)
    img_3d_RD = np.zeros((size[0]-2*lbp.R, size[1]-2*lbp.R, size[2]-2*lbp.R), dtype=np.int)
    img_3d_CI = np.zeros((size[0]-2*lbp.R, size[1]-2*lbp.R, size[2]-2*lbp.R), dtype=np.int)
    for dep in xrange(size[2]-lbp.K+1):
        for row in xrange(size[1]-lbp.K+1):
            for col in xrange(size[0]-lbp.K+1): 
                (NI,RD,CI) = lbp.convert(img3D[row:row+lbp.K, col:col+lbp.K, dep:dep+lbp.K])                
                img_3d_NI[row, col, dep] = NI
                img_3d_RD[row, col, dep] = RD
                img_3d_CI[row, col, dep] = CI
    '''
    
    # calculate the LBP for each pixel in the image
    (img_3d_NI,img_3d_RD,img_3d_CI) = lbp.convert_3d_image(img3D)
    
    joint, concat, hist_NI, hist_RD, hist_CI = construct_histograms(img_3d_NI, img_3d_RD, img_3d_CI, lbp.bins)
    
    print "Elapsed time: {} [s]".format(time.time()-start)
    
    plt.subplot(231)
    plt.plot(hist_NI)
    plt.title("hist_NI")
    plt.subplot(232)
    plt.plot(hist_RD)
    plt.title("hist_RD")
    plt.subplot(233)
    plt.plot(hist_CI)
    plt.title("hist_CI")
    plt.subplot(234)
    plt.plot(joint.ravel())
    plt.title("Joint NI/RD/CI")
    plt.subplot(235)
    plt.plot(concat)
    plt.title("Concat NI+RD+CI")
    plt.show()



















