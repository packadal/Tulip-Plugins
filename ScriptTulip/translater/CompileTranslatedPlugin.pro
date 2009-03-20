TEMPLATE = app
TARGET = Plug
QT += core \
    gui \
    script
HEADERS += QIterator.h \
    QEdge.h \
    QGraph.h \
    QProperty.h \
    QNode.h
    
SOURCES += script.txt.cpp
    
LIBS += -L/net/cremi/dmothes/tulipBin/lib
LIBS += -L/net/cremi/rnappee/root/lib
LIBS += -L.

# FORMS +=
# RESOURCES +=
# LIBS += -L/net/cremi/chuet/liens/travail/
LIBS += -lcppunit \
    -ltulip -lScriptTulip
INCLUDEPATH += /net/cremi/dmothes/tulipBin/include
