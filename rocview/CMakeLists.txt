message(STATUS "Configure rocview")

set(CMAKE_CXX_STANDARD 11)

# provide extra options to wx-config to find a certain (not default) wxWidgets lib on unix systems
set(wxWidgets_CONFIG_OPTIONS $ENV{wxWidgets_CONFIG_OPTIONS})

set(FRLIBS wrapper rocutils rocs frail)
find_package(wxWidgets REQUIRED core base adv)
include(${wxWidgets_USE_FILE})
set( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fno-common" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fno-common" )

set(RVWRP_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/wrapper)
set(RVWRP_SRC
    ${RVWRP_SRC_DIR}/impl/Accelerator.c
    ${RVWRP_SRC_DIR}/impl/Cmdline.c
    ${RVWRP_SRC_DIR}/impl/ColPos.c
    ${RVWRP_SRC_DIR}/impl/CVcat.c
    ${RVWRP_SRC_DIR}/impl/CVconf.c
    ${RVWRP_SRC_DIR}/impl/Gui.c
    ${RVWRP_SRC_DIR}/impl/LcCtrl.c
    ${RVWRP_SRC_DIR}/impl/LocoGrid.c
    ${RVWRP_SRC_DIR}/impl/MGV.c
    ${RVWRP_SRC_DIR}/impl/MGVServo.c
    ${RVWRP_SRC_DIR}/impl/MIC.c
    ${RVWRP_SRC_DIR}/impl/ModPanel.c
    ${RVWRP_SRC_DIR}/impl/Patch.c
    ${RVWRP_SRC_DIR}/impl/PlanPanel.c
    ${RVWRP_SRC_DIR}/impl/PowerCtrl.c
    ${RVWRP_SRC_DIR}/impl/Release.c
    ${RVWRP_SRC_DIR}/impl/RRCon.c
    ${RVWRP_SRC_DIR}/impl/SensorMonitor.c
    ${RVWRP_SRC_DIR}/impl/Shortcut.c
    ${RVWRP_SRC_DIR}/impl/SplitPanel.c
    ${RVWRP_SRC_DIR}/impl/SwCtrl.c
    ${RVWRP_SRC_DIR}/impl/Tab.c
    ${RVWRP_SRC_DIR}/impl/ThemeBlock.c
    ${RVWRP_SRC_DIR}/impl/Theme.c
    ${RVWRP_SRC_DIR}/impl/ThemePanel.c
    ${RVWRP_SRC_DIR}/impl/Window.c
    ${RVWRP_SRC_DIR}/impl/WorkSpace.c
    ${RVWRP_SRC_DIR}/impl/WorkSpaces.c
    ${RVWRP_SRC_DIR}/impl/wrapper.c
    )
set(RVRES_DIR ${CMAKE_CURRENT_BINARY_DIR}/res)
set(RVMSG_C ${RVRES_DIR}/messages.c)
set(RVWRP_C ${RVWRP_SRC_DIR}/impl/guiwrapperinfo.c)
set(RVFRRRP_C ${CMAKE_CURRENT_SOURCE_DIR}/../rocrail/wrapper/impl/wrapperinfo.c)
set(RVPNG_OUT ${RVRES_DIR}/icons)
set(RVPNG_CXX ${RVPNG_OUT}.cpp)
set(RVPNG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/icons)
set(RVWRP_XML ${CMAKE_CURRENT_SOURCE_DIR}/public/wrapper.xml)
set(RVMSG_XML ${CMAKE_CURRENT_SOURCE_DIR}/res/messages.xml)
add_custom_command(
    OUTPUT ${RVMSG_C}
    DEPENDS ${RVMSG_XML} xml2cstr
    COMMAND ${CMAKE_COMMAND} -E remove ${RVMSG_C}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${RVRES_DIR}
    COMMAND xml2cstr ${RVMSG_XML} ${RVMSG_C} "messages" # > /dev/null
    COMMENT "Generate message.c by xml2cstr"
    VERBATIM
    )
