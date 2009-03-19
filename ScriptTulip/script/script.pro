TEMPLATE = lib

QT += script

TARGET = qtscript_tulip_script
#CONFIG += plugin static
#DEFINES += QT_STATICPLUGIN

include(../variables.pri)

include (generated_cpp/tulip_script/tulip_script.pri)

HEADERS += $$ENGINE_PATH/TulipScriptEngine.h \ 
    $$ENGINE_PATH/QIterator.h \
    $$ENGINE_PATH/QProperty.h \
    $$ENGINE_PATH/QGraph.h \
    $$ENGINE_PATH/QNode.h \
    $$ENGINE_PATH/QEdge.h \

SOURCES += $$ENGINE_PATH/TulipScriptEngine.cpp \ 
    $$ENGINE_PATH/QIterator.cpp \
    $$ENGINE_PATH/QProperty.cpp \
    $$ENGINE_PATH/QGraph.cpp \
    $$ENGINE_PATH/QNode.cpp \
    $$ENGINE_PATH/QEdge.cpp \
    generated_cpp/tulip_script/main.cpp 
    
    LIBS += -L$$TULIP_PATH/lib \
    -ltulip

INCLUDEPATH += $$TULIP_PATH/library/tulip/include \
	$$ENGINE_PATH
