TEMPLATE = app
TARGET = editor
QT += core \
    gui \
    script
SOURCES += editor.cpp \
    main.cpp \
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
INCLUDEPATH += ../
LIBS += -L../ \
    -lScriptTulip
