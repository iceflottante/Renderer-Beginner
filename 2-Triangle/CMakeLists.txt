# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)

add_executable (TriangleOutline "triangle-outline.cpp" "line.cpp")

target_link_libraries (TriangleOutline PUBLIC TGAImage)


add_executable (SweepLine "sweep-line.cpp" "line.cpp")

target_link_libraries (SweepLine PUBLIC TGAImage)


# file ends here

