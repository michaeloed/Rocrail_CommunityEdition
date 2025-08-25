message(STATUS "Configure rocutils")
set(CMAKE_CXX_STANDARD 99)
set(CMAKE_C_STANDARD 99)

set(LIBRU_SRC
    impl/addr.c
    impl/colorutils.c
    impl/crc.c
    impl/devices.c
    impl/fileutils.c
    )
add_library(rocutils STATIC ${LIBRU_SRC})
set_target_properties(rocutils PROPERTIES FOLDER "Libs")
