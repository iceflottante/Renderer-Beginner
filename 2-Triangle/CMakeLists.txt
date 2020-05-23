# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)

add_executable (LineSweeping "line-sweeping.cpp" "line.cpp")

target_link_libraries (LineSweeping PUBLIC TGAImage)
target_link_libraries (LineSweeping PUBLIC LineLibModel)


# file ends here

