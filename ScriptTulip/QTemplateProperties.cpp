#ifndef TEMPLATE_PROPERTIES_CPP
#define TEMPLATE_PROPERTIES_CPP

#include "QTemplateProperties.h"

#define AS_ARG(ARG) ARG
#define AS_ARG_EDGE(ARG) AS_ARG(ARG)
#define AS_ARG_NODE(ARG) AS_ARG(ARG)

#define AS_RETURN(RET) RET
#define AS_RETURN_EDGE(RET) RET
#define AS_RETURN_NODE(RET) RET

#define CLASS_NAME Integer
#define PROPERTY_NAME IntegerProperty
#define QPROPERTY_NAME QIntegerProperty
#define EDGE_TYPE int
#define NODE_TYPE int

QPROPERTY_NAME::QPROPERTY_NAME(QGraph *g):QProperty(new tlp::PROPERTY_NAME(g->asGraph())) { }
QPROPERTY_NAME::QPROPERTY_NAME(tlp::PROPERTY_NAME* p):QProperty(p) {}
QPROPERTY_NAME::~QPROPERTY_NAME() { delete _property; }


NODE_TYPE QPROPERTY_NAME::getNodeDefaultValue() { return AS_RETURN_NODE(_property->getNodeDefaultValue()); }
NODE_TYPE QPROPERTY_NAME::getNodeValue(const QNode* n) { return AS_RETURN_NODE(_property->getNodeValue(n->asNode())); }
void QPROPERTY_NAME::setNodeValue(const QNode* n, NODE_TYPE v) { _property->setNodeValue(n->asNode(), AS_ARG_NODE(v)); }
void QPROPERTY_NAME::setAllNodeValue(NODE_TYPE v) { _property->setAllNodeValue(AS_ARG_NODE(v)); }

EDGE_TYPE QPROPERTY_NAME::getEdgeDefaultValue() { return AS_RETURN_EDGE(_property->getEdgeDefaultValue()); }
EDGE_TYPE QPROPERTY_NAME::getEdgeValue(const QEdge* e) { return AS_RETURN_EDGE(_property->getEdgeValue(e->asEdge())); }
void QPROPERTY_NAME::setEdgeValue(const QEdge* e, EDGE_TYPE v) { _property->setEdgeValue(e->asEdge(), AS_ARG_EDGE(v)); }
void QPROPERTY_NAME::setAllEdgeValue(EDGE_TYPE v) { _property->setAllEdgeValue(AS_ARG_EDGE(v)); }

