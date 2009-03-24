TEMPLATE = lib

TARGET = com_tulip_jambi

include(../variables.pri)

DEFINES += JAMBI_BUILD

HEADERS += $$ENGINE_PATH/QIterator.h \
    $$ENGINE_PATH/QProperty.h \
    $$ENGINE_PATH/QGraph.h \
    $$ENGINE_PATH/QNode.h \
    $$ENGINE_PATH/QEdge.h \
    #    $$ENGINE_PATH/QTemplateProperty.cpp \

SOURCES += $$ENGINE_PATH/QIterator.cpp \
    $$ENGINE_PATH/QProperty.cpp \
    $$ENGINE_PATH/QGraph.cpp \
    $$ENGINE_PATH/QNode.cpp \
    $$ENGINE_PATH/QEdge.cpp \
    #   $$ENGINE_PATH/QTemplateProperty.cpp 
    
LIBS += -L$$TULIP_PATH/lib \
    -ltulip

INCLUDEPATH += $$TULIP_PATH/library/tulip/include \
    $$ENGINE_PATH

include (cpp/com_tulip_jambi/com_tulip_jambi.pri)
include ($$JAMBI_PATH/qtjambi/qtjambi_include.pri)