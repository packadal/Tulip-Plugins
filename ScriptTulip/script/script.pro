TEMPLATE = lib

QT += script

TARGET = qtscript_tulip_script
CONFIG += static
#DEFINES += QT_STATICPLUGIN

include(../variables.pri)

include (generated_cpp/tulip_script/tulip_script.pri)

HEADERS += $$ENGINE_PATH/TulipScriptEngine.h \ 
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
    $$ENGINE_PATH/QGraphProperty.h \
    $$ENGINE_PATH/QSize3D.h

SOURCES += $$ENGINE_PATH/TulipScriptEngine.cpp \ 
    $$ENGINE_PATH/QIterator.cpp \
    $$ENGINE_PATH/QProperty.cpp \
    $$ENGINE_PATH/QDoubleProperty.cpp \
    $$ENGINE_PATH/QStringProperty.cpp \
    $$ENGINE_PATH/QBooleanProperty.cpp \
    $$ENGINE_PATH/QLayoutProperty.cpp \
    $$ENGINE_PATH/QIntegerProperty.cpp \
    $$ENGINE_PATH/QColorProperty.cpp \
    $$ENGINE_PATH/QSizeProperty.cpp \
    $$ENGINE_PATH/QGraphProperty.cpp \
    $$ENGINE_PATH/QGraph.cpp \
    $$ENGINE_PATH/QNode.cpp \
    $$ENGINE_PATH/QEdge.cpp \
    $$ENGINE_PATH/QSize3D.cpp \
    generated_cpp/tulip_script/plugin.cpp 
    
#LIBS += -L$$TULIP_PATH/lib \
#    -ltulip

INCLUDEPATH += $$TULIP_PATH/library/tulip/include \
    $$TULIP_PATH/include \
	$$ENGINE_PATH
