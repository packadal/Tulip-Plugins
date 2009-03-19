TARGET = tulip-script
QT += script

include(../variables.pri)
QMAKE_CXXFLAGS += -Wno-deprecated

CONFIG(tests) { 
    TEMPLATE = app
    message("DEBUG MOOOODE !!!")
}
else { 
    TEMPLATE = lib
    message("RELEASE MODE :)")
}

HEADERS += QStdSet.h \
    QSize3D.h \    
    QIterator.h \    
    QProperty.h \
    TulipScriptEngine.h \
    QGraph.h \
    QNode.h \
    QEdge.h
SOURCES += QIterator.cpp \
    QProperty.cpp \
    TulipScriptEngine.cpp \
    QGraph.cpp \
    QNode.cpp \
    QEdge.cpp

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
        -lcppunit

    INCLUDEPATH += $$CPPUNIT_PATH/include

}
LIBS += -L$$TULIP_PATH/lib \
    -ltulip
    
LIBS += -L./script