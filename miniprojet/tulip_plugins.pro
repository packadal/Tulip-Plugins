TARGET = tulip_plugins

CONFIG += qt debug
CONFIG -= release

QT += core \
    gui \
    script
    
HEADERS += tests/ScriptChangeGraphicTest.h \
    tests/HistogramWidgetTest.h \
    tests/CurveWidgetTest.h \
    tests/AddDeleteTest.h \
    tests/ColorGraphicTest.h \
    tests/GraphicLegendTest.h \
    tests/DataTest.h \
    tests/ModelTest.h \
    tests/ScriptWidgetTest.h \
    QData.h \
    Application.h \
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
    Viewer.h \
    Axis.h
SOURCES += Axis.cpp \
    CurveGroup.cpp \
    HistogramGroup.cpp \
    Model.cpp \
    Observable.cpp \
    Observer.cpp \
    ScriptViewer.cpp \
    Viewer.cpp

debug {
	SOURCES += tests/testRunner.cpp \
	tests/ScriptChangeGraphicTest.cpp \
    tests/HistogramWidgetTest.cpp \
    tests/CurveWidgetTest.cpp \
    tests/GraphicLegendTest.cpp \
    tests/DataTest.cpp \
    tests/ModelTest.cpp \
    tests/ScriptWidgetTest.cpp \
    tests/testObserver.cpp \
    tests/AddDeleteTest.cpp \
    tests/ColorGraphicTest.cpp
}

release {
	SOURCES += Application.cpp
}
    
#RESOURCES += 

LIBS += -L/net/cremi/chuet/liens/travail/QT-4.4.3 \
		-L/net/cremi/chuet/liens/cppunit/lib 
LIBS += -lcppunit
INCLUDEPATH += /net/cremi/chuet/liens/travail/QT-4.4.3/include \
				/net/cremi/chuet/liens/cppunit/include
FORMS += ScriptViewer.ui 
