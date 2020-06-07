# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)

add_executable (TriangleOutline "triangle-outline.cpp" "line.cpp")

target_link_libraries (TriangleOutline PUBLIC TGAImage)


add_executable (SweepLine "sweep-line.cpp" "line.cpp")

target_link_libraries (SweepLine PUBLIC TGAImage)


add_executable (BarycentricCoordinate "barycentric-coordinate-method.cpp" "line.cpp")

target_link_libraries (BarycentricCoordinate PUBLIC TGAImage)


add_executable (RandomColorTriangles "random-color-triangles.cpp" "line.cpp")

target_link_libraries (RandomColorTriangles PUBLIC TGAImage)
target_link_libraries (RandomColorTriangles PUBLIC Model)



add_executable (IlluminateTriangle "illuminate-triangle.cpp" "line.cpp")

target_link_libraries (IlluminateTriangle PUBLIC TGAImage)
target_link_libraries (IlluminateTriangle PUBLIC Model)





# file ends here

