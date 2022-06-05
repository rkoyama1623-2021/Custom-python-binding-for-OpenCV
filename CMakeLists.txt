cmake_minimum_required(VERSION 3.7)

project(sandbox)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

find_package(OpenCV REQUIRED)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs 2 REQUIRED)
include_directories(
  ${PYTHON_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

set(cv2_generated_hdrs
    "${CMAKE_CURRENT_BINARY_DIR}/pyopencv_generated_include.h"
    "${CMAKE_CURRENT_BINARY_DIR}/pyopencv_generated_funcs.h"
    "${CMAKE_CURRENT_BINARY_DIR}/pyopencv_generated_types.h"
    "${CMAKE_CURRENT_BINARY_DIR}/pyopencv_generated_type_reg.h"
    "${CMAKE_CURRENT_BINARY_DIR}/pyopencv_generated_ns_reg.h"
)

add_custom_command(
  OUTPUT ${cv2_generated_hdrs}
  COMMAND python "${CMAKE_CURRENT_SOURCE_DIR}/gen2.py" ${CMAKE_CURRENT_BINARY_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/src/headers.txt"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src"
  DEPENDS ${opencv_hdrs}
)

add_library(sandbox SHARED
  "src/sandbox.cpp"
  "src/cv2.cpp"
  ${cv2_generated_hdrs}
)
target_include_directories(sandbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(sandbox
  ${PYTHON_LIBRARIES}
  ${OpenCV_LIBS}
)
set_target_properties(sandbox PROPERTIES
  PREFIX ""
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
)
