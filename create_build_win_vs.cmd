@echo off

rem ----------------------------------------------------------------------------
rem TODO: Set variables for Qt
echo Prepare Qt
set QT5_BASE_DIR=<full path to root of the Qt installation>
set QT5_BIN=%QT5_BASE_DIR%\bin

rem TODO: Set variables for wxWidgets
echo Prepare wxWidgets
set WXWIN=<Full path to root of wxWidget installation>
set WXVARIANT=<subpath to lib-dir (e.g. lib/vc141_dll for visual studio 2017 32bit DLLs)>
set WXVERSION=<version of wxWidgets>                                                                                        
rem ----------------------------------------------------------------------------                                                                                        

title FreeRail build environment
cls

echo Prepare build directory
if not exist _build md _build
cd _build
del /S /Q *.* >nul 2>&1

echo Prepare wxWidgets cmake-build
set wxWidgets_ROOT_DIR=%WXWIN%
set wxWidgets_LIB_DIR=%WXWIN%%WXVARIANT%
echo wxWidgets_CONFIGURATION:STRING=mswu > CMakeCache.txt
echo wxWidgets_LIB_DIR:PATH=%wxWidgets_LIB_DIR% >> CMakeCache.txt
echo wxWidgets_ROOT_DIR:PATH=%wxWidgets_ROOT_DIR% >> CMakeCache.txt
echo WX_LIB_DIR:INTERNAL=%wxWidgets_LIB_DIR% >> CMakeCache.txt
echo WX_ROOT_DIR:INTERNAL=%wxWidgets_ROOT_DIR% >> CMakeCache.txt

echo Prepare environment
set PATH=%PATH%;%QT5_BIN%;%WXWIN%;%wxWidgets_LIB_DIR%

echo Run CMake
cmake ..

echo Prepare output directory
if not exist run\bin md run\bin

echo Copy required wx libs
copy %wxWidgets_LIB_DIR%wxmsw%WXVERSION%ud_core_vc_custom.dll run\bin\
copy %wxWidgets_LIB_DIR%wxbase%WXVERSION%ud_vc_custom.dll run\bin\
copy %wxWidgets_LIB_DIR%wxmsw%WXVERSION%ud_adv_vc_custom.dll run\bin\
copy %wxWidgets_LIB_DIR%wxmsw%WXVERSION%u_core_vc_custom.dll run\bin\
copy %wxWidgets_LIB_DIR%wxbase%WXVERSION%u_vc_custom.dll run\bin\
copy %wxWidgets_LIB_DIR%wxmsw%WXVERSION%u_adv_vc_custom.dll run\bin\

cd..
pause