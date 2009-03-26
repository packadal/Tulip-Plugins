include(../variables.pri)
TEMPLATE = lib
TARGET = Editor-$$TULIP_VERSION
QT += core \
    gui \
    script

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
    $$TULIP_PATH/include \
    $$TRANSLATER_PATH
  
LIBS += -L$$ENGINE_PATH \
		-L$$TRANSLATER_PATH \
    -ltulip-script \
    -L$$TULIP_PATH/lib \
    -ltulip \
    -ltulip-pluginsmanager \
    -ltulip-qt4 \
    -ltulip-ogl \
    -L$$TULIP_PATH/lib \
    -ltulip \
    -L$$SCRIPT_PATH \
    -lqtscript_tulip_script \
    -L$$QTSCRIPT_GENERATOR_PATH/plugins/static \
    -lqtscript_gui \
    -lqtscript_core \
    -L$$TRANSLATER_PATH \
    -ltranslater
