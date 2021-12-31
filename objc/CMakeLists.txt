set(TGTNAME blockhead_objc)
set(CMAKE_CXX_FLAGS "-x objective-c++")

add_executable(${TGTNAME} main.mm)

if(APPLE)
    set(LINK_LIBS ${LINK_LIBS}
        "-framework CoreFoundation"
    )
endif(APPLE)

target_link_libraries(${TGTNAME} ${LINK_LIBS})
