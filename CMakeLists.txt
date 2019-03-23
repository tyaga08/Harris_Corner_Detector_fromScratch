cmake_minimum_required(VERSION 3.5)
project(Harris_Corner_Detector_fromScratch)

IF(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_BUILD_TYPE Debug)
ENDIF()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/build/cmake)

find_package(OpenCV REQUIRED)

add_compile_options(-std=c++11)

include_directories(include
${PROJECT_SOURCE_DIR}/
${PROJECT_SOURCE_DIR}/include/
${OpenCV_INCLUDE_DIRS}
)

add_library(HarrisCorner SHARED src/source_code/harris_corner.cpp)

add_executable(find_corner src/find_corner.cpp)
target_link_libraries(find_corner ${OpenCV_LIBS} 
									HarrisCorner)
