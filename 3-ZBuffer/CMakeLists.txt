# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)


add_library (Line "../2-Triangle/line.cc")


add_executable (ZBufferDrawLines "draw_lines.cc")
target_link_libraries (ZBufferDrawLines PUBLIC TGAImage)
target_link_libraries (ZBufferDrawLines PUBLIC Line)
# target_link_libraries (DrawLines PUBLIC Geometry)


add_executable (ZBufferYBuffer "y_buffer.cc")
target_link_libraries (ZBufferYBuffer PUBLIC TGAImage)
target_link_libraries (ZBufferYBuffer PUBLIC Model)


add_executable (ZBuffer "z_buffer.cc")
target_link_libraries (ZBuffer PUBLIC TGAImage)
target_link_libraries (ZBuffer PUBLIC Model)


add_executable (TextureExample "texture_example.cc")
target_link_libraries (TextureExample PUBLIC TGAImage)
target_link_libraries (TextureExample PUBLIC Model)

# file ends here

