#!/bin/bash
g++ -std=c++14 -c -fPIC -Wp,-w -I. -I/usr/include/python2.7 -I../include ext3DLBPpy.cpp -o ext3DLBPpy.o
g++ -shared -Wl,-soname,ext3DLBPpy.so -o ext3DLBPpy.so  ext3DLBPpy.o -lpython2.7 -lboost_python
