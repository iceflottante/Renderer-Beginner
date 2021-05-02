# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)


add_executable (Transformation2D "transformation_2d.cc")

target_link_libraries (Transformation2D PUBLIC TGAImage)
target_link_libraries (Transformation2D PUBLIC Line)

# file ends here

