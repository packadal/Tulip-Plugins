TEMPLATE=subdirs

TULIP_PLUGINS_SOURCE_ROOT=$$PWD

include(variables.pri)

CONFIG += ordered

!system(QTDIR=$$QTDIR_VAR $$GENERATOR $$SCRIPT_PATH/global.h $$SCRIPT_PATH/typesystem.xml --output-directory=script) {
    error(unable to run the qtScript Generator !)
}

SUBDIRS = engine \
	  editor \
	  script \
	  jambi
