TEMPLATE = lib

TARGET = com_tulip_jambi

include(../variables.pri)

DEFINES += JAMBI_BUILD

HEADERS += $$ENGINE_HEADERS

SOURCES += $$ENGINE_SOURCES
    
LIBS += -L$$TULIP_PATH/lib \
    -ltulip

INCLUDEPATH += $$TULIP_PATH/library/tulip/include \
    $$ENGINE_PATH

include (cpp/com_tulip_jambi/com_tulip_jambi.pri)
include ($$JAMBI_PATH/qtjambi/qtjambi_include.pri)