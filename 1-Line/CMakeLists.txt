# CMakeLists.txt: 0-Getting-Started
#
cmake_minimum_required (VERSION 3.8)

add_executable (FirstAttempt "first-attempt.cpp")
target_link_libraries (FirstAttempt PUBLIC TGAImage)

add_executable (SecondAttempt "second-attempt.cpp")
target_link_libraries (SecondAttempt PUBLIC TGAImage)

add_executable (ThirdAttempt "third-attempt.cpp")
target_link_libraries (ThirdAttempt PUBLIC TGAImage)

# file ends here

