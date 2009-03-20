#include "QGraphProperty.h"
#include "QGraph.h"

QGraphProperty::QGraphProperty(const QGraph* g) :
	QProperty(new tlp::GraphProperty(g->asGraph())) {
}

QGraphProperty::QGraphProperty(tlp::GraphProperty* p) :
	QProperty(p) {
}

QGraphProperty::~QGraphProperty() {
	delete _property;
}

tlp::GraphProperty* QGraphProperty::asProperty() {
	return dynamic_cast<tlp::GraphProperty*> (_property);
}

QGraph* QGraphProperty::getNodeDefaultValue() {
	return new QGraph(
			dynamic_cast<tlp::GraphProperty*> (_property)->getNodeDefaultValue());
}

QEdgeSet* QGraphProperty::getEdgeDefaultValue() {
	return new QEdgeSet*(
			dynamic_cast<tlp::GraphProperty*> (_property)->getEdgeDefaultValue());
}

QGraph* QGraphProperty::getNodeValue(const QNode* n) {
	return new QGraph(
			dynamic_cast<tlp::GraphProperty*> (_property)->getNodeValue(
					n->asNode()));
}

QEdgeSet* QGraphProperty::getEdgeValue(const QEdge* e) {
	return new QEdgeSet*(
			dynamic_cast<tlp::GraphProperty*> (_property)->getEdgeValue(
					e->asEdge()));
}

void QGraphProperty::setNodeValue(const QNode* n, const QGraph* v) {
	dynamic_cast<tlp::GraphProperty*> (_property)->setNodeValue(n->asNode(),
			v->asGraph());
}

void QGraphProperty::setEdgeValue(const QEdge* e, const QEdgeSet* v) {
	dynamic_cast<tlp::GraphProperty*> (_property)->setEdgeValue(e->asEdge(),
			v->asGraph());
}

void QGraphProperty::setAllNodeValue(const QGraph* v) {
	dynamic_cast<tlp::GraphProperty*> (_property)->setAllNodeValue(v->asGraph());
}

void QGraphProperty::setAllEdgeValue(const QEdgeSet* v) {
	dynamic_cast<tlp::GraphProperty*> (_property)->setAllEdgeValue(v->asGraph());
}

void QGraphProperty::destroy(const QGraph * g) {
	dynamic_cast<tlp::GraphProperty*> (_property)->destroy(g->asGraph());
}

bool QGraphProperty::setNodeStringValue(const QNode* n, const QString* v) {
	return dynamic_cast<tlp::GraphProperty*> (_property)->setNodeStringValue(
			n->asNode(), v->toStdString());
}

bool QGraphProperty::setAllNodeStringValue(const QString* v) {
	return dynamic_cast<tlp::GraphProperty*> (_property)->setAllNodeStringValue(
			v->toStdString());
}

bool QGraphProperty::setEdgeStringValue(const QEdge* e, const QString* v) {
	return dynamic_cast<tlp::GraphProperty*> (_property)->setEdgeStringValue(
			e->asEdge(), v->toStdString());
}

bool QGraphProperty::setAllEdgeStringValue(const QString* v) {
	return dynamic_cast<tlp::GraphProperty*> (_property)->setAllEdgeStringValue(
			v->toStdString());
}

