message(STATUS "Configure rocdigs")

if(UNIX OR APPLE)
    find_path(LIBUSB_INC_DIR
        NAMES libusb.h
        PATH_SUFFIXES "include" "libusb" "libusb-1.0"
    )
    find_library(LIBUSB
        NAMES usb-1.0
        PATH_SUFFIXES "lib" "lib32" "lib64"
    )    
    list(APPEND LIBS m)
endif(UNIX OR APPLE) 

set(PROTOLIBS ${LIBS} rocs)
if(WIN32)
    set(PROTOLIBS ${GENERATORLIBS} ws2_32 iphlpapi mpr winmm)
endif(WIN32)  

set(FRLIBS wrapper rocutils rocs)

file(GLOB PROT_SRC impl/*.c)

set(NMRA_SRC
    impl/nmra/nmra.c
    impl/nmra/nmrapacket.c
    )
# list of protocols that require nmra bindings (according to former makefiles)
list(APPEND NMRA_PROTO "dcc232" "sprog" "easydcc" "cti")

# create protocol targets
foreach(FILE ${PROT_SRC})
    # extract protocoll name from the source file
    get_filename_component(PROT ${FILE} NAME_WE)
    list(APPEND PROTOCOLS ${PROT})
    message(STATUS "  add ${PROT} protocol support")

    # if there's a subdirectory, add the sources from there (except opendcc)
    set(PROT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/impl/${PROT})
    if(EXISTS ${PROT_DIR} AND IS_DIRECTORY ${PROT_DIR} AND NOT ${PROT} STREQUAL "opendcc")
        file(GLOB XTR_SRC impl/${PROT}/*.c)
    else()
        set(XTR_SRC "")
    endif()

    if(WIN32)
        if(${PROT} STREQUAL "bidib")
            list(APPEND XTR_SRC impl/${PROT}/${PROT}.def)
        else()
            list(APPEND XTR_SRC rocdigs.def)
        endif()
    endif()

    # add NMRA sources if required
    if(${PROT} IN_LIST NMRA_PROTO)
        list(APPEND XTR_SRC ${NMRA_SRC})
    endif()

    add_library(${PROT} SHARED ${FILE} ${XTR_SRC})
    set_target_properties(${PROT} PROPERTIES FOLDER "Libs/Protocols") 
    target_link_libraries(${PROT} ${PROTOLIBS} ${FRLIBS})
endforeach()

# add special compile flag to ddx (like in the former makefiles)
if (UNIX OR APPLE)
    if(TARGET ddx)
        target_compile_options(ddx PUBLIC "-O2")
    endif()
endif (UNIX OR APPLE)

# link rocomp also to libusb on Unix and MacOS
if (UNIX OR APPLE)
    if(TARGET rocomp)
        target_include_directories(rocomp PUBLIC ${LIBUSB_INC_DIR})
        target_link_libraries(rocomp ${LIBUSB})
    endif()
endif(UNIX OR APPLE)

# cutom target to build all protocols at once
add_custom_target(rocdigs
    DEPENDS ${PROTOCOLS}
    )
set_target_properties(rocdigs PROPERTIES FOLDER "Libs/Protocols")

