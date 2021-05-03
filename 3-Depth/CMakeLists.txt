# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)


add_library (Line "../2-Triangle/line.cc")


add_executable (DrawLines "draw_lines.cc")
target_link_libraries (DrawLines PUBLIC TGAImage)
target_link_libraries (DrawLines PUBLIC Line)
# target_link_libraries (DrawLines PUBLIC Geometry)


add_executable (DepthYBuffer "depth_y_buffer.cc")
target_link_libraries (DepthYBuffer PUBLIC TGAImage)
target_link_libraries (DepthYBuffer PUBLIC Model)


add_executable (DepthZBuffer "depth_z_buffer.cc")
target_link_libraries (DepthZBuffer PUBLIC TGAImage)
target_link_libraries (DepthZBuffer PUBLIC Model)


add_executable (ExampleDepthDisplay "example_depth_display.cc")
target_link_libraries (ExampleDepthDisplay PUBLIC TGAImage)
target_link_libraries (ExampleDepthDisplay PUBLIC Model)


add_executable (ExampleDepthTexture "example_depth_texture.cc")
target_link_libraries (ExampleDepthTexture PUBLIC TGAImage)
target_link_libraries (ExampleDepthTexture PUBLIC Model)


add_executable (ExampleDepthDiffuse "example_depth_diffuse.cc")
target_link_libraries (ExampleDepthDiffuse PUBLIC TGAImage)
target_link_libraries (ExampleDepthDiffuse PUBLIC Model)

# file ends here

