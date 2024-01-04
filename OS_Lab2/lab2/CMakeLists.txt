set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/monteCheckDefault.cpp src/monteCheckThreads.cpp src/deck.cpp main.cpp)

target_include_directories(main PRIVATE include)
