ENGINE_PATH = $$PWD/engine
SCRIPT_PATH = $$PWD/script
JAMBI_PATH =  $$PWD/jambi
EDITOR_PATH = $$PWD/editor

ROOT_DIR=$$PWD

TULIP_PATH=/home/packadal/temp/auber
QTSCRIPT_GENERATOR_PATH=/var/lib/QT4/qtscriptgenerator/
QTSCRIPT_GENERATOR=$$QTSCRIPT_GENERATOR_PATH/generator/generator
JAMBI_GENERATOR_PATH=/var/lib/QT4/qtjambi/generator
QTDIR_VAR=/var/lib/QT4/qt

INCLUDEPATH += $$TULIP_PATH/library/tulip/include
INCLUDEPATH += $$TULIP_PATH/include

QMAKE_CXXFLAGS += -Wno-deprecated
