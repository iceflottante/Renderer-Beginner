# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)


add_library (Line "../2-Triangle/line.cpp")


add_executable (ZBuffer "main.cpp")

target_link_libraries (ZBuffer PUBLIC TGAImage)
# target_link_libraries (ZBuffer PUBLIC Geometry)


add_executable (ZBufferDrawLines "draw-lines.cpp")

target_link_libraries (ZBufferDrawLines PUBLIC TGAImage)
target_link_libraries (ZBufferDrawLines PUBLIC Line)
# target_link_libraries (DrawLines PUBLIC Geometry)


add_executable (ZBufferYBuffer "y-buffer.cpp")

target_link_libraries (ZBufferYBuffer PUBLIC TGAImage)
target_link_libraries (ZBufferYBuffer PUBLIC Line)


# file ends here

