TEMPLATE = app
TARGET = tulip_plugins
QT += core \
    gui \
    script
HEADERS += QData.h \
    tests/CurveWidgetTest.h \
    tests/DataTest.h \
    tests/GraphicsWidgetTest.h \
    tests/ModelTest.h \
    tests/ScriptWidgetTest.h \
    ScriptViewer.h \
    CurveGroup.h \
    Data.h \
    Graphic.h \
    HistogramGroup.h \
    IData.h \
    IModel.h \
    Model.h \
    Observable.h \
    Observer.h \
    QGraphic.h \
    Viewer.h
SOURCES += tests/CurveWidgetTest.cpp \
    tests/DataTest.cpp \
    tests/GraphicsWidgetTest.cpp \
    tests/ModelTest.cpp \
    tests/ScriptWidgetTest.cpp \
   	tests/testObserver.cpp \
   	tests/testRunner.cpp \
    ScriptViewer.cpp \
    CurveGroup.cpp \
    HistogramGroup.cpp \
    Model.cpp \
    Observable.cpp \
    Observer.cpp \
    Viewer.cpp
RESOURCES += 
LIBS += -L/net/cremi/chuet/liens/cppunit/lib
LIBS += -lcppunit
INCLUDEPATH += /net/cremi/chuet/liens/cppunit/include
FORMS += ScriptViewer.ui
