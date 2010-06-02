project(TulipScript)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH /home/packadal/tulip/share)

set(TULIP_DIR /home/packadal/tulip)

SET(CMAKE_CXX_FLAGS_DEBUG  "-g -Wall -Wextra")

find_package(Qt4 REQUIRED)
find_package(Tulip REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} editor translater engine)
# include_directories(${TULIP_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR} .)
include_directories(/home/packadal/tulip/include ${CMAKE_CURRENT_BINARY_DIR} .)
include_directories(${QT_INCLUDE_DIR} ${QT_INCLUDES})

# set(CMAKE_CXX_FLAGS "-Wall")
# set(CMAKE_CXX_FLAGS_DEBUG "-g")
# set(CMAKE_CXX_FLAGS_RELEASE "-Wall")

# set(TULIP_PATH /home/packadal/tulip)
# set(TULIP /home/packadal/tulip/lib/libtulip-3.4.so
# 	  /home/packadal/tulip/lib/libtulip-qt4-3.4.so 
# 	  /home/packadal/tulip/lib/libtulip-ogl-3.4.so 
# 	  /home/packadal/tulip/lib/libtulip-pluginsmanager-3.4.so)

# set(TulipVersion 3.4)

set (SCRIPT_SOURCES
	script/generated_cpp/tulip_script/qtscript_QBooleanProperty.cpp 
	script/generated_cpp/tulip_script/qtscript_QColorProperty.cpp 
	script/generated_cpp/tulip_script/qtscript_QDoubleProperty.cpp 
	script/generated_cpp/tulip_script/qtscript_QEdge.cpp 
	script/generated_cpp/tulip_script/qtscript_QGraph.cpp 
	script/generated_cpp/tulip_script/qtscript_QGraphProperty.cpp 
	script/generated_cpp/tulip_script/qtscript_QIntegerProperty.cpp 
	script/generated_cpp/tulip_script/qtscript_QIterator.cpp 
	script/generated_cpp/tulip_script/qtscript_QNode.cpp 
	script/generated_cpp/tulip_script/qtscript_QView.cpp 
	script/generated_cpp/tulip_script/qtscript_QControllerViewsManager.cpp 
	script/generated_cpp/tulip_script/qtscript_QProperty.cpp 
	script/generated_cpp/tulip_script/qtscript_QLayoutProperty.cpp 
	script/generated_cpp/tulip_script/qtscript_QSize3D.cpp 
	script/generated_cpp/tulip_script/qtscript_QSizeProperty.cpp 
	script/generated_cpp/tulip_script/qtscript_QStringProperty.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QBooleanProperty.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QColorProperty.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QDoubleProperty.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QEdge.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QGraph.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QGraphProperty.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QIntegerProperty.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QIterator.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QNode.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QSize3D.cpp
	script/generated_cpp/tulip_script/qtscriptshell_QProperty.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QLayoutProperty.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QSizeProperty.cpp 
	script/generated_cpp/tulip_script/qtscriptshell_QStringProperty.cpp 
	script/generated_cpp/tulip_script/tulip_script_init.cpp
	script/generated_cpp/tulip_script/plugin.cpp)

##----------------------------------------------------------------------------------------------------------------------------
    
set(ENGINE_SOURCES engine/QIterator.cpp 
    engine/QProperty.cpp 
    engine/QDoubleProperty.cpp 
    engine/QStringProperty.cpp 
    engine/QBooleanProperty.cpp 
    engine/QLayoutProperty.cpp
    engine/QIntegerProperty.cpp 
    engine/QColorProperty.cpp 
    engine/QSizeProperty.cpp 
    engine/QGraphProperty.cpp 
    engine/QGraph.cpp 
    engine/QNode.cpp 
    engine/QEdge.cpp 
    engine/QSize3D.cpp
    engine/QView.cpp
    engine/QControllerViewsManager.cpp
    engine/TulipScriptEngine.cpp
#     engine/TulipScriptEngineAgent.cpp
)

set(ENGINE_HEADERS engine/QIterator.h 
    engine/QProperty.h 
    engine/QDoubleProperty.h 
    engine/QStringProperty.h 
    engine/QBooleanProperty.h 
    engine/QLayoutProperty.h
    engine/QIntegerProperty.h 
    engine/QColorProperty.h 
    engine/QSizeProperty.h 
    engine/QGraphProperty.h
    engine/QView.h
    engine/QControllerViewsManager.h
    engine/QGraph.h 
    engine/QNode.h 
    engine/QEdge.h 
    engine/QSize3D.h
#    engine/TulipScriptEngine.h
)

QT4_WRAP_CPP(ENGINE_SOURCES_MOC ${ENGINE_HEADERS})
set(ENGINE_SOURCES ${ENGINE_SOURCES} ${ENGINE_SOURCES_MOC})

##----------------------------------------------------------------------------------------------------------------------------
set(EDITOR_SOURCES editor/ScriptInteractor.cpp 
    editor/scriptedit.cpp
    editor/scripthighlighter.cpp
    editor/tabsettings.cpp
    editor/textedit.cpp)

set(EDITOR_HEADERS editor/editor.h
    editor/scriptedit.h
    editor/scripthighlighter.h
    editor/textedit.h)

QT4_WRAP_CPP(EDITOR_SOURCES_MOC ${EDITOR_HEADERS})
set(EDITOR_SOURCES ${EDITOR_SOURCES} ${EDITOR_SOURCES_MOC})

##----------------------------------------------------------------------------------------------------------------------------
set(TRANSLATER_SOURCES translater/Translater.cpp)

##----------------------------------------------------------------------------------------------------------------------------
add_library(script_plugin-${TULIP_VERSION} SHARED editor/editor.cpp ${EDITOR_SOURCES} ${TRANSLATER_SOURCES} ${SCRIPT_SOURCES} ${ENGINE_SOURCES})

set(QTSCRIPTLIBS /home/packadal/src/qtscriptgenerator/plugins/script/libqtscript_core.a
		/home/packadal/src/qtscriptgenerator/plugins/script/libqtscript_gui.a
		/home/packadal/src/qtscriptgenerator/plugins/script/libqtscript_network.a)

target_link_libraries(script_plugin-${TULIP_VERSION} ${TULIP} ${QTSCRIPTLIBS} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTSCRIPT_LIBRARY} ${QT_QTSCRIPTTOOLS_LIBRARY})

##----------------------------------------------------------------------------------------------------------------------------
SET(TESTS_SOURCES 
  unit_test/AddEdgeTest.cpp
  unit_test/AddNodeTest.cpp
  unit_test/EdgeIterationTest.cpp
  unit_test/NodeIterationTest.cpp
  unit_test/QGraphTest.cpp
  unit_test/QPropertyTest.cpp
  unit_test/SaveGraphTest.cpp
  unit_test/GraphCreateTest.cpp
  unit_test/testRunner.cpp)

# add_executable(unitTests ${TESTS_SOURCES})
# target_link_libraries(unitTests script_plugin-${TulipVersion} cppunit ${LibTulipName} ${LibTulipQtName} ${QTSCRIPTLIBS})
# add_executable(editor_test editor/main.cpp)
# target_link_libraries(editor_test script_editor ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTSCRIPT_LIBRARY} ${TULIP} ${QTSCRIPTLIBS})

INSTALL(TARGETS script_plugin-${TULIP_VERSION}
	DESTINATION ${CMAKE_INSTALL_PREFIX}${TulipLibInstallDir}/lib/tlp/)