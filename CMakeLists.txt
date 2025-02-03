cmake_minimum_required(VERSION 3.10)

project(NetworkScanner VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(server src/server.cpp)

target_link_libraries(server PRIVATE ${Boost_LIBRARIES})

add_executable(client src/client.cpp)

target_link_libraries(client PRIVATE ${Boost_LIBRARIES})
