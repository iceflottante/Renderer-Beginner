# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)

add_executable (ZBuffer "main.cpp")

target_link_libraries (ZBuffer PUBLIC TGAImage)
target_link_libraries (ZBuffer PUBLIC Geometry)

# file ends here

