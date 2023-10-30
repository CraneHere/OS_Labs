add_executable(main src/parent.cpp main.cpp)
add_executable(child src/child.cpp)

target_include_directories(main PRIVATE include)
target_include_directories(child PRIVATE include)
