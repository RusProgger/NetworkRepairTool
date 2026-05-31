cmake_minimum_required(VERSION 3.15)
project(NetworkRepairTool)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NetworkRepairTool
    src/main.cpp

)

target_include_directories(NetworkRepairTool PRIVATE ${CMAKE_SOURCE_DIR}/include)