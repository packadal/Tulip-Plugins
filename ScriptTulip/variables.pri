ENGINE_PATH = $$PWD/engine
SCRIPT_PATH = $$PWD/script
JAMBI_PATH =  $$PWD/jambi
EDITOR_PATH = $$PWD/editor

TULIP_PATH=/home/packadal/temp/auber
GENERATOR=/var/lib/QT4/qtscriptgenerator/generator/generator
QTDIR_VAR=/var/lib/QT4/qt-4.4.3

INCLUDEPATH += $$TULIP_PATH/library/tulip/include
INCLUDEPATH += $$TULIP_PATH/include

QMAKE_CXXFLAGS += -Wno-deprecated
