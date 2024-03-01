cmake_minimum_required(VERSION 3.27)

include(FetchContent)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../lab4)
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

add_library(lib1_static SHARED ${INCLUDE_DIR}/src/utils.cpp ${INCLUDE_DIR}/src/lib1.cpp)
add_library(lib2_static SHARED ${INCLUDE_DIR}/src/utils.cpp ${INCLUDE_DIR}/src/lib2.cpp)

target_include_directories(lib1_static PRIVATE ${PROJECT_SOURCE_DIR}/../lab4/include)
target_include_directories(lib2_static PRIVATE ${PROJECT_SOURCE_DIR}/../lab4/include)

add_executable(lab4_lib1_test lab4_lib1_test.cpp ${PROJECT_SOURCE_DIR}/../lab4/include/lib.h ${PROJECT_SOURCE_DIR}/../lab4/include/utils.h)
target_include_directories(lab4_lib1_test PRIVATE ${PROJECT_SOURCE_DIR}/../lab4/include)
target_link_libraries(lab4_lib1_test PRIVATE lib1_static GTest::GTest)

add_executable(lab4_lib2_test lab4_lib2_test.cpp ${PROJECT_SOURCE_DIR}/../lab4/include/lib.h ${PROJECT_SOURCE_DIR}/../lab4/include/utils.h)
target_link_libraries(lab4_lib2_test PRIVATE lib2_static GTest::GTest)
target_include_directories(lab4_lib2_test PRIVATE ${PROJECT_SOURCE_DIR}/../lab4/include)