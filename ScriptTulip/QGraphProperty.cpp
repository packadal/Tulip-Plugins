#include "QGraphProperty.h"
#include "QGraph.h"

QGraphProperty::QGraphProperty(const QGraph* g) {
        _property = new tlp::GraphProperty(g->asGraph());
}

QGraphProperty::QGraphProperty(tlp::GraphProperty* p) :
        _property(p) {
}

QGraphProperty::~QGraphProperty() {
        delete _property;
}

tlp::GraphProperty* QGraphProperty::asProperty() {
        return _property;
}

QGraph* QGraphProperty::getNodeDefaultValue() {
        return new QGraph(_property->getNodeDefaultValue());
}

QEdgeSet* QGraphProperty::getEdgeDefaultValue() {
        return new QSTDSET(Edge, tlp::Edge)(_property->getEdgeDefaultValue());
}

QGraph* QGraphProperty::getNodeValue(const QNode* n) {
        return new QGraph(_property->getNodeValue(n->asNode()));
}

QEdgeSet* QGraphProperty::getEdgeValue(const QEdge* e) {
        return new QSTDSET(Edge, tlp::Edge)(_property->getEdgeValue(e->asEdge()));
}

void QGraphProperty::setNodeValue(const QNode* n, const QGraph* v) {
        _property->setNodeValue(n->asNode(), v->asGraph());
}

void QGraphProperty::setEdgeValue(const QEdge* e, const QEdgeSet* v) {
        _property->setEdgeValue(e->asEdge(), v->asGraph());
}

void QGraphProperty::setAllNodeValue(const QGraph* v) {
        _property->setAllNodeValue(v->asGraph());
}

void QGraphProperty::setAllEdgeValue(const QEdgeSet* v) {
        _property->setAllEdgeValue(v->asGraph());
}

void QGraphProperty::destroy(const QGraph * g) {
	_property->destroy(g->asGraph());
}

bool QGraphProperty::setNodeStringValue(const QNode* n, const QString* v) {
	return _property->setNodeStringValue(n->asNode(), v->toStdString());
}

bool QGraphProperty::setAllNodeStringValue(const QString* v) {
	return _property->setAllNodeStringValue(v->toStdString());
}

bool QGraphProperty::setEdgeStringValue( const QEdge* e, const QString* v) {
	return _property->setEdgeStringValue(e->asEdge(), v->toStdString());
}

bool QGraphProperty::setAllEdgeStringValue(const QString* v) {
	return _property->setAllEdgeStringValue(v->toStdString());
}

