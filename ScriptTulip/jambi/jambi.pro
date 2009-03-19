TEMPLATE=subdirs

include(../variables.pri)

message(QTDIR=$$QTDIR_VAR PATH=$$JAMBI_GENERATOR_PATH:$PATH ant)

message(QTDIR=$$QTDIR_VAR PATH=$$JAMBI_GENERATOR_PATH:$PATH ant)

!system(QTDIR=$$QTDIR_VAR PATH=$$JAMBI_GENERATOR_PATH:$PATH ant) {
    error(unable to run the qtJambi Generator !)
}
