TARGET = tulip-script
QT += script

include(../variables.pri)
QMAKE_CXXFLAGS += -Wno-deprecated

INCLUDEPATH += $$QTSCRIPT_GENERATOR_PATH/qtbindings/qtscript_core

CONFIG += static
DEFINES += JAMBI_BUILD
TEMPLATE = lib


HEADERS += $$ENGINE_PATH/QStdSet.h \
    $$ENGINE_PATH/QSize3D.h \    
    $$ENGINE_PATH/QIterator.h \    
    $$ENGINE_PATH/QProperty.h \
    $$ENGINE_PATH/QGraph.h \
    $$ENGINE_PATH/QNode.h \
    $$ENGINE_PATH/QEdge.h
SOURCES += $$ENGINE_PATH/QIterator.cpp \
    $$ENGINE_PATH/QProperty.cpp \
    $$ENGINE_PATH/QGraph.cpp \
    $$ENGINE_PATH/QNode.cpp \
    $$ENGINE_PATH/QEdge.cpp
