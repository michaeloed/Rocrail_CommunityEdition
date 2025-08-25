message(STATUS "Configure freerailview")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Enable moc
set(CMAKE_AUTOMOC ON)
# Enable qrc
set(CMAKE_AUTORCC ON)
# Enable ui
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set(FREERAILVIEW_HEADER
    freerailviewapp.h
    mainwindow.h
)

set(FREERAILVIEW_UI 
    ui/mainwindow.ui
)

set(FREERAILVIEW_QRC 
    resources/freerailview.qrc
)

set(FREERAILVIEW_SRC 
    main.cpp
    freerailviewapp.cpp
    mainwindow.cpp
)

source_group("ui" FILES ${FREERAILVIEW_UI})
source_group("include" FILES ${FREERAILVIEW_HEADER})
source_group("source" FILES ${FREERAILVIEW_SRC})

add_executable(freerailview WIN32 ${FREERAILVIEW_SRC} ${FREERAILVIEW_HEADER} ${FREERAILVIEW_UI} ${FREERAILVIEW_QRC})

# Use the Widgets module from Qt 5.
target_link_libraries(freerailview Qt5::Widgets)
set_target_properties(freerailview PROPERTIES FOLDER "Executables/FreeRail") 

