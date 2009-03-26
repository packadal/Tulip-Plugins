TARGET = tulip-script
QT += script

include(../variables.pri)
QMAKE_CXXFLAGS += -Wno-deprecated

INCLUDEPATH += $$QTSCRIPT_GENERATOR_PATH/qtbindings/qtscript_core

CONFIG += static
DEFINES += JAMBI_BUILD
TEMPLATE = lib


HEADERS += $$ENGINE_PATH/QStdSet.h \
    $$ENGINE_HEADERS
    
SOURCES += $$ENGINE_SOURCES
