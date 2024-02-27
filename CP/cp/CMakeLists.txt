set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.27)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_library(FBLA_al STATIC src/FBLAllocator.cpp ${INCLUDE_DIR}/FBLAllocator.hpp)
add_library(Twin_al STATIC src/TwinAllocator.cpp ${INCLUDE_DIR}/TwinAllocator.hpp)
add_library(FBLA SHARED src/FBLAllocator.cpp ${INCLUDE_DIR}/FBLAllocator.hpp)
add_library(Twin SHARED src/TwinAllocator.cpp ${INCLUDE_DIR}/TwinAllocator.hpp)

target_include_directories(FBLA_al PUBLIC ${INCLUDE_DIR})
target_include_directories(FBLA PUBLIC ${INCLUDE_DIR})

target_include_directories(Twin_al PUBLIC ${INCLUDE_DIR})
target_include_directories(Twin PUBLIC ${INCLUDE_DIR})

add_executable(main main.cpp)

target_include_directories(main PRIVATE ${INCLUDE_DIR})

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# cmake_minimum_required(VERSION 3.27)

# set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# add_library(lib1_static STATIC src/lib1.cpp ${INCLUDE_DIR}/lib.h src/utils.cpp ${INCLUDE_DIR}/utils.h)
# add_library(lib2_static STATIC src/lib2.cpp ${INCLUDE_DIR}/lib.h src/utils.cpp ${INCLUDE_DIR}/utils.h)
# add_library(lib1 SHARED src/lib1.cpp ${INCLUDE_DIR}/lib.h src/utils.cpp ${INCLUDE_DIR}/utils.h)
# add_library(lib2 SHARED src/lib2.cpp ${INCLUDE_DIR}/lib.h src/utils.cpp ${INCLUDE_DIR}/utils.h)

# target_include_directories(lib1_static PUBLIC ${INCLUDE_DIR})
# target_include_directories(lib1 PUBLIC ${INCLUDE_DIR})

# target_include_directories(lib2_static PUBLIC ${INCLUDE_DIR})
# target_include_directories(lib2 PUBLIC ${INCLUDE_DIR})

# add_executable(static_main static_main.cpp)
# add_executable(dynamic_main dynamic_main.cpp)

# target_link_libraries(static_main PRIVATE lib1)

# target_include_directories(dynamic_main PRIVATE ${INCLUDE_DIR})