TEMPLATE = lib

CONFIG += static
include(../variables.pri)
TARGET = translater
QT += core \
    gui \
    script
HEADERS += Translater.h
SOURCES += Translater.cpp
LIBS += -L$$TULIP_PATH/lib
LIBS += -L$$QTDIR_VAR/lib
LIBS += -L$$ENGINE_PATH
LIBS += -ltulip \
    -ltulip-script
LIBS += -L$$QTSCRIPT_GENERATOR_PATH/plugins/static
LIBS += -lqtscript_gui
LIBS += -lqtscript_core
LIBS += -L$$SCRIPT_PATH
LIBS += -lqtscript_tulip_script
INCLUDEPATH += $$ENGINE_PATH
