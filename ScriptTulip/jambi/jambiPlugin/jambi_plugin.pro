TEMPLATE = lib

PATHES= $$find(CONFIG, (/[^\/]*)+ )
JAVA_FILE=$$find(CONFIG, [a-Z]*.java)
TULIP_PLUGINS_PATH =$$member(PATHES, 0) 
QTJAMBI_PATH=$$member(PATHES, 1)

JAVA_FILE=$$replace(JAVA_FILE, ".java", "")
TARGET=$$JAVA_FILE-3.1.2

#we include the variables defined in the variables.pri located in the tulipPluginsDir
include($$TULIP_PLUGINS_PATH/variables.pri)

SOURCES += jambi_plugin.cpp

#we add the java file name to the defines
DEFINES += JAVA_FILE=$$JAVA_FILE

LIBS += -L$$TULIP_PATH/lib \
    -L$$TULIP_PLUGINS_PATH/engine-jambi \
    -L$$QTJAMBI_PATH/lib \
    -L$(JAVA_HOME)/jre/lib/i386/client/ \
    -L$$ENGINE_PATH \
    -ltulip \
    -ljvm \
    -lqtjambi \
    -ltulip-script 

INCLUDEPATH += $$TULIP_PATH/library/tulip/include \
	$$ENGINE_PATH \
	$$QTJAMBI_PATH/include \
	$(JAVA_HOME)/include/ \
	$(JAVA_HOME)/include/linux/ \
	
