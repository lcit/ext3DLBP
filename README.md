# ext3DLBP

C++ - Extended three-dimensional rotation invariant local binary patterns (LBP).

Header-only implementation of the Extended 3D LBP with python wrappers.

```
L. Citraro, S. Mahmoodi, A. Darekar, B. Vollmer,
Extended three-dimensional rotation invariant local binary patterns, 
Image and Vision Computing (2017)
```

### Prerequisites

- CMake to compile the examples
- Boost.Python to compile the wrappers

### Compilation
In almost every folder there is a `build.sh` and a `run.sh` scripts. The first compiles the sources, the latter runs the example codes if applicable.

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

array = np.zeros((3,3,3), dtype=np.int)

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

## Acknowledgments

