#include "QBooleanProperty.h"
#include "QGraph.h"

QBooleanProperty::QBooleanProperty(const QGraph* g) :
	QProperty(new tlp::BooleanProperty(g->asGraph())) {
}

QBooleanProperty::QBooleanProperty(tlp::BooleanProperty* p) :
	QProperty(p) {
}

QBooleanProperty::~QBooleanProperty() {
	delete _property;
}

tlp::BooleanProperty* QBooleanProperty::asProperty() {
	return dynamic_cast<tlp::BooleanProperty*> (_property);
}

bool QBooleanProperty::getNodeDefaultValue() {
	return dynamic_cast<tlp::BooleanProperty*> (_property)->getNodeDefaultValue();
}

bool QBooleanProperty::getEdgeDefaultValue() {
	return dynamic_cast<tlp::BooleanProperty*> (_property)->getEdgeDefaultValue();
}

bool QBooleanProperty::getNodeValue(QNode* n) {
	return dynamic_cast<tlp::BooleanProperty*> (_property)->getNodeValue(
			n->asNode());
}

bool QBooleanProperty::getEdgeValue(QEdge* e) {
	return dynamic_cast<tlp::BooleanProperty*> (_property)->getEdgeValue(
			e->asEdge());
}

void QBooleanProperty::setNodeValue(QNode* n, bool v) {
	dynamic_cast<tlp::BooleanProperty*> (_property)->setNodeValue(n->asNode(),
			v);
}

void QBooleanProperty::setEdgeValue(QEdge* e, bool v) {
	dynamic_cast<tlp::BooleanProperty*> (_property)->setEdgeValue(e->asEdge(),
			v);
}

void QBooleanProperty::setAllNodeValue(bool v) {
	dynamic_cast<tlp::BooleanProperty*> (_property)->setAllNodeValue(v);
}

void QBooleanProperty::setAllEdgeValue(bool v) {
	dynamic_cast<tlp::BooleanProperty*> (_property)->setAllEdgeValue(v);
}

void QBooleanProperty::reverse() {
	dynamic_cast<tlp::BooleanProperty*> (_property)->reverse();
}

void QBooleanProperty::reverseEdgeDirection() {
	dynamic_cast<tlp::BooleanProperty*> (_property)->reverseEdgeDirection();
}

QIterator* QBooleanProperty::getNodesEqualTo(bool val, QGraph * g) {
	return new QIterator(
			dynamic_cast<tlp::BooleanProperty*> (_property)->getNodesEqualTo(
					val, g->asGraph()));
}

QIterator* QBooleanProperty::getEdgesEqualTo(bool val, QGraph * g) {
	return new QIterator(
			dynamic_cast<tlp::BooleanProperty*> (_property)->getEdgesEqualTo(
					val, g->asGraph()));
}
