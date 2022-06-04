# Custom python binding for OpenCV
## Requirements
* Ubuntu 18.04
* Python 2
* Open CV v3.2.0
* CMake >= 3.7

## Build
```bash
cd /path/to/custom_opencv_python_binding
mkdir build
cd build
cmake ..
make
```

## DEMO
After building, you can import sandbox python module.
```bash
cd /path/to/custom_opencv_python_binding/lib
ipython
In [1]: import sandbox
In [2]: import numpy as np
In [3]: sandbox.getImage(np.ones([2,2]))
```

## LICENSE
3-clause BSD License
