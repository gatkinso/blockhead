
set(TGTNAME blockhead_cpp)

set(CMAKE_CXX_FLAGS "-x objective-c++")

add_executable(${TGTNAME} main.cpp)

if(APPLE)
    set(LINK_LIBS ${LINK_LIBS}
        "-framework CoreFoundation"
#        "-framework CoreServices"
        )
endif(APPLE)

target_link_libraries(${TGTNAME} ${LINK_LIBS})
