set(TGTNAME blockhead_cpp)

if(LINUX)
    SET(CMAKE_CXX_FLAGS -fblocks)
    set(LINK_LIBS ${LINK_LIBS} BlocksRuntime)
endif()

add_executable(${TGTNAME} main.cpp)

target_link_libraries(${TGTNAME} ${LINK_LIBS})

