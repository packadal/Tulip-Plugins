TEMPLATE = lib
TARGET = editor-3.1.0
QT += core \
    gui \
    script
    
CONFIG += dll
DEPENDPATH += .
    
SOURCES += editor.cpp \
    #main.cpp \
    scriptedit.cpp \
    scripthighlighter.cpp \
    tabsettings.cpp \
    textedit.cpp
HEADERS += editor.h \
    scriptedit.h \
    scripthighlighter.h \
    tabsettings.h \
    textedit.h \
    editor.h \
    scriptedit.h \
    scripthighlighter.h \
    tabsettings.h \
    textedit.h \
    scripthighlighter.h \
    textedit.h \
    tabsettings.h \
    scriptedit.h

INCLUDEPATH += ../ \
 /net/cremi/dmothes/tulipBin/include 
  
LIBS += -L.. \
	-L/net/cremi/dmothes/tulipBin/lib \
	-ltulip-script \
	-ltulip \
	-ltulip-ogl \
	-ltulip-pluginsmanager \
	-ltulip-qt4