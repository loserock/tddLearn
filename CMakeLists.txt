cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

###################

enable_testing()

add_executable(
    minimath_test
    minimath.cpp
    minimath_test.cpp
)
target_link_libraries(
    minimath_test
    gtest_main
)

add_executable(
    deq_test
    deq.cpp
    deq_test.cpp
)
target_link_libraries(
    deq_test
    gtest_main
)

add_executable(
    deq_test_2
    deq.cpp
    deq_test2.cpp
)
target_link_libraries(
    deq_test_2
    gtest_main
    gmock_main
)
    
add_executable(
    sample
    wrong.cpp
    basic1.cpp
    math_test.cpp
#   mock_sample.cpp
)
target_link_libraries(
    sample
    gtest_main
    gmock_main
)


include(GoogleTest)
gtest_discover_tests(minimath_test)
