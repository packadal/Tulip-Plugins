ENGINE_PATH = $$PWD/engine
SCRIPT_PATH = $$PWD/script
JAMBI_PATH =  $$PWD/jambi
EDITOR_PATH = $$PWD/editor
TRANSLATER_PATH = $$PWD/translater

ROOT_DIR=$$PWD

TULIP_PATH=/home/packadal/tulip
QTSCRIPT_GENERATOR_PATH=/home/packadal/src/qtscriptgenerator
QTSCRIPT_GENERATOR=$$QTSCRIPT_GENERATOR_PATH/generator/generator

#JAMBI_PATH=/net/travail/uti/chuet/qtjambi/
#JAMBI_GENERATOR_PATH=$$JAMBI_PATH/generator
QTDIR_VAR=/usr/share/qt4

INCLUDEPATH += /home/packadal/src/tulip/library/tulip/include
INCLUDEPATH += /home/packadal/src/tulip/library/tulip-qt/include
INCLUDEPATH += /home/packadal/src/tulip/build/library/tulip/include

TULIP_VERSION = $$system($$TULIP_PATH/bin/tulip-config --version)

QMAKE_CXXFLAGS += -Wno-deprecated
CONFIG(debug) {
	QMAKE_CXXFLAGS += -g
} 

ENGINE_HEADERS = $$ENGINE_PATH/QIterator.h \
    $$ENGINE_PATH/QProperty.h \
    $$ENGINE_PATH/QGraph.h \
    $$ENGINE_PATH/QNode.h \
    $$ENGINE_PATH/QEdge.h \
    $$ENGINE_PATH/QDoubleProperty.h \
    $$ENGINE_PATH/QStringProperty.h \
    $$ENGINE_PATH/QBooleanProperty.h \
    #$$ENGINE_PATH/QLayoutProperty.h \
    $$ENGINE_PATH/QIntegerProperty.h \
    $$ENGINE_PATH/QColorProperty.h \
    $$ENGINE_PATH/QSizeProperty.h \
    $$ENGINE_PATH/QGraphProperty.h \
    $$ENGINE_PATH/QSize3D.h
    
ENGINE_SOURCES = $$ENGINE_PATH/QIterator.cpp \
    $$ENGINE_PATH/QProperty.cpp \
    $$ENGINE_PATH/QDoubleProperty.cpp \
    $$ENGINE_PATH/QStringProperty.cpp \
    $$ENGINE_PATH/QBooleanProperty.cpp \
    #$$ENGINE_PATH/QLayoutProperty.cpp \
    $$ENGINE_PATH/QIntegerProperty.cpp \
    $$ENGINE_PATH/QColorProperty.cpp \
    $$ENGINE_PATH/QSizeProperty.cpp \
    $$ENGINE_PATH/QGraphProperty.cpp \
    $$ENGINE_PATH/QGraph.cpp \
    $$ENGINE_PATH/QNode.cpp \
    $$ENGINE_PATH/QEdge.cpp \
    $$ENGINE_PATH/QSize3D.cpp 
