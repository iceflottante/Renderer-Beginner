# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)

add_executable (TriangleOutline "triangle_outline.cc")
target_link_libraries (TriangleOutline PUBLIC TGAImage)


add_executable (TriangleSweepLine "triangle_sweep_line.cc")
target_link_libraries (TriangleSweepLine PUBLIC TGAImage)


add_executable (TriangleBarycentric "triangle_barycentric.cc")
target_link_libraries (TriangleBarycentric PUBLIC TGAImage)


add_executable (ExampleTriangleRandomColors "example_triangle_random_colors.cc")
target_link_libraries (ExampleTriangleRandomColors PUBLIC TGAImage)
target_link_libraries (ExampleTriangleRandomColors PUBLIC Model)


add_executable (ExampleTriangleIlluminate "example_triangle_illuminate.cc")
target_link_libraries (ExampleTriangleIlluminate PUBLIC TGAImage)
target_link_libraries (ExampleTriangleIlluminate PUBLIC Model)

# file ends here

