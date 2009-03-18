#include "QBooleanProperty.h"
#include "QGraph.h"

QBooleanProperty::QBooleanProperty(const QGraph* g) {
        _property = new tlp::BooleanProperty(g->asGraph());
}

QBooleanProperty::QBooleanProperty(tlp::BooleanProperty* p) :
        _property(p) {
}

QBooleanProperty::~QBooleanProperty() {
        delete _property;
}

tlp::BooleanProperty* QBooleanProperty::asProperty() {
        return _property;
}

bool QBooleanProperty::getNodeDefaultValue() {
        return _property->getNodeDefaultValue();
}

bool QBooleanProperty::getEdgeDefaultValue() {
        return _property->getEdgeDefaultValue();
}

bool QBooleanProperty::getNodeValue(const QNode* n) {
        return _property->getNodeValue(n->asNode());
}

bool QBooleanProperty::getEdgeValue(const QEdge* e) {
        return _property->getEdgeValue(e->asEdge());
}

void QBooleanProperty::setNodeValue(const QNode* n, bool v) {
        _property->setNodeValue(n->asNode(), v);
}

void QBooleanProperty::setEdgeValue(const QEdge* e, bool v) {
        _property->setEdgeValue(e->asEdge(), v);
}

void QBooleanProperty::setAllNodeValue(bool v) {
        _property->setAllNodeValue(v);
}

void QBooleanProperty::setAllEdgeValue(bool v) {
        _property->setAllEdgeValue(v);
}

void QBooleanProperty::reverse() {
	_property->reverse();
}

void QBooleanProperty::reverseEdgeDirection() {
	_property->reverseEdgeDirection();
}

QIterator* QBooleanProperty::getNodesEqualTo(const bool val, QGraph * g) {
	return new QIterator(_property->getNodesEqualTo(val,g));
}

QIterator* QBooleanProperty::getEdgesEqualTo(const bool val, QGraph * g) {
	return new QIterator(_property->getEdgesEqualTo(val,g));
}
