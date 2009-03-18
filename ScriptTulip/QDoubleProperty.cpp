#include "QDoubleProperty.h"
#include "QGraph.h"

QDoubleProperty::QDoubleProperty(const QGraph* g) {
        _property = new tlp::DoubleProperty(g->asGraph());
}

QDoubleProperty::QDoubleProperty(tlp::DoubleProperty* p) :
        _property(p) {
}

QDoubleProperty::~QDoubleProperty() {
        delete _property;
}

tlp::DoubleProperty* QDoubleProperty::asProperty() {
        return _property;
}

double QDoubleProperty::getNodeDefaultValue() {
        return _property->getNodeDefaultValue();
}

double QDoubleProperty::getEdgeDefaultValue() {
        return _property->getEdgeDefaultValue();
}

double QIntegerProperty::getNodeValue(const QNode* n) {
        return _property->getNodeValue(n->asNode());
}

double QDoubleProperty::getEdgeValue(const QEdge* e) {
        return _property->getEdgeValue(e->asEdge());
}

void QDoubleProperty::setNodeValue(const QNode* n, double v) {
        _property->setNodeValue(n->asNode(), v);
}

void QDoubleProperty::setEdgeValue(const QEdge* e, double v) {
        _property->setEdgeValue(e->asEdge(), v);
}

void QIntegerProperty::setAllNodeValue(double v) {
        _property->setAllNodeValue(v);
}

void QDoubleProperty::setAllEdgeValue(double v) {
        _property->setAllEdgeValue(v);
}

double QDoubleProperty::getNodeMin(const QGraph *sg) {
        return _property->getNodeMin(sg);
}

double QDoubleProperty::getNodeMax(const QGraph *sg) {
        return _property->getNodeMax(sg);
}

double QDoubleProperty::getEdgeMin(const QGraph *sg) {
        return _property->getEdgeMin(sg);
}

double QDoubleProperty::getEdgeMax(const QGraph *sg) {
        return _property->getEdgeMax(sg);
}

void QDoubleProperty::uniformQuantification(unsigned int i) {
	_property->uniformQuantification(i);
}
