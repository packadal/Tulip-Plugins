TEMPLATE=app
TARGET=scriptTulip-tests
include(../variables.pri)

QT += script

CPPUNIT_PATH = /net/cremi/chuet/liens/cppunit
INCLUDEPATH += $$CPPUNIT_PATH/include \
    $$ENGINE_PATH

SOURCES += GraphCreateTest.cpp \
    QGraphTest.cpp \
    QPropertyTest.cpp \
    AddEdgeTest.cpp \
    LoadGraphTest.cpp \
    AddNodeTest.cpp \
    testRunner.cpp \
    EdgeIterationTest.cpp \
    NodeIterationTest.cpp \
    SaveGraphTest.cpp
    
HEADERS += utilsTest.h \
    LoadGraphTest.h \
    AddEdgeTest.h \
    AddNodeTest.h \
    GraphCreateTest.h \
    SaveGraphTest.h \
    TestSkeleton.h
    
LIBS += -L$$CPPUNIT_PATH/lib \
    -lcppunit \
    -L$$TULIP_PATH/lib \
    -ltulip-3.4 \
    -L$$SCRIPT_PATH \
    -lqtscript_tulip_script \
    -L$$QTSCRIPT_GENERATOR_PATH/plugins/script \
    #-L$$QTSCRIPT_GENERATOR_PATH/plugins/static \
    -lqtscript_gui \
    -lqtscript_core
