# CMakeLists.txt: 0-Line
#
cmake_minimum_required (VERSION 3.8)


add_executable (FirstAttempt "1st-attempt.cpp")

target_link_libraries (FirstAttempt PUBLIC TGAImage)


add_executable (SecondAttempt "2nd-attempt.cpp")

target_link_libraries (SecondAttempt PUBLIC TGAImage)


add_executable (ThirdAttempt "3rd-attempt.cpp")

target_link_libraries (ThirdAttempt PUBLIC TGAImage)


add_executable (FourthAttempt "4th-attempt.cpp")

target_link_libraries (FourthAttempt PUBLIC TGAImage)


add_executable (FifthAttempt "5th-attempt.cpp")

target_link_libraries (FifthAttempt PUBLIC TGAImage)


# file ends here

