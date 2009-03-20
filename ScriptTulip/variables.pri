ENGINE_PATH = $$PWD/engine
SCRIPT_PATH = $$PWD/script
JAMBI_PATH =  $$PWD/jambi
EDITOR_PATH = $$PWD/editor
TRANSLATER_PATH = $$PWD/translater

ROOT_DIR=$$PWD

TULIP_PATH=/net/cremi/dmothes/tulipBin/
QTSCRIPT_GENERATOR_PATH=/net/cremi/chuet/liens/travail/qtscriptgenerator/
QTSCRIPT_GENERATOR=$$QTSCRIPT_GENERATOR_PATH/generator/generator
JAMBI_GENERATOR_PATH=/net/cremi/chuet/liens/travail/qtjambi/generator
QTDIR_VAR=/net/cremi/chuet/liens/travail/QT-4.5.0/

INCLUDEPATH += $$TULIP_PATH/library/tulip/include
INCLUDEPATH += $$TULIP_PATH/include

QMAKE_CXXFLAGS += -Wno-deprecated
