# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)


add_executable (LineSweeping "line-sweeping.cpp")

target_link_libraries (LineSweeping PUBLIC TGAImage)


# file ends here

