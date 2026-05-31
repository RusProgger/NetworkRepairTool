cmake_minimum_required(VERSION 3.10)
project(networkRepairTool)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(networkRepairTool
    src/main.cpp

)

target_include_directories(networkRepairTool PRIVATE ${CMAKE_SOURCE_DIR}/include)