#define GENERATE_GET_MIN_MAX(NAME, EDGE_TYPE, NODE_TYPE) \
NODE_TYPE getNodeMin() { return _property->getNodeMin(); }\
NODE_TYPE getNodeMax() { return _property->getNodeMax(); }\
EDGE_TYPE getEdgeMin() { return _property->getEdgeMin(); }\
EDGE_TYPE getEdgeMax() { return _property->getEdgeMax(); }\

#define GENERATE_CLASS(NAME) \
class Q##NAME##Property: public QProperty\
{\
\
Q_OBJECT \
\
public:\
\
	Q##NAME##Property(QGraph *g) {_property = new tlp::NAME##Property(g->asGraph()); }\
	Q##NAME##Property(tlp::NAME##Property* p):_property(p) {} \
	virtual ~Q##NAME##Property() { delete _property; }\
	tlp::NAME##Property* asProperty() { return _property; }\
\
public slots:\


#define GENERATE_CLASS_TAIL(NAME) \
private:\
\
	tlp::NAME##Property* _property;\
\
};

#define GENERATE_GET_SET_NODE(NAME, TYPE) \
TYPE getNodeDefaultValue() { return AS_RETURN_NODE(_property->getNodeDefaultValue()); }\
TYPE getNodeValue(const QNode* n) { return AS_RETURN_NODE(_property->getNodeValue(n->asNode())); }\
void setNodeValue(const QNode* n, TYPE v) { _property->setNodeValue(n->asNode(), AS_ARG(v)); }\
void setAllNodeValue(TYPE v) { _property->setAllNodeValue(AS_ARG(v)); }\

#define GENERATE_GET_SET_EDGE(NAME, TYPE) \
TYPE getEdgeDefaultValue() { return AS_RETURN_EDGE(_property->getEdgeDefaultValue()); }\
TYPE getEdgeValue(const QEdge* e) { return AS_RETURN_EDGE(_property->getEdgeValue(e->asEdge())); }\
void setEdgeValue(const QEdge* e, TYPE v) { _property->setEdgeValue(e->asEdge(), AS_ARG(v)); }\
void setAllEdgeValue(TYPE v) { _property->setAllEdgeValue(AS_ARG(v)); }\

#define GENERATE_PROPERTY(NAME, EDGE_TYPE, NODE_TYPE) \
\
GENERATE_CLASS(NAME) \
GENERATE_GET_SET_NODE(NAME, NODE_TYPE) \
GENERATE_GET_SET_EDGE(NAME, EDGE_TYPE) \
\
GENERATE_GET_MIN_MAX(NAME, EDGE_TYPE, NODE_TYPE) \
\
GENERATE_CLASS_TAIL(NAME)

#define GENERATE_SIMPLE_PROPERTY(NAME, EDGE_TYPE, NODE_TYPE) \
\
GENERATE_CLASS(NAME) \
GENERATE_GET_SET_NODE(NAME, NODE_TYPE) \
GENERATE_GET_SET_EDGE(NAME, EDGE_TYPE) \
\
GENERATE_CLASS_TAIL(NAME)

#define GENERATE_OBJECT_PROPERTY(NAME, EDGE_TYPE, NODE_TYPE) \
\
GENERATE_CLASS(NAME) \
GENERATE_GET_SET_NODE(NAME, NODE_TYPE) \
GENERATE_GET_SET_EDGE(NAME, EDGE_TYPE) \
GENERATE_GET_MIN_MAX(NAME, EDGE_TYPE, NODE_TYPE) \
\
GENERATE_CLASS_TAIL(NAME)

#include "QProperty.h"
#include "QGraph.h"
#include "QNode.h"
#include "QEdge.h"
#include "QSize3D.h"
#include "QStdSet.h"

#include <tulip/IntegerProperty.h>
#include <tulip/DoubleProperty.h>
#include <tulip/BooleanProperty.h>
#include <tulip/SizeProperty.h>

#include <QtGui/QColor>
#include <QtCore/QSet>

#define AS_ARG(ARG) ARG
#define AS_RETURN(RET) RET
#define AS_RETURN_EDGE(RET) AS_RETURN(RET)
#define AS_RETURN_NODE(RET) AS_RETURN(RET)

GENERATE_PROPERTY(Integer, int, int)
GENERATE_PROPERTY(Double, double, double)
GENERATE_SIMPLE_PROPERTY(Boolean, bool, bool)

#undef AS_ARG
#define AS_ARG(ARG) ARG->asSize3D()
#undef AS_RETURN_NODE
#define AS_RETURN_NODE(RET) new QSize3D(RET)
#undef AS_RETURN_EDGE
#define AS_RETURN_EDGE(RET) new QSize3DVector(RET)
QSTDVECTOR(Size3D, tlp::Coord);
GENERATE_SIMPLE_PROPERTY(Layout, QSize3DVector*, QSize3D*)

#undef AS_ARG
#define AS_ARG(ARG) ARG->asGraph()
#undef AS_RETURN_NODE
#define AS_RETURN_NODE(RET) new QGraph(RET)
#undef AS_RETURN_EDGE
#define AS_RETURN_EDGE(RET) new QEdgeSet(RET)
QSTDSET(Edge, tlp::edge);
GENERATE_SIMPLE_PROPERTY(Graph, QEdgeSet*, QGraph*)
#undef AS_RETURN_NODE
#define AS_RETURN_NODE(RET) AS_RETURN(RET)
#undef AS_RETURN_EDGE
#define AS_RETURN_EDGE(RET) AS_RETURN(RET)

#undef AS_ARG
#define AS_ARG(ARG) ARG.toStdString()
#undef AS_RETURN
#define AS_RETURN(RET) QString::fromStdString(RET)
GENERATE_SIMPLE_PROPERTY(String, QString, QString)

#undef AS_ARG
#define AS_ARG(ARG) tlp::Color(ARG.red(), ARG.green(), ARG.blue(), ARG.alpha())
#undef AS_RETURN
#define AS_RETURN(RET) QColor(RET.getR(), RET.getG(), RET.getB(), RET.getA())
GENERATE_SIMPLE_PROPERTY(Color, QColor, QColor)

#undef AS_ARG
#define AS_ARG(ARG) tlp::Size(ARG.getW(), ARG.getH(), ARG.getD())
#undef AS_RETURN
#define AS_RETURN(RET) QSize3D(RET)
GENERATE_SIMPLE_PROPERTY(Size, QSize3D, QSize3D)
