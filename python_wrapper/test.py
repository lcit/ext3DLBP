'''
==========================================================================================
Author: Leonardo Citraro
Company:
Filename: test.py
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
'''
import sys
import os
sys.path.append(os.getcwd())
import numpy as np
import ext3DLBPpy

a = np.zeros((3,3,3), dtype=np.int)
lbp = ext3DLBPpy.NI_LBP_P42g_R1(128.0, 3)
print lbp.convert(a)

a = np.zeros((5,5,5), dtype=np.int)
lbp = ext3DLBPpy.NI_LBP_P42g_R2(128.0, 3)
print lbp.convert(a)

a = np.zeros((5,5,5), dtype=np.int)
lbp = ext3DLBPpy.CI_LBP(128.0)
print lbp.convert(a)

a = np.zeros((3,3,3), dtype=np.int)
lbp = ext3DLBPpy.NI_RD_LBP_P42g_R1(128.0, 3)
print lbp.convert(a)

a = np.zeros((3,3,3), dtype=np.int)
lbp = ext3DLBPpy.NI_RD_CI_LBP_P42g_R1(128.0, 3)
print lbp.convert(a)

a = np.zeros((7,7,7), dtype=np.int)
lbp = ext3DLBPpy.NI_RD_CI_LBP_P42g_R1(128.0, 3)
print lbp.convert(a)
