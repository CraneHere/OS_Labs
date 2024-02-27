cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-L/usr/local/include -lzmq")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_compile_options(-Wno-error=deprecated-declarations -Wdeprecated-declarations)

add_executable(control include/node.hpp include/socket.hpp
        src/node.cpp src/socket.cpp src/control.cpp
)
target_include_directories(control PRIVATE include)

add_executable(calculate include/node.hpp include/socket.hpp
        src/node.cpp src/socket.cpp src/calculate.cpp
)
target_include_directories(calculate PRIVATE include)

target_link_libraries(control PRIVATE zeromq)

target_link_libraries(calculate PRIVATE zeromq)
