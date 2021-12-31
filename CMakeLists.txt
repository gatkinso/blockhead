cmake_minimum_required (VERSION 3.19)
project (blockhead)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

set(CMAKE_CXX_STANDARD 17)

if(APPLE)
    enable_language(OBJCXX)
    add_subdirectory(objc)
endif()

add_subdirectory(cpp)
