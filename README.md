# ext3DLBP

C++ - Extended three-dimensional rotation invariant local binary patterns (LBP).

Header-only implementation of the Extended 3D LBP with python wrappers.

```
L. Citraro, S. Mahmoodi, A. Darekar, B. Vollmer,
Extended three-dimensional rotation invariant local binary patterns, 
Image and Vision Computing (2017)
```

### Prerequisites

- python 3
- CMake (tested with version 3.12.2)
- Boost.Python (to compile the python wrapper, tested with version 1.66)
- OpenCV (to compile the example convert_3d_texture_cpp)

### Unit tests (C++)
```
cd test_functional
./build.sh
./run.sh
```
### Build Python wrapper
Go to section `Installing Boost.Python`
Go to section `Installing OpenCV + Contrib + FFmpeg`
```
cd python_wrapper
./build.sh
```
To import the package set the following environmental variable:
```
export PYTHONPATH="..package location../ext3DLBP/python_wrapper/build:$PYTHONPATH"
```
To run the unit tests:
```
./test_functional/run.sh
```
### Example usage

###### A C++ example
```C++
#include "ext3DLBP.hpp"
#include <iostream>
#include <array>

int main(int argc, char* argv[]){
    
    Array3D<int,3,3,3> array = {{
            {{{0,0,0},{0,0,0},{0,0,0}}},
            {{{0,0,0},{0,0,0},{0,0,0}}},
            {{{0,0,0},{0,0,0},{0,0,0}}}
        }};
    
    double mur = 128.0;
    int V = 3;
    ext3DLBP::NI_RD_CI_LBP<P42g, R1> NI_RD_CI_lbp(mur, V);
    
    Array1D<int,3> NI_RD_CI_code = NI_RD_CI_lbp.convert(array);
    
    std::cout << "codes(NI,RD,CI) = (" << NI_RD_CI_code[0] << "," << NI_RD_CI_code[1] << "," << NI_RD_CI_code[2] << ")\n";

    return 0;
}
```
###### A Python example
```Python
import numpy as np
import ext3DLBPpy

array = np.zeros((3,3,3), dtype=np.int32)

mur = 128.0
V = 3
lbp = ext3DLBPpy.NI_RD_CI_LBP_P42g_R1(mur, V)

LBPcodes = lbp.convert(array)

print LBPcodes
```

## Reference

```
@article{Citraro2017,
	title = "Extended Three-Dimensional Rotation Invariant Local Binary Patterns ",
	journal = "Image and Vision Computing ",
	volume = "",
	number = "",
	pages = " - ",
	year = "2017",
	doi = "http://dx.doi.org/10.1016/j.imavis.2017.03.004",
	url = "http://www.sciencedirect.com/science/article/pii/S0262885617300665",
}
```

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

### Installing Boost.Python
We suggest installing Boost.Python from source as we need to include some header files in our library:
```
cd $HOME
wget https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.tar.bz2
tar --bzip2 -xf boost_1_66_0.tar.bz2
cd boost_1_66_0
./bootstrap.sh --with-python=python3
sudo ./b2 install
sudo ldconfig
cd $HOME
```

##### Possible issues:
1. If you have a message similar to this one: `failed updating 66 targets...fatal error: pyconfig.h: No such file or directory` then you may want to try this:
``` 
./bootstrap.sh --with-python=python3 --with-python-version=3.5m
sudo ./b2 install
sudo ldconfig
```

another option would be to modify line 542 of file tools/build/src/tools/python.jam from this:
`includes ?= $(prefix)/include/python$(version) ;`
to this:
`includes ?= $(prefix)/include/python$(version)m ;`
            
```
./bootstrap.sh --with-python=python3
sudo ./b2 install
sudo ldconfig
```

2. Another version of Boost is clashing with the new one. If it is the case for you we suggest removing the old version and re-install the new one. HINT: after compiling the core module, type `ldd core.so` to see which boost.python was used.

### Installing OpenCV + Contrib + FFmpeg
We first need to install some packages:
```
sudo apt-get install build-essential
sudo apt-get install git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libavresample-dev libx264-dev
sudo apt-get install libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
```
then:
```
cd ${HOME}
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git 
cd opencv_contrib
cd ../opencv
mkdir build
cd build

cmake -DWITH_FFMPEG=ON -DOPENCV_EXTRA_MODULES_PATH=${HOME}/opencv_contrib/modules -DWITH_CUDA=OFF -DBUILD_TIFF=ON -DBUILD_opencv_java=OFF -DENABLE_AVX=ON -DWITH_OPENGL=ON -DWITH_OPENCL=ON -DWITH_IPP=ON -DWITH_TBB=ON -DWITH_EIGEN=ON -DWITH_V4L=ON -DWITH_VTK=OFF -DBUILD_TESTS=OFF -DBUILD_PERF_TESTS=OFF -DCMAKE_BUILD_TYPE=RELEASE -DBUILD_opencv_python2=OFF -DCMAKE_INSTALL_PREFIX=$(python3 -c "import sys; print(sys.prefix)") -DPYTHON3_EXECUTABLE=$(which python3) -DPYTHON3_INCLUDE_DIR=$(python3 -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())") -DPYTHON3_PACKAGES_PATH=$(python3 -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())") -D INSTALL_PYTHON_EXAMPLES=ON -D INSTALL_C_EXAMPLES=OFF -D WITH_GTK_2_X=ON -D BUILD_EXAMPLES=ON ..
```
then we suggest double-checking the report to make sure FFmpeg is detected:
>-- General configuration for OpenCV 3.4.0-dev >=====================================
>--   Extra modules:
>--     Location (extra):   /home/.../opencv_contrib/modules
>--     Version control (extra):     3.4.0

>--   Video I/O:
>--     DC1394:                      NO
>--     FFMPEG:                      YES
>--       avcodec:                   YES (ver 56.60.100)
>--       avformat:                  YES (ver 56.40.101)
>--       avutil:                    YES (ver 54.31.100)
>--       swscale:                   YES (ver 3.1.101)
>--       avresample:                YES (ver 2.1.0)

then:
```
make -j8
sudo make install
```
to verify OpenCV is correctly installed; open a terminal and type `python` then type:
```
 import cv2
 print(cv2.__version__)
```
