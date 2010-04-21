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
set(TULIP /home/packadal/tulip/lib/libtulip-3.4.so 
	  /home/packadal/tulip/lib/libtulip-qt4-3.4.so 
	  /home/packadal/tulip/lib/libtulip-ogl-3.4.so 
	  /home/packadal/tulip/lib/libtulip-pluginsmanager-3.4.so)

set(QTSCRIPTLIBS /home/packadal/src/qtscriptgenerator/plugins/script/libqtscript_core.so 
		 /home/packadal/src/qtscriptgenerator/plugins/script/libqtscript_gui.so)

include_directories(${QT_INCLUDES}
		${ENGINE_PATH}
		${TRANSLATER_PATH}
		${TULIP_PATH}/library/tulip/include
		${TULIP_PATH}/library/tulip-qt/include
		${TULIP_PATH}/build/library/tulip/include
		${TULIP_PATH}/include )
set(TULIP_VERSION 3.4)

set (SCRIPT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QBooleanProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QColorProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QDoubleProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QEdge.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QGraph.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QGraphProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QIntegerProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QIterator.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QNode.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QSize3D.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QSizeProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscript_QStringProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QBooleanProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QColorProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QDoubleProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QEdge.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QGraph.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QGraphProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QIntegerProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QIterator.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QNode.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QSizeProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/qtscriptshell_QStringProperty.cpp 
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/tulip_script_init.cpp
	${CMAKE_SOURCE_DIR}/script/generated_cpp/tulip_script/plugin.cpp)
    
# add_library(qtscript_tulip_script SHARED ${SCRIPT_SOURCES} ${ENGINE_SOURCES} ${ENGINE_PATH}/TulipScriptEngine.cpp)

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
    ${ENGINE_PATH}/QSize3D.cpp)

set(ENGINE_HEADERS ${ENGINE_PATH}/QIterator.h 
    ${ENGINE_PATH}/QProperty.h 
    ${ENGINE_PATH}/QDoubleProperty.h 
    ${ENGINE_PATH}/QStringProperty.h 
    ${ENGINE_PATH}/QBooleanProperty.h 
    ${ENGINE_PATH}/QIntegerProperty.h 
    ${ENGINE_PATH}/QColorProperty.h 
    ${ENGINE_PATH}/QSizeProperty.h 
    ${ENGINE_PATH}/QGraphProperty.h 
    ${ENGINE_PATH}/QGraph.h 
    ${ENGINE_PATH}/QNode.h 
    ${ENGINE_PATH}/QEdge.h 
    ${ENGINE_PATH}/QSize3D.h
    ${ENGINE_PATH}/TulipScriptEngine.h)

QT4_WRAP_CPP(ENGINE_SOURCES_MOC ${ENGINE_HEADERS})
set(ENGINE_SOURCES ${ENGINE_SOURCES} ${ENGINE_SOURCES_MOC})

set(EDITOR_SOURCES ${EDITOR_PATH}/scriptedit.cpp
    ${EDITOR_PATH}/scripthighlighter.cpp
    ${EDITOR_PATH}/tabsettings.cpp
    ${EDITOR_PATH}/textedit.cpp)

set(EDITOR_HEADERS ${EDITOR_PATH}/editor.h
    ${EDITOR_PATH}/scriptedit.h
    ${EDITOR_PATH}/scripthighlighter.h
    ${EDITOR_PATH}/textedit.h)

set(TRANSLATER_SOURCES ${TRANSLATER_PATH}/Translater.cpp)

QT4_WRAP_CPP(EDITOR_SOURCES_MOC ${EDITOR_HEADERS})
set(EDITOR_SOURCES ${EDITOR_SOURCES} ${EDITOR_SOURCES_MOC})

# add_library(script_editor STATIC ${EDITOR_SOURCES})
# add_library(translater STATIC  ${TRANSLATER_SOURCES})
# add_library(script-tulip SHARED ${ENGINE_SOURCES})
add_library(script_plugin-${TULIP_VERSION} SHARED ${EDITOR_PATH}/editor.cpp ${EDITOR_SOURCES} ${TRANSLATER_SOURCES} ${SCRIPT_SOURCES} ${ENGINE_SOURCES} ${ENGINE_PATH}/TulipScriptEngine.cpp)
target_link_libraries(script_plugin-${TULIP_VERSION} ${qtscript_tulip_script})
# target_link_libraries(script_plugin-${TULIP_VERSION} script_editor)
# target_link_libraries(script_plugin-${TULIP_VERSION}  script-tulip translater)
target_link_libraries(script_plugin-${TULIP_VERSION} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTSCRIPT_LIBRARY} ${TULIP} ${QTSCRIPTLIBS})

# add_executable(editor_test ${EDITOR_PATH}/main.cpp)
# target_link_libraries(editor_test script_editor ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTSCRIPT_LIBRARY} ${TULIP} ${QTSCRIPTLIBS})
