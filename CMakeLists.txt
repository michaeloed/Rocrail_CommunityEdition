cmake_minimum_required (VERSION 3.3)
project (FreeRail)

execute_process(COMMAND git rev-list --count HEAD OUTPUT_VARIABLE REV OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND git log -n 1 --pretty=format:%H OUTPUT_VARIABLE COMMIT OUTPUT_STRIP_TRAILING_WHITESPACE)
configure_file(common/version.h.in common/version.h @ONLY)
                                                               
# Global properties
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories(${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/run/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/run/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/run/bin)

set(FREERAIL_OUTPUTDIR ${CMAKE_BINARY_DIR}/run/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${FREERAIL_OUTPUTDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${FREERAIL_OUTPUTDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${FREERAIL_OUTPUTDIR})

# Set for all build configurations (e.g. Debug, Release) one output folder
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${FREERAIL_OUTPUTDIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${FREERAIL_OUTPUTDIR})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${FREERAIL_OUTPUTDIR})
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(LIBS
    Threads::Threads
    ${CMAKE_DL_LIBS}
    )

add_custom_target(clean_gen
    COMMENT "Remove generated files"
    )
set_target_properties(clean_gen PROPERTIES FOLDER "Generate tasks")  

add_subdirectory(rocs/gen)
add_subdirectory(rocs)
add_subdirectory(rocrail)
add_subdirectory(rocutils)
#add_subdirectory(rocint)
add_subdirectory(rocdigs)
add_subdirectory(roclcdr)
add_subdirectory(rocnetnode)
add_subdirectory(rocview)
# Qt Viewer
add_subdirectory(freerailview)

