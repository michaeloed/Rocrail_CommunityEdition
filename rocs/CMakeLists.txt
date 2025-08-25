message(STATUS "Configure rocs")
set(ROCS_SRC
    impl/attr.c
    impl/cmdln.c
    impl/converter.h
    impl/dir.c
    impl/doc.c
    impl/ebcdic.c
    impl/event.c
    impl/file.c
    impl/gzip.c
    impl/js.c
    impl/json.c
    impl/lib.c
    impl/list.c
    impl/map.c
    impl/mem.c
    impl/mime64.c
    impl/msg.c
    impl/mutex.c
    impl/node.c
    impl/queue.c
    impl/res.c
    impl/serial.c
    impl/socket.c
    impl/stats.c
    impl/str.c
    impl/string.c
    impl/strtok.c
    impl/system.c
    impl/thread.c
    impl/trace.c
    impl/usb.c
    impl/wrpinf.c
    impl/wutils.c
    impl/xmlh.c
    )
    
if(UNIX OR APPLE)
    set(ROCSPLATFORM_SRC
        impl/unx/udir.c
        impl/unx/uevent.c
        impl/unx/ujs.c
        impl/unx/ulib.c
        impl/unx/umutex.c
        impl/unx/userial.c
        impl/unx/usocket.c
        impl/unx/usystem.c
        impl/unx/uthread.c
        impl/unx/uusb.c
        )
else(UNIX OR APPLE)
    set(ROCSPLATFORM_SRC
        impl/win/wdir.c
        impl/win/wevent.c
        impl/win/wjs.c
        impl/win/wlib.c
        impl/win/wmutex.c
        impl/win/wserial.c
        impl/win/wsocket.c
        impl/win/wsystem.c
        impl/win/wthread.c
        impl/win/wusb.c
    )
endif(UNIX OR APPLE)
    

add_library(rocs STATIC
            ${ROCS_SRC}
            ${ROCSPLATFORM_SRC}
            )  
set_target_properties(rocs PROPERTIES FOLDER "Libs")
