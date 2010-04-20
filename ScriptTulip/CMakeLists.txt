project(Tulip-Plugins)

cmake_minimum_required(VERSION 2.8)

set(ENGINE_PATH ${CMAKE_SOURCE_DIR}/engine)
set(SCRIPT_PATH = ${CMAKE_SOURCE_DIR}/script)
set(JAMBI_PATH =  ${CMAKE_SOURCE_DIR}/jambi)
set(EDITOR_PATH = ${CMAKE_SOURCE_DIR}/editor)
set(TRANSLATER_PATH = ${CMAKE_SOURCE_DIR}/translater)

#set(TULIP_PATH=/home/packadal/tulip)
#set(QTSCRIPT_GENERATOR_PATH=/home/packadal/src/qtscriptgenerator)
#set(QTSCRIPT_GENERATOR=${QTSCRIPT_GENERATOR_PATH}/generator/generator)

#JAMBI_PATH=/net/travail/uti/chuet/qtjambi/
#JAMBI_GENERATOR_PATH=$$JAMBI_PATH/generator
#QTDIR_VAR=/usr/share/qt4

include_directories(/home/packadal/src/tulip/library/tulip/include
		    /home/packadal/src/tulip/library/tulip-qt/include
		    /home/packadal/src/tulip/build/library/tulip/include)
set(TULIP_VERSION 2.6)

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