#ifndef SIMPLE
NODE_TYPE QPROPERTY_NAME::getNodeMin() { return _property->getNodeMin(); }
NODE_TYPE QPROPERTY_NAME::getNodeMax() { return _property->getNodeMax(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMin() { return _property->getEdgeMin(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMax() { return _property->getEdgeMax(); }
#endif

#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#define CLASS_NAME Double
#define PROPERTY_NAME DoubleProperty
#define QPROPERTY_NAME QDoubleProperty
#define EDGE_TYPE double
#define NODE_TYPE double

QPROPERTY_NAME::QPROPERTY_NAME(QGraph *g):QProperty(new tlp::PROPERTY_NAME(g->asGraph())) { }
QPROPERTY_NAME::QPROPERTY_NAME(tlp::PROPERTY_NAME* p):QProperty(p) {}
QPROPERTY_NAME::~QPROPERTY_NAME() { delete _property; }


NODE_TYPE QPROPERTY_NAME::getNodeDefaultValue() { return AS_RETURN_NODE(_property->getNodeDefaultValue()); }
NODE_TYPE QPROPERTY_NAME::getNodeValue(const QNode* n) { return AS_RETURN_NODE(_property->getNodeValue(n->asNode())); }
void QPROPERTY_NAME::setNodeValue(const QNode* n, NODE_TYPE v) { _property->setNodeValue(n->asNode(), AS_ARG_NODE(v)); }
void QPROPERTY_NAME::setAllNodeValue(NODE_TYPE v) { _property->setAllNodeValue(AS_ARG_NODE(v)); }

EDGE_TYPE QPROPERTY_NAME::getEdgeDefaultValue() { return AS_RETURN_EDGE(_property->getEdgeDefaultValue()); }
EDGE_TYPE QPROPERTY_NAME::getEdgeValue(const QEdge* e) { return AS_RETURN_EDGE(_property->getEdgeValue(e->asEdge())); }
void QPROPERTY_NAME::setEdgeValue(const QEdge* e, EDGE_TYPE v) { _property->setEdgeValue(e->asEdge(), AS_ARG_EDGE(v)); }
void QPROPERTY_NAME::setAllEdgeValue(EDGE_TYPE v) { _property->setAllEdgeValue(AS_ARG_EDGE(v)); }

#ifndef SIMPLE
NODE_TYPE QPROPERTY_NAME::getNodeMin() { return _property->getNodeMin(); }
NODE_TYPE QPROPERTY_NAME::getNodeMax() { return _property->getNodeMax(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMin() { return _property->getEdgeMin(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMax() { return _property->getEdgeMax(); }
#endif

#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

//do not generate get{Node/Edge}{Min/Max} from now on
#define SIMPLE

#define CLASS_NAME Boolean
#define PROPERTY_NAME BooleanProperty
#define QPROPERTY_NAME QBooleanProperty
#define EDGE_TYPE bool
#define NODE_TYPE bool

QPROPERTY_NAME::QPROPERTY_NAME(QGraph *g):QProperty(new tlp::PROPERTY_NAME(g->asGraph())) { }
QPROPERTY_NAME::QPROPERTY_NAME(tlp::PROPERTY_NAME* p):QProperty(p) {}
QPROPERTY_NAME::~QPROPERTY_NAME() { delete _property; }

NODE_TYPE QPROPERTY_NAME::getNodeDefaultValue() { return AS_RETURN_NODE(_property->getNodeDefaultValue()); }
NODE_TYPE QPROPERTY_NAME::getNodeValue(const QNode* n) { return AS_RETURN_NODE(_property->getNodeValue(n->asNode())); }
void QPROPERTY_NAME::setNodeValue(const QNode* n, NODE_TYPE v) { _property->setNodeValue(n->asNode(), AS_ARG_NODE(v)); }
void QPROPERTY_NAME::setAllNodeValue(NODE_TYPE v) { _property->setAllNodeValue(AS_ARG_NODE(v)); }

EDGE_TYPE QPROPERTY_NAME::getEdgeDefaultValue() { return AS_RETURN_EDGE(_property->getEdgeDefaultValue()); }
EDGE_TYPE QPROPERTY_NAME::getEdgeValue(const QEdge* e) { return AS_RETURN_EDGE(_property->getEdgeValue(e->asEdge())); }
void QPROPERTY_NAME::setEdgeValue(const QEdge* e, EDGE_TYPE v) { _property->setEdgeValue(e->asEdge(), AS_ARG_EDGE(v)); }
void QPROPERTY_NAME::setAllEdgeValue(EDGE_TYPE v) { _property->setAllEdgeValue(AS_ARG_EDGE(v)); }

#ifndef SIMPLE
NODE_TYPE QPROPERTY_NAME::getNodeMin() { return _property->getNodeMin(); }
NODE_TYPE QPROPERTY_NAME::getNodeMax() { return _property->getNodeMax(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMin() { return _property->getEdgeMin(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMax() { return _property->getEdgeMax(); }
#endif

#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#undef AS_ARG
#define AS_ARG(ARG) ARG->asSize3D()
#undef AS_RETURN_NODE
#define AS_RETURN_NODE(RET) new QSize3D(RET)
#undef AS_RETURN_EDGE
#define AS_RETURN_EDGE(RET) new QSize3DVector(RET)

#define CLASS_NAME Layout
#define PROPERTY_NAME LayoutProperty
#define QPROPERTY_NAME QLayoutProperty
#define EDGE_TYPE QSize3DVector*
#define NODE_TYPE QSize3D*

QPROPERTY_NAME::QPROPERTY_NAME(QGraph *g):QProperty(new tlp::PROPERTY_NAME(g->asGraph())) { }
QPROPERTY_NAME::QPROPERTY_NAME(tlp::PROPERTY_NAME* p):QProperty(p) {}
QPROPERTY_NAME::~QPROPERTY_NAME() { delete _property; }

NODE_TYPE QPROPERTY_NAME::getNodeDefaultValue() { return AS_RETURN_NODE(_property->getNodeDefaultValue()); }
NODE_TYPE QPROPERTY_NAME::getNodeValue(const QNode* n) { return AS_RETURN_NODE(_property->getNodeValue(n->asNode())); }
void QPROPERTY_NAME::setNodeValue(const QNode* n, NODE_TYPE v) { _property->setNodeValue(n->asNode(), AS_ARG_NODE(v)); }
void QPROPERTY_NAME::setAllNodeValue(NODE_TYPE v) { _property->setAllNodeValue(AS_ARG_NODE(v)); }

EDGE_TYPE QPROPERTY_NAME::getEdgeDefaultValue() { return AS_RETURN_EDGE(_property->getEdgeDefaultValue()); }
EDGE_TYPE QPROPERTY_NAME::getEdgeValue(const QEdge* e) { return AS_RETURN_EDGE(_property->getEdgeValue(e->asEdge())); }
void QPROPERTY_NAME::setEdgeValue(const QEdge* e, EDGE_TYPE v) { _property->setEdgeValue(e->asEdge(), AS_ARG_EDGE(v)); }
void QPROPERTY_NAME::setAllEdgeValue(EDGE_TYPE v) { _property->setAllEdgeValue(AS_ARG_EDGE(v)); }

#ifndef SIMPLE
NODE_TYPE QPROPERTY_NAME::getNodeMin() { return _property->getNodeMin(); }
NODE_TYPE QPROPERTY_NAME::getNodeMax() { return _property->getNodeMax(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMin() { return _property->getEdgeMin(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMax() { return _property->getEdgeMax(); }
#endif

#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_RETURN_EDGE
#undef AS_RETURN_NODE
#undef AS_ARG
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#define AS_ARG(ARG) ARG->asGraph()
#define AS_RETURN_NODE(RET) new QGraph(RET)
#define AS_RETURN_EDGE(RET) new QEdgeSet(RET)
#define CLASS_NAME Graph
#define PROPERTY_NAME GraphProperty
#define QPROPERTY_NAME QGraphProperty
#define EDGE_TYPE QEdgeSet*
#define NODE_TYPE QGraph*

QPROPERTY_NAME::QPROPERTY_NAME(QGraph *g):QProperty(new tlp::PROPERTY_NAME(g->asGraph())) { }
QPROPERTY_NAME::QPROPERTY_NAME(tlp::PROPERTY_NAME* p):QProperty(p) {}
QPROPERTY_NAME::~QPROPERTY_NAME() { delete _property; }

NODE_TYPE QPROPERTY_NAME::getNodeDefaultValue() { return AS_RETURN_NODE(_property->getNodeDefaultValue()); }
NODE_TYPE QPROPERTY_NAME::getNodeValue(const QNode* n) { return AS_RETURN_NODE(_property->getNodeValue(n->asNode())); }
void QPROPERTY_NAME::setNodeValue(const QNode* n, NODE_TYPE v) { _property->setNodeValue(n->asNode(), AS_ARG_NODE(v)); }
void QPROPERTY_NAME::setAllNodeValue(NODE_TYPE v) { _property->setAllNodeValue(AS_ARG_NODE(v)); }

EDGE_TYPE QPROPERTY_NAME::getEdgeDefaultValue() { return AS_RETURN_EDGE(_property->getEdgeDefaultValue()); }
EDGE_TYPE QPROPERTY_NAME::getEdgeValue(const QEdge* e) { return AS_RETURN_EDGE(_property->getEdgeValue(e->asEdge())); }
void QPROPERTY_NAME::setEdgeValue(const QEdge* e, EDGE_TYPE v) { _property->setEdgeValue(e->asEdge(), AS_ARG_EDGE(v)); }
void QPROPERTY_NAME::setAllEdgeValue(EDGE_TYPE v) { _property->setAllEdgeValue(AS_ARG_EDGE(v)); }

#ifndef SIMPLE
NODE_TYPE QPROPERTY_NAME::getNodeMin() { return _property->getNodeMin(); }
NODE_TYPE QPROPERTY_NAME::getNodeMax() { return _property->getNodeMax(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMin() { return _property->getEdgeMin(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMax() { return _property->getEdgeMax(); }
#endif

#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_RETURN_EDGE
#undef AS_RETURN_NODE
#undef AS_ARG
#undef AS_RETURN
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#define AS_RETURN(RET) QString::fromStdString(RET)
#define AS_RETURN_NODE(RET) QString::fromStdString(RET)
#define AS_RETURN_EDGE(RET) QString::fromStdString(RET)
#define AS_ARG(ARG) ARG.toStdString()
#define CLASS_NAME String
#define PROPERTY_NAME StringProperty
#define QPROPERTY_NAME QStringProperty
#define EDGE_TYPE QString
#define NODE_TYPE QString

QPROPERTY_NAME::QPROPERTY_NAME(QGraph *g):QProperty(new tlp::PROPERTY_NAME(g->asGraph())) { }
QPROPERTY_NAME::QPROPERTY_NAME(tlp::PROPERTY_NAME* p):QProperty(p) {}
QPROPERTY_NAME::~QPROPERTY_NAME() { delete _property; }

NODE_TYPE QPROPERTY_NAME::getNodeDefaultValue() { return AS_RETURN_NODE(_property->getNodeDefaultValue()); }
NODE_TYPE QPROPERTY_NAME::getNodeValue(const QNode* n) { return AS_RETURN_NODE(_property->getNodeValue(n->asNode())); }
void QPROPERTY_NAME::setNodeValue(const QNode* n, NODE_TYPE v) { _property->setNodeValue(n->asNode(), AS_ARG_NODE(v)); }
void QPROPERTY_NAME::setAllNodeValue(NODE_TYPE v) { _property->setAllNodeValue(AS_ARG_NODE(v)); }

EDGE_TYPE QPROPERTY_NAME::getEdgeDefaultValue() { return AS_RETURN_EDGE(_property->getEdgeDefaultValue()); }
EDGE_TYPE QPROPERTY_NAME::getEdgeValue(const QEdge* e) { return AS_RETURN_EDGE(_property->getEdgeValue(e->asEdge())); }
void QPROPERTY_NAME::setEdgeValue(const QEdge* e, EDGE_TYPE v) { _property->setEdgeValue(e->asEdge(), AS_ARG_EDGE(v)); }
void QPROPERTY_NAME::setAllEdgeValue(EDGE_TYPE v) { _property->setAllEdgeValue(AS_ARG_EDGE(v)); }

#ifndef SIMPLE
NODE_TYPE QPROPERTY_NAME::getNodeMin() { return _property->getNodeMin(); }
NODE_TYPE QPROPERTY_NAME::getNodeMax() { return _property->getNodeMax(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMin() { return _property->getEdgeMin(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMax() { return _property->getEdgeMax(); }
#endif

#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_RETURN_EDGE
#undef AS_RETURN_NODE
#undef AS_RETURN
#undef AS_ARG
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME

#define AS_ARG(ARG) tlp::Color(ARG.red(), ARG.green(), ARG.blue(), ARG.alpha())
#define AS_RETURN(RET) QColor(RET.getR(), RET.getG(), RET.getB(), RET.getA())
#define AS_RETURN_NODE(RET) QColor(RET.getR(), RET.getG(), RET.getB(), RET.getA())
#define AS_RETURN_EDGE(RET) QColor(RET.getR(), RET.getG(), RET.getB(), RET.getA())
#define CLASS_NAME Color
#define PROPERTY_NAME ColorProperty
#define QPROPERTY_NAME QColorProperty
#define EDGE_TYPE QColor
#define NODE_TYPE QColor

QPROPERTY_NAME::QPROPERTY_NAME(QGraph *g):QProperty(new tlp::PROPERTY_NAME(g->asGraph())) { }
QPROPERTY_NAME::QPROPERTY_NAME(tlp::PROPERTY_NAME* p):QProperty(p) {}
QPROPERTY_NAME::~QPROPERTY_NAME() { delete _property; }

NODE_TYPE QPROPERTY_NAME::getNodeDefaultValue() { return AS_RETURN_NODE(_property->getNodeDefaultValue()); }
NODE_TYPE QPROPERTY_NAME::getNodeValue(const QNode* n) { return AS_RETURN_NODE(_property->getNodeValue(n->asNode())); }
void QPROPERTY_NAME::setNodeValue(const QNode* n, NODE_TYPE v) { _property->setNodeValue(n->asNode(), AS_ARG_NODE(v)); }
void QPROPERTY_NAME::setAllNodeValue(NODE_TYPE v) { _property->setAllNodeValue(AS_ARG_NODE(v)); }

EDGE_TYPE QPROPERTY_NAME::getEdgeDefaultValue() { return AS_RETURN_EDGE(_property->getEdgeDefaultValue()); }
EDGE_TYPE QPROPERTY_NAME::getEdgeValue(const QEdge* e) { return AS_RETURN_EDGE(_property->getEdgeValue(e->asEdge())); }
void QPROPERTY_NAME::setEdgeValue(const QEdge* e, EDGE_TYPE v) { _property->setEdgeValue(e->asEdge(), AS_ARG_EDGE(v)); }
void QPROPERTY_NAME::setAllEdgeValue(EDGE_TYPE v) { _property->setAllEdgeValue(AS_ARG_EDGE(v)); }

#ifndef SIMPLE
NODE_TYPE QPROPERTY_NAME::getNodeMin() { return _property->getNodeMin(); }
NODE_TYPE QPROPERTY_NAME::getNodeMax() { return _property->getNodeMax(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMin() { return _property->getEdgeMin(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMax() { return _property->getEdgeMax(); }
#endif

#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_ARG
#undef AS_RETURN
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME
#undef AS_RETURN_NODE
#undef AS_RETURN_EDGE

#define AS_ARG(ARG) tlp::Size(ARG.getW(), ARG.getH(), ARG.getD())
#define AS_RETURN(RET) QSize3D(RET)
#define AS_RETURN_NODE(RET) QSize3D(RET)
#define AS_RETURN_EDGE(RET) QSize3D(RET)
#define CLASS_NAME Size
#define PROPERTY_NAME SizeProperty
#define QPROPERTY_NAME QSizeProperty
#define EDGE_TYPE QSize3D
#define NODE_TYPE QSize3D

QPROPERTY_NAME::QPROPERTY_NAME(QGraph *g):QProperty(new tlp::PROPERTY_NAME(g->asGraph())) { }
QPROPERTY_NAME::QPROPERTY_NAME(tlp::PROPERTY_NAME* p):QProperty(p) {}
QPROPERTY_NAME::~QPROPERTY_NAME() { delete _property; }

NODE_TYPE QPROPERTY_NAME::getNodeDefaultValue() { return AS_RETURN_NODE(_property->getNodeDefaultValue()); }
NODE_TYPE QPROPERTY_NAME::getNodeValue(const QNode* n) { return AS_RETURN_NODE(_property->getNodeValue(n->asNode())); }
void QPROPERTY_NAME::setNodeValue(const QNode* n, NODE_TYPE v) { _property->setNodeValue(n->asNode(), AS_ARG_NODE(v)); }
void QPROPERTY_NAME::setAllNodeValue(NODE_TYPE v) { _property->setAllNodeValue(AS_ARG_NODE(v)); }

EDGE_TYPE QPROPERTY_NAME::getEdgeDefaultValue() { return AS_RETURN_EDGE(_property->getEdgeDefaultValue()); }
EDGE_TYPE QPROPERTY_NAME::getEdgeValue(const QEdge* e) { return AS_RETURN_EDGE(_property->getEdgeValue(e->asEdge())); }
void QPROPERTY_NAME::setEdgeValue(const QEdge* e, EDGE_TYPE v) { _property->setEdgeValue(e->asEdge(), AS_ARG_EDGE(v)); }
void QPROPERTY_NAME::setAllEdgeValue(EDGE_TYPE v) { _property->setAllEdgeValue(AS_ARG_EDGE(v)); }

#ifndef SIMPLE
NODE_TYPE QPROPERTY_NAME::getNodeMin() { return _property->getNodeMin(); }
NODE_TYPE QPROPERTY_NAME::getNodeMax() { return _property->getNodeMax(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMin() { return _property->getEdgeMin(); }
EDGE_TYPE QPROPERTY_NAME::getEdgeMax() { return _property->getEdgeMax(); }
#endif

#undef CLASS_NAME
#undef EDGE_TYPE
#undef NODE_TYPE
#undef AS_ARG
#undef AS_RETURN
#undef AS_ARG_EDGE
#undef AS_ARG_NODE
#undef AS_RETURN_EDGE
#undef AS_RETURN_NODE
#undef PROPERTY_NAME
#undef QPROPERTY_NAME
#undef CLASS_NAME
#undef PROPERTY_NAME
#undef QPROPERTY_NAME*/

#endif //TEMPLATE_PROPERTIES_CPP
