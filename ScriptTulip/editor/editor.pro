TEMPLATE = lib
TARGET = Editor-3.1.2
QT += core \
    gui \
    script

include(../variables.pri)

#CONFIG += dll
#DEPENDPATH += .
   
HEADERS += editor.h \
    scriptedit.h \
    scripthighlighter.h \
    tabsettings.h \
    textedit.h \

SOURCES += editor.cpp \
    scriptedit.cpp \
    scripthighlighter.cpp \
    tabsettings.cpp \
    textedit.cpp

INCLUDEPATH += $$ENGINE_PATH \
    $$TULIP_PATH/library/tulip/include \
    $$TULIP_PATH/include 
  
LIBS += -L$$ENGINE_PATH \
    -ltulip-script \
    -L$$TULIP_PATH/lib \
    -ltulip \
    -ltulip-pluginsmanager \
    -ltulip-qt4 \
    -ltulip-ogl
    