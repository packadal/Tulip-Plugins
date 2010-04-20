project(Tulip-Plugins)

cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE(Qt4 REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall")

set(ENGINE_PATH ${CMAKE_SOURCE_DIR}/engine)
#set(SCRIPT_PATH ${CMAKE_SOURCE_DIR}/script)
#set(JAMBI_PATH  ${CMAKE_SOURCE_DIR}/jambi)
set(EDITOR_PATH ${CMAKE_SOURCE_DIR}/editor)
set(TRANSLATER_PATH ${CMAKE_SOURCE_DIR}/translater)

set(TULIP_PATH /home/packadal/src/tulip)
set(TULIP /home/packadal/tulip/lib)
#set(QTSCRIPT_GENERATOR_PATH=/home/packadal/src/qtscriptgenerator)
#set(QTSCRIPT_GENERATOR=${QTSCRIPT_GENERATOR_PATH}/generator/generator)

#JAMBI_PATH=/net/travail/uti/chuet/qtjambi/
#JAMBI_GENERATOR_PATH=$$JAMBI_PATH/generator
#QTDIR_VAR=/usr/share/qt4

include_directories(${QT_INCLUDES}
		${ENGINE_PATH}
		${TRANSLATER_PATH}
		${TULIP_PATH}/library/tulip/include
		${TULIP_PATH}/library/tulip-qt/include
		${TULIP_PATH}/build/library/tulip/include
		${TULIP_PATH}/include )
set(TULIP_VERSION 3.4)

#QMAKE_CXXFLAGS += -Wno-deprecated
#CONFIG(debug) {
#	QMAKE_CXXFLAGS += -g
#} 
    
set(ENGINE_SOURCES ${ENGINE_PATH}/QIterator.cpp 
    ${ENGINE_PATH}/QProperty.cpp 
    ${ENGINE_PATH}/QDoubleProperty.cpp 
    ${ENGINE_PATH}/QStringProperty.cpp 
    ${ENGINE_PATH}/QBooleanProperty.cpp 
    #${ENGINE_PATH}/QLayoutProperty.cpp 
    ${ENGINE_PATH}/QIntegerProperty.cpp 
    ${ENGINE_PATH}/QColorProperty.cpp 
    ${ENGINE_PATH}/QSizeProperty.cpp 
    ${ENGINE_PATH}/QGraphProperty.cpp 
    ${ENGINE_PATH}/QGraph.cpp 
    ${ENGINE_PATH}/QNode.cpp 
    ${ENGINE_PATH}/QEdge.cpp 
    ${ENGINE_PATH}/QSize3D.cpp )

set(EDITOR_SOURCES ${EDITOR_PATH}/editor.cpp
    ${EDITOR_PATH}/scriptedit.cpp
    ${EDITOR_PATH}/scripthighlighter.cpp
    ${EDITOR_PATH}/tabsettings.cpp
    ${EDITOR_PATH}/textedit.cpp)

set(TRANSLATER_SOURCES ${TRANSLATER_PATH}/Translater.cpp)

add_library(script_editor SHARED ${EDITOR_SOURCES})
add_library(translater STATIC ${TRANSLATER_SOURCES})
add_library(script_plugin-${TULIP_VERSION} SHARED ${ENGINE_SOURCES} )

add_executable(editor_test ${EDITOR_PATH}/main.cpp)
target_link_libraries(editor_test script_editor ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} ${TULIP})

target_link_libraries(script_plugin-${TULIP_VERSION} qtscript_tulip_script script_editor)

add_subdirectory(script)
