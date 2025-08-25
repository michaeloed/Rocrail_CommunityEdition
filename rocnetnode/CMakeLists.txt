message(STATUS "Configure rocnetnode")
set(FRLIBS wrapper rocutils rocs frail)
if(WIN32)
    list(APPEND FRLIBS ws2_32 iphlpapi mpr winmm)
endif(WIN32)

set(RNN_SRC
    impl/i2c.c
    impl/io.c
    impl/ip.c
    impl/main.c
    impl/rocnetnode.c
    ../rocdigs/impl/rocnet/rn-utils.c
    )
add_executable(rocnetnode ${RNN_SRC})
set_target_properties(rocnetnode PROPERTIES FOLDER "Executables/FreeRail") 
target_link_libraries(rocnetnode ${FRLIBS} ${LIBS})
set_property(TARGET rocnetnode PROPERTY C_STANDARD 99)

