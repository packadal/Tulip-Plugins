TEMPLATE=subdirs

TULIP_PLUGINS_SOURCE_ROOT=$$PWD

include(variables.pri)

CONFIG += ordered

SUBDIRS = engine 

CONFIG(jambi) {
    message(Jambi build !)
    SUBDIRS += jambi
}
else {
    !system(QTDIR=$$QTDIR_VAR $$QTSCRIPT_GENERATOR $$SCRIPT_PATH/global.h $$SCRIPT_PATH/typesystem.xml --output-directory=script) {
        error(unable to run the qtScript Generator !)
    }
    message(script build !)
    SUBDIRS += script \
        editor
}


