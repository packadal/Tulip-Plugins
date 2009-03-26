ENGINE_PATH = $$PWD/engine
SCRIPT_PATH = $$PWD/script
JAMBI_PATH =  $$PWD/jambi
EDITOR_PATH = $$PWD/editor
TRANSLATER_PATH = $$PWD/translater

ROOT_DIR=$$PWD

TULIP_PATH=/net/cremi/dmothes/tulipBin/
QTSCRIPT_GENERATOR_PATH=/net/travail/uti/chuet/qtscriptgenerator/
QTSCRIPT_GENERATOR=$$QTSCRIPT_GENERATOR_PATH/generator/generator

JAMBI_PATH=/net/travail/uti/chuet/qtjambi/
JAMBI_GENERATOR_PATH=$$JAMBI_PATH/generator
QTDIR_VAR=/net/travail/uti/chuet/QT-4.5.0/

INCLUDEPATH += $$TULIP_PATH/library/tulip/include
INCLUDEPATH += $$TULIP_PATH/include

TULIP_VERSION = $$system($$TULIP_PATH/bin/tulip-config --version)

QMAKE_CXXFLAGS += -Wno-deprecated
CONFIG(debug) {
	QMAKE_CXXFLAGS += -g
} 
