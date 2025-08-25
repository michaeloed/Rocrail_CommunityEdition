message(STATUS "Configure rocint")
set(ROCINT_XML ${CMAKE_CURRENT_SOURCE_DIR}/rocint.xml)
set(OGEN_STAMP ${CMAKE_CURRENT_BINARY_DIR}/ogen.stamp)
add_custom_command(
    OUTPUT ${OGEN_STAMP}
    DEPENDS ${ROCINT_XML}
    # required because other xml files have this as a dependency with relative path
    COMMAND ${CMAKE_COMMAND} -E copy ${ROCINT_XML} ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ogen ${ROCINT_XML} # > /dev/null
    COMMAND ${CMAKE_COMMAND} -E touch ${OGEN_STAMP}
    COMMENT "Generate sources from rocint.xml"
    VERBATIM
    )
add_custom_target(gen_int ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    SOURCES ${OGEN_STAMP}
    )     
set_target_properties(gen_int PROPERTIES FOLDER "Generate tasks") 
add_dependencies(gen_int ogen)

add_custom_target(clean_gen_int
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/doc
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/public
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/impl
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_BINARY_DIR}/rocint.xml
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_BINARY_DIR}/ogen.???.trc
    COMMAND ${CMAKE_COMMAND} -E remove ${OGEN_STAMP}
    COMMENT "Remove generated files from rocint.xml"
    )      
set_target_properties(clean_gen_int PROPERTIES FOLDER "Generate tasks") 
# unfortunately, it doesn't seem to be possible to add this to make's clean command
add_dependencies(clean_gen clean_gen_int)

