cmake_minimum_required(VERSION 3.15)
project(NetworkRepairTool)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NetworkRepairTool
    src/main.cpp
    # src/intro.cpp
    src/warningMessage.cpp
    src/messageInfo.cpp
    src/colorHandle.cpp
    src/system.cpp
)

target_include_directories(NetworkRepairTool PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(NetworkRepairTool PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/release"
)