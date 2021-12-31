set(TGTNAME blockhead_objc)
set(CMAKE_CXX_FLAGS "-x objective-c++")

add_executable(${TGTNAME} main.mm)

set(LINK_LIBS ${LINK_LIBS}
    "-framework CoreFoundation"
)

target_link_libraries(${TGTNAME} ${LINK_LIBS})
