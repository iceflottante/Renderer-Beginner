# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)


add_executable (Line1 "line_1.cc")
target_link_libraries (Line1 PUBLIC TGAImage)


add_executable (Line2 "line_2.cc")
target_link_libraries (Line2 PUBLIC TGAImage)


add_executable (Line3 "line_3.cc")
target_link_libraries (Line3 PUBLIC TGAImage)


add_executable (Line4 "line_4.cc")
target_link_libraries (Line4 PUBLIC TGAImage)


add_executable (Line5 "line_5.cc")
target_link_libraries (Line5 PUBLIC TGAImage)


add_executable (LineWireframe "line_wireframe.cc")
target_link_libraries (LineWireframe PUBLIC TGAImage)
target_link_libraries (LineWireframe PUBLIC Model)

# file ends here

