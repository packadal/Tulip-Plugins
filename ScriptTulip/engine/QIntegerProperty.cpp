#include "QIntegerProperty.h"
#include "QGraph.h"

QIntegerProperty::QIntegerProperty(const QGraph* g) :
	QProperty(new tlp::IntegerProperty(g->asGraph())) {
}

QIntegerProperty::QIntegerProperty(tlp::IntegerProperty* p) :
	QProperty(p) {
}

QIntegerProperty::~QIntegerProperty() {
	delete _property;
}

tlp::IntegerProperty* QIntegerProperty::asProperty() {
	return dynamic_cast<tlp::IntegerProperty*> (_property);
}

int QIntegerProperty::getNodeDefaultValue() {
	return dynamic_cast<tlp::IntegerProperty*> (_property)->getNodeDefaultValue();
}

int QIntegerProperty::getEdgeDefaultValue() {
	return dynamic_cast<tlp::IntegerProperty*> (_property)->getEdgeDefaultValue();
}

int QIntegerProperty::getNodeValue(QNode* n) {
	return dynamic_cast<tlp::IntegerProperty*> (_property)->getNodeValue(
			n->asNode());
}

int QIntegerProperty::getEdgeValue(QEdge* e) {
	return dynamic_cast<tlp::IntegerProperty*> (_property)->getEdgeValue(
			e->asEdge());
}

void QIntegerProperty::setNodeValue(QNode* n, int v) {
	dynamic_cast<tlp::IntegerProperty*> (_property)->setNodeValue(n->asNode(),
			v);
}

void QIntegerProperty::setEdgeValue(QEdge* e, int v) {
	dynamic_cast<tlp::IntegerProperty*> (_property)->setEdgeValue(e->asEdge(),
			v);
}

void QIntegerProperty::setAllNodeValue(int v) {
	dynamic_cast<tlp::IntegerProperty*> (_property)->setAllNodeValue(v);
}

void QIntegerProperty::setAllEdgeValue(int v) {
	dynamic_cast<tlp::IntegerProperty*> (_property)->setAllEdgeValue(v);
}

int QIntegerProperty::getNodeMin() {
	return dynamic_cast<tlp::IntegerProperty*> (_property)->getNodeMin();
}

int QIntegerProperty::getNodeMax() {
	return dynamic_cast<tlp::IntegerProperty*> (_property)->getNodeMax();
}

int QIntegerProperty::getEdgeMin() {
	return dynamic_cast<tlp::IntegerProperty*> (_property)->getEdgeMin();
}

int QIntegerProperty::getEdgeMax() {
	return dynamic_cast<tlp::IntegerProperty*> (_property)->getEdgeMax();
}
