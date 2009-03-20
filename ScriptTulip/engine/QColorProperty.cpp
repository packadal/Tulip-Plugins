#include "QColorProperty.h"
#include "QGraph.h"

QColorProperty::QColorProperty(const QGraph* g) :
	_property(new tlp::ColorProperty(g->asGraph())) {
}

QColorProperty::QColorProperty(tlp::ColorProperty* p) :
	_property(p) {
}

QColorProperty::~QColorProperty() {
	delete _property;
}

tlp::ColorProperty* QColorProperty::asProperty() {
	return _property;
}

QColor* QColorProperty::getNodeDefaultValue() {
	tlp::Color c = _property->getNodeDefaultValue();
	return new QColor(c.getR(), c.getG(), c.getB(), c.getA());
}

QColor* QColorProperty::getEdgeDefaultValue() {
	return _property->getEdgeDefaultValue();
}

QColor* QColorProperty::getNodeValue(const QNode* n) {
	tlp::Color c = _property->getNodeValue(n->asNode());
	return new QColor(c.getR(), c.getG(), c.getB(), c.getA());
}

QColor* QColorProperty::getEdgeValue(const QEdge* e) {
	tlp::Color c = _property->getEdgeValue(e->asEdge());
	return new QColor(c.getR(), c.getG(), c.getB(), c.getA());
}

void QColorProperty::setNodeValue(const QNode* n, const QColor* v) {
	int r,g,b,a;
	v->getRgb(r,g,b,a);
	_property->setNodeValue(n->asNode(), new Color(r,g,b,a));
}

void QColorProperty::setEdgeValue(const QEdge* e, const QColor* v) {
	int r,g,b,a;
	v->getRgb(r,g,b,a);
	_property->setEdgeValue(e->asEdge(), new Color(r,g,b,a));
}

void QColorProperty::setAllNodeValue(const QColor* v) {
	int r,g,b,a;
	v->getRgb(r,g,b,a);
	_property->setAllNodeValue(new Color(r,g,b,a));
}

void QColorProperty::setAllEdgeValue(const QColor* v) {
	int r,g,b,a;
	v->getRgb(r,g,b,a);
	_property->setAllEdgeValue(new Color(r,g,b,a));
}
