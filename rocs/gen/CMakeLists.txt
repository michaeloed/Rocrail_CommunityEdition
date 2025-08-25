message(STATUS "Configure generators")

set(GENTARGETS 
#    wgen
#    ogen
    xml2cstr
    png2wx
#    addlang
#    mergelang
#    mdoc
#    lang2po
#    po2lang
    )

set(GENERATORLIBS ${LIBS} rocs)
if(WIN32)
    list(APPEND GENERATORLIBS ws2_32 iphlpapi mpr)
endif(WIN32)

#add_executable(wgen wgen.c)
#target_link_libraries(wgen ${GENERATORLIBS})
#add_executable(ogen ogen.c)
#target_link_libraries(ogen ${GENERATORLIBS})
add_executable(xml2cstr xml2cstr.c)
target_link_libraries(xml2cstr ${GENERATORLIBS})
add_executable(png2wx png2wx.c)
target_link_libraries(png2wx ${GENERATORLIBS})
#add_executable(addlang addlang.c)
#target_link_libraries(addlang ${GENERATORLIBS})
#add_executable(mergelang mergelang.c)
#target_link_libraries(mergelang ${GENERATORLIBS})
#add_executable(mdoc mdoc.c)
#target_link_libraries(mdoc ${GENERATORLIBS})
#add_executable(lang2po lang2po.c)
#target_link_libraries(lang2po ${GENERATORLIBS})
#add_executable(po2lang po2lang.c)
#target_link_libraries(po2lang ${GENERATORLIBS})
set_target_properties(${GENTARGETS} PROPERTIES FOLDER "Executables/Generators") 

# Replacemant for the former 'fromtar' target
# It seems like it was an alternative 'clean' target. It removed previously compiled
# binary files like 'clean' did, too. But 'fromtar' unpacks an archive of source files
# while 'clean' generated them using the ogen binary and created the archive used here
# from them.
# There is obviously a circular dependency between building ogen, libroc and calling
# ogen to generate files required to build libroc.
#set(TAR_STAMP ${CMAKE_CURRENT_BINARY_DIR}/tar.stamp)
#add_custom_command(
#    OUTPUT ${TAR_STAMP}
#    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/..
#    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/
#    COMMAND ${CMAKE_COMMAND} -E tar xzf ${CMAKE_CURRENT_SOURCE_DIR}/../rocs-gen.tar.gz .
#    COMMAND ${CMAKE_COMMAND} -E touch ${OGEN_STAMP}
#    COMMAND ${CMAKE_COMMAND} -E touch ${TAR_STAMP}
#    COMMENT "Unpack generated rocs sources"
#    )

#add_custom_target(fromtar
#    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#    SOURCES ${TAR_STAMP}
#    COMMENT "Execute fromtar"
#    )


