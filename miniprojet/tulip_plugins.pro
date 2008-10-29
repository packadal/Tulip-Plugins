TEMPLATE = app
TARGET = tulip_plugins
QT += core \
    gui \
    script
HEADERS += CurveGroup.h \
    Data.h \
    Graphic.h \
    HistogramGroup.h \
    IData.h \
    IModel.h \
    Model.h \
    Observable.h \
    Observer.h \
    QGraphic.h \
    Viewer.h \
    tests/CurveWidgetTest.h \
    tests/DataTest.h \
    tests/GraphicsWidgetTest.h \
    tests/ScriptWidgetTest.h \
    tests/ModelTest.h
SOURCES += CurveGroup.cpp \
    Data.cpp \
    HistogramGroup.cpp \
    Model.cpp \
    Observable.cpp \
    Observer.cpp \
    Viewer.cpp \
    tests/CurveWidgetTest.cpp \
    tests/DataTest.cpp \
    tests/GraphicsWidgetTest.cpp \
    tests/ScriptWidgetTest.cpp \
    tests/ModelTest.cpp \
    tests/testObserver.cpp \
    tests/testRunner.cpp
RESOURCES += 
LIBS += -L/net/cremi/chuet/liens/cppunit/lib
LIBS += -lcppunit
INCLUDEPATH += /net/cremi/chuet/liens/cppunit/include
INCLUDEPATH += /usr/include/c++/4.2
INCLUDEPATH += /usr/include/c++/4.2/backward
