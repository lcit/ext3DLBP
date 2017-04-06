#!/bin/bash
rm -rdf ./build > /dev/null 2>&1
mkdir build 
cd build
cmake ..
make -j 4
cp *.so ..
cp *.so ../test_functional/
cd ..
