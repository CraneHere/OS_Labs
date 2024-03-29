cmake_minimum_required(VERSION 3.27)

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(lab2_test ../lab2/src/monteCheckThreads.cpp ../lab2/src/monteCheckDefault.cpp ../lab2/src/deck.cpp lab2_test.cpp)
target_include_directories(lab2_test PRIVATE ../lab2/include)

target_link_libraries(lab2_test PRIVATE GTest::GTest)