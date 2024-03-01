find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(${INCLUDE_DIR};/Users/Shy/Documents/vcpkg/installed/arm64-osx/include)

add_executable(lab5_7_test lab5_7_test.cpp ../lab5_7/include/topology.h ../lab5_7/include/node.h ../lab5_7/include/socket.h)
target_link_libraries(lab5_7_test GTest::gtest GTest::gtest_main /Users/Shy/Documents/vcpkg/installed/arm64-osx/lib/libzmq.a zmqsocket zmqnode nodetopo)
target_include_directories(lab5_7_test PRIVATE ../lab5_7/include)
add_test(lab5_7_test lab5_7_test)
