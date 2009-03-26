TEMPLATE = lib

QT += script

TARGET = qtscript_tulip_script
CONFIG += static
#DEFINES += QT_STATICPLUGIN

include(../variables.pri)

include (generated_cpp/tulip_script/tulip_script.pri)

HEADERS += $$ENGINE_PATH/TulipScriptEngine.h \ 
    $$ENGINE_HEADERS

SOURCES += $$ENGINE_PATH/TulipScriptEngine.cpp \ 
    $$ENGINE_SOURCES \
    generated_cpp/tulip_script/plugin.cpp 
    
#LIBS += -L$$TULIP_PATH/lib \
#    -ltulip

INCLUDEPATH += $$TULIP_PATH/library/tulip/include \
    $$TULIP_PATH/include \
	$$ENGINE_PATH
