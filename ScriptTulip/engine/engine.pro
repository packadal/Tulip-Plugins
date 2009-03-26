TARGET = tulip-script
QT += script
include(../variables.pri)
QMAKE_CXXFLAGS += -Wno-deprecated
INCLUDEPATH += $$QTSCRIPT_GENERATOR_PATH/qtbindings/qtscript_core
CONFIG += static


CONFIG(tests) { 
    TEMPLATE = app
    message("DEBUG MOOOODE !!!")
}
else { 
    TEMPLATE = lib
    message("RELEASE MODE :)")
}

HEADERS += QStdSet.h \
    $$ENGINE_HEADERS
    
SOURCES += $$ENGINE_SOURCES

CONFIG(tests) { 
    CPPUNIT_PATH = /net/cremi/chuet/liens/cppunit/lib
    SOURCES += test/GraphCreateTest.cpp \
        test/QGraphTest.cpp \
        test/QPropertyTest.cpp \
        test/AddEdgeTest.cpp \
        test/LoadGraphTest.cpp \
        test/AddNodeTest.cpp \
        test/testRunner.cpp \
        test/EdgeIterationTest.cpp \
        test/NodeIterationTest.cpp \
        test/SaveGraphTest.cpp
    HEADERS += test/utilsTest.h \
        test/LoadGraphTest.h \
        test/AddEdgeTest.h \
        test/AddNodeTest.h \
        test/GraphCreateTest.h \
        test/SaveGraphTest.h \
        test/TestSkeleton.h
    LIBS += -L$$CPPUNIT_PATH \
        -lcppunit \
        -L$$TULIP_PATH/lib \
        -ltulip \
        -L$$SCRIPT_PATH \
        -lqtscript_tulip_script \
        -L$$QTSCRIPT_GENERATOR_PATH/plugins/static \
        -lqtscript_gui \
        -lqtscript_core
    INCLUDEPATH += $$CPPUNIT_PATH/include
}
