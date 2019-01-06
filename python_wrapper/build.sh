#!/bin/bash
rm -rdf ./build > /dev/null 2>&1
mkdir build 
cd build
cmake -D Boost_LIBRARY_DIR=/usr/local/lib -DBoost_INCLUDE_DIR=/usr/local/include ..
make -j 4
