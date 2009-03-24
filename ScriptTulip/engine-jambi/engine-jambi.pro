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
    $$ENGINE_PATH/QEdge.h \
    $$ENGINE_PATH/QDoubleProperty.h \
    $$ENGINE_PATH/QStringProperty.h \
    $$ENGINE_PATH/QBooleanProperty.h \
    $$ENGINE_PATH/QLayoutProperty.h \
    $$ENGINE_PATH/QIntegerProperty.h \
    $$ENGINE_PATH/QColorProperty.h \
    $$ENGINE_PATH/QSizeProperty.h \
    $$ENGINE_PATH/QGraphProperty.h
    
SOURCES += $$ENGINE_PATH/QIterator.cpp \
    $$ENGINE_PATH/QSize3D.cpp \    
    $$ENGINE_PATH/QProperty.cpp \
    $$ENGINE_PATH/QGraph.cpp \
    $$ENGINE_PATH/QNode.cpp \
    $$ENGINE_PATH/QEdge.cpp \
    $$ENGINE_PATH/QDoubleProperty.cpp \
    $$ENGINE_PATH/QStringProperty.cpp \
    $$ENGINE_PATH/QBooleanProperty.cpp \
    $$ENGINE_PATH/QLayoutProperty.cpp \
    $$ENGINE_PATH/QIntegerProperty.cpp \
    $$ENGINE_PATH/QColorProperty.cpp \
    $$ENGINE_PATH/QSizeProperty.cpp \
    $$ENGINE_PATH/QGraphProperty.cpp
