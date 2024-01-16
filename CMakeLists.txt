cmake_minimum_required(VERSION 3.20)

project(OS_LABS C CXX)

enable_testing()

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

include(FindThreads)

add_subdirectory(OS_Lab1/lab1)
add_subdirectory(OS_Lab4/lab4)
add_subdirectory(tests)