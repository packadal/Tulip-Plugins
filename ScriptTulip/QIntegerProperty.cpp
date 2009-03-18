#include "QIntegerProperty.h"
#include "QGraph.h"

QIntegerProperty::QIntegerProperty(const QGraph* g) {
        _property = new tlp::IntegerProperty(g->asGraph());
}

QIntegerProperty::QIntegerProperty(tlp::IntegerProperty* p) :
        _property(p) {
}

QIntegerProperty::~QIntegerProperty() {
        delete _property;
}

tlp::IntegerProperty* QIntegerProperty::asProperty() {
        return _property;
}

int QIntegerProperty::getNodeDefaultValue() {
        return _property->getNodeDefaultValue();
}

int QIntegerProperty::getEdgeDefaultValue() {
        return _property->getEdgeDefaultValue();
}

int QIntegerProperty::getNodeValue(const QNode* n) {
        return _property->getNodeValue(n->asNode());
}

int QIntegerProperty::getEdgeValue(const QEdge* e) {
        return _property->getEdgeValue(e->asEdge());
}

void QIntegerProperty::setNodeValue(const QNode* n, int v) {
        _property->setNodeValue(n->asNode(), v);
}

void QIntegerProperty::setEdgeValue(const QEdge* e, int v) {
        _property->setEdgeValue(e->asEdge(), v);
}

void QIntegerProperty::setAllNodeValue(int v) {
        _property->setAllNodeValue(v);
}

void QIntegerProperty::setAllEdgeValue(int v) {
        _property->setAllEdgeValue(v);
}

int QIntegerProperty::getNodeMin() {
        return _property->getNodeMin();
}

int QIntegerProperty::getNodeMax() {
        return _property->getNodeMax();
}

int QIntegerProperty::getEdgeMin() {
        return _property->getEdgeMin();
}

int QIntegerProperty::getEdgeMax() {
        return _property->getEdgeMax();
}
