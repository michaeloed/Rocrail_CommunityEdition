message(STATUS "Configure roclcdr")
set(LCDR_EVENTS_SRC
    impl/events/enter.c
    impl/events/exit.c
    impl/events/free.c
    impl/events/in.c
    impl/events/pre2in.c
    )
set(LCDR_STS_SRC
    impl/status/checkroute.c
    impl/status/enter.c
    impl/status/exit.c
    impl/status/finddest.c
    impl/status/go.c
    impl/status/idle.c
    impl/status/in.c
    impl/status/initdest.c
    impl/status/out.c
    impl/status/pause.c
    impl/status/pre2in.c
    impl/status/prewait.c
    impl/status/timer.c
    impl/status/wait4event.c
    impl/status/wait.c
    )
set(LCDR_TOOLS_SRC
    impl/tools/actions.c
    impl/tools/initialize.c
    impl/tools/reserve.c
    impl/tools/schedules.c
    impl/tools/signals.c
    )
set(LCDR_SRC 
    impl/lcdriver.c
    )

set(LCDR_LIBS
    wrapper
    rocs)

if(WIN32)
    list(APPEND LCDR_SRC lcdriver.def)
    list(APPEND LCDR_LIBS ws2_32 iphlpapi mpr winmm)
endif(WIN32)

add_library(lcdriver SHARED ${LCDR_SRC} ${LCDR_EVENTS_SRC} ${LCDR_STS_SRC} ${LCDR_TOOLS_SRC})
target_link_libraries(lcdriver ${LCDR_LIBS})
set_target_properties(lcdriver PROPERTIES FOLDER "Libs")