add_custom_command(
    OUTPUT ${RVPNG_CXX}
    DEPENDS ${RVPNG_DIR} png2wx
    COMMAND ${CMAKE_COMMAND} -E remove ${RVPNG_OUT}.hpp ${RVPNG_CXX}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${RVRES_DIR}
    COMMAND png2wx ${RVPNG_DIR} ${RVPNG_OUT} # > /dev/null
    COMMENT "Generate source file from icons"
    VERBATIM
    )

set(RV_SRC
    impl/base.cpp
    impl/basepanel.cpp
    impl/cellrenderer.cpp
    impl/clock.cpp
    impl/cv.cpp
    impl/guiapp.cpp
    impl/guiframe.cpp
    impl/item.cpp
    impl/jssupport.cpp
    impl/lc.cpp
    impl/ledbutton.cpp
    impl/lncv.cpp
    impl/meter.cpp
    impl/modpanel.cpp
    impl/planpanel.cpp
    impl/routedlg.cpp
    impl/slider.cpp
    impl/statbar.cpp
    impl/swdlg.cpp
    )
set(RVDIALOG_SRC
    dialogs/accdecdlg.cpp
    dialogs/accdecgendlg.cpp
    dialogs/actionsctrldlg.cpp
    dialogs/basedlg.cpp
    dialogs/basenotebook.cpp
    dialogs/blockdialog.cpp
    dialogs/blockgroupingdlg.cpp
    dialogs/cardlg.cpp
    dialogs/cardlggen.cpp
    dialogs/clockdialog.cpp
    dialogs/cmdrecorder.cpp
    dialogs/cmdrecordergen.cpp
    dialogs/colorpanel.cpp
    dialogs/connectiondialog.cpp
    dialogs/decconfigdlg.cpp
    dialogs/decconfigdlggen.cpp
    dialogs/dipdlg.cpp
    dialogs/feedbackdialog.cpp
    dialogs/fundialog.cpp
    dialogs/fxdlg.cpp
    dialogs/fxdlggen.cpp
    dialogs/gotodlg.cpp
    dialogs/gotodlggen.cpp
    dialogs/guestloco.cpp
    dialogs/guestlocogen.cpp
    dialogs/historypanel.cpp
    dialogs/infodialog.cpp
    dialogs/issuedlg.cpp
    dialogs/issuedlggen.cpp
    dialogs/locationsdlg.cpp
    dialogs/locdialog.cpp
    dialogs/locowidget.cpp
    dialogs/locowidgetgen.cpp
    dialogs/locseldlg.cpp
    dialogs/modplandlg.cpp
    dialogs/modulepropsdlg.cpp
    dialogs/mvtrackdlg.cpp
    dialogs/operatordlg.cpp
    dialogs/operatordlggen.cpp
    dialogs/outputdialog.cpp
    dialogs/planpaneldlg.cpp
    dialogs/powerctrldlg.cpp
    dialogs/powerctrlgen.cpp
    dialogs/powermandlg.cpp
    dialogs/powermandlggen.cpp
    dialogs/rocguiinidlg.cpp
    dialogs/rocprodlg.cpp
    dialogs/rocprodlggen.cpp
    dialogs/rocrailinidialog.cpp
    dialogs/routedialog.cpp
    dialogs/scheduledialog.cpp
    dialogs/schedulegraph.cpp
    dialogs/selectdialog.cpp
    dialogs/seltabdlg.cpp
    dialogs/seltabtrackdlg.cpp
    dialogs/sensorevents.cpp
    dialogs/sensoreventsgen.cpp
    dialogs/signaldialog.cpp
    dialogs/softwareupdates.cpp
    dialogs/speedcurvedlg.cpp
    dialogs/speedcurvedlggen.cpp
    dialogs/stagedlg.cpp
    dialogs/stagedlggen.cpp
    dialogs/switchdialog.cpp
    dialogs/textdialog.cpp
    dialogs/throttledlg.cpp
    dialogs/throttledlggen.cpp
    dialogs/timedactions.cpp
    dialogs/toursdlg.cpp
    dialogs/toursdlggen.cpp
    dialogs/tracedlg.cpp
    dialogs/tracedlggen.cpp
    dialogs/trackdialog.cpp
    dialogs/trackpickerdlg.cpp
    dialogs/trackpickerdlggen.cpp
    dialogs/tttrackdialog.cpp
    dialogs/turntabledialog.cpp
    dialogs/undodlg.cpp
    dialogs/variabledlg.cpp
    dialogs/variabledlggen.cpp
    dialogs/waybilldlg.cpp
    dialogs/waybilldlggen.cpp
    dialogs/weatherdlg.cpp
    dialogs/weatherdlggen.cpp
    dialogs/widgetspanel.cpp
    dialogs/zoomdlg.cpp
    dialogs/zoomdlggen.cpp
    dialogs/controllers/barjutdlg.cpp
    dialogs/controllers/bidibdlg.cpp
    dialogs/controllers/bidibdlggen.cpp
    dialogs/controllers/cbusdlg.cpp
    dialogs/controllers/cbusdlggen.cpp
    dialogs/controllers/dcc232dlg.cpp
    dialogs/controllers/dcc232dlggen.cpp
    dialogs/controllers/ddxdlg.cpp
    dialogs/controllers/dinamodlg.cpp
    dialogs/controllers/dmxdlg.cpp
    dialogs/controllers/dmxdlggen.cpp
    dialogs/controllers/ecosdlg.cpp
    dialogs/controllers/gendlg.cpp
    dialogs/controllers/hsi88dlg.cpp
    dialogs/controllers/lenzdlg.cpp
    dialogs/controllers/loconetdlg.cpp
    dialogs/controllers/opendcc.cpp
    dialogs/controllers/rocnetdlg.cpp
    dialogs/controllers/rocnetdlggen.cpp
    dialogs/controllers/spldlg.cpp
    dialogs/controllers/spldlggen.cpp
    dialogs/controllers/srcpdlg.cpp
    dialogs/controllers/ucons88dlg.cpp
    dialogs/controllers/ucons88dlggen.cpp
    dialogs/decoders/bidibidendlggen.cpp
    dialogs/decoders/bidibidentdlg.cpp
    dialogs/decoders/cbusnodedlg.cpp
    dialogs/decoders/cbusnodedlggen.cpp
    dialogs/decoders/channeltunedlg.cpp
    dialogs/decoders/channeltunegen.cpp
    dialogs/decoders/dtopswdlg.cpp
    dialogs/decoders/dtopswdlggen.cpp
    dialogs/decoders/hueconfdlg.cpp
    dialogs/decoders/hueconfdlggen.cpp
    dialogs/decoders/locoio.cpp
    dialogs/decoders/mgv141dlg.cpp
    dialogs/decoders/mgv141dlggen.cpp
    dialogs/decoders/mgvdlg.cpp
    dialogs/decoders/mgvdlggen.cpp
    dialogs/decoders/rocnetnodedlg.cpp
    dialogs/decoders/rocnetnodegen.cpp
    dialogs/decoders/uhl68610dlg.cpp
    dialogs/decoders/uhl68610gen.cpp
)
set(RVSMBL_SRC symbols/renderer.cpp symbols/svg.cpp)

add_executable(rocview WIN32 ${RV_SRC} ${RVDIALOG_SRC} ${RVSMBL_SRC} ${RVWRP_SRC} ${RVWRP_C} ${RVFRRRP_C} ${RVMSG_C} ${RVPNG_CXX})
set_target_properties(rocview PROPERTIES FOLDER "Executables/FreeRail") 
target_link_libraries(rocview ${LIBS} ${FRLIBS} ${wxWidgets_LIBRARIES} bidib)
