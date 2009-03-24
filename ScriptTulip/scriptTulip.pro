TEMPLATE=subdirs

TULIP_PLUGINS_SOURCE_ROOT=$$PWD

include(variables.pri)

!system(QTDIR=$$QTDIR_VAR $$QTSCRIPT_GENERATOR $$SCRIPT_PATH/global.h $$SCRIPT_PATH/typesystem.xml --output-directory=script) {
    error(unable to run the qtScript Generator !)
}
CONFIG += ordered
SUBDIRS += engine \
    script \
    editor \
    engine-jambi \
    jambi \


