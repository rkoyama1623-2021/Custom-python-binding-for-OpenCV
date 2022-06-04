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

## For your application
You can your own python module using OpenCV C++ API by modifying gen2.py and cv2.cpp.
See commit [9053b14](https://github.com/rkoyama1623/Custom-python-binding-for-OpenCV/commit/9053b140e3da7b824eb5eda12cbed07d3c2ccf49).

## LICENSE
3-clause BSD License
