TARGET = tulip-script
QT += script
include(../variables.pri)
QMAKE_CXXFLAGS += -Wno-deprecated
INCLUDEPATH += $$QTSCRIPT_GENERATOR_PATH/qtbindings/qtscript_core
CONFIG += static

CONFIG(tests) { 
    TEMPLATE = app
    message("DEBUG MOOOODE !!!")
}
else { 
    TEMPLATE = lib
    message("RELEASE MODE :)")
}

HEADERS += QStdSet.h \
    $$ENGINE_HEADERS
    
SOURCES += $$ENGINE_SOURCES

