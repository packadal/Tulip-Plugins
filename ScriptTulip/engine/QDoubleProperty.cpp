#include "QDoubleProperty.h"
#include "QGraph.h"

QDoubleProperty::QDoubleProperty(const QGraph* g) :
	QProperty(new tlp::DoubleProperty(g->asGraph())) {
}

QDoubleProperty::QDoubleProperty(tlp::DoubleProperty* p) :
	QProperty(p) {
}

QDoubleProperty::~QDoubleProperty() {
	delete _property;
}

tlp::DoubleProperty* QDoubleProperty::asProperty() {
	return dynamic_cast<tlp::DoubleProperty*> (_property);
}

double QDoubleProperty::getNodeDefaultValue() {
	return dynamic_cast<tlp::DoubleProperty*> (_property)->getNodeDefaultValue();
}

double QDoubleProperty::getEdgeDefaultValue() {
	return dynamic_cast<tlp::DoubleProperty*> (_property)->getEdgeDefaultValue();
}

double QDoubleProperty::getNodeValue(const QNode* n) {
	return dynamic_cast<tlp::DoubleProperty*> (_property)->getNodeValue(
			n->asNode());
}

double QDoubleProperty::getEdgeValue(const QEdge* e) {
	return dynamic_cast<tlp::DoubleProperty*> (_property)->getEdgeValue(
			e->asEdge());
}

void QDoubleProperty::setNodeValue(const QNode* n, double v) {
	dynamic_cast<tlp::DoubleProperty*> (_property)->setNodeValue(n->asNode(), v);
}

void QDoubleProperty::setEdgeValue(const QEdge* e, double v) {
	dynamic_cast<tlp::DoubleProperty*> (_property)->setEdgeValue(e->asEdge(), v);
}

void QDoubleProperty::setAllNodeValue(double v) {
	dynamic_cast<tlp::DoubleProperty*> (_property)->setAllNodeValue(v);
}

void QDoubleProperty::setAllEdgeValue(double v) {
	dynamic_cast<tlp::DoubleProperty*> (_property)->setAllEdgeValue(v);
}

double QDoubleProperty::getNodeMin(const QGraph *sg) {
	return dynamic_cast<tlp::DoubleProperty*> (_property)->getNodeMin(sg->asGraph());
}

double QDoubleProperty::getNodeMax(const QGraph *sg) {
	return dynamic_cast<tlp::DoubleProperty*> (_property)->getNodeMax(sg->asGraph());
}

double QDoubleProperty::getEdgeMin(const QGraph *sg) {
	return dynamic_cast<tlp::DoubleProperty*> (_property)->getEdgeMin(sg->asGraph());
}

double QDoubleProperty::getEdgeMax(const QGraph *sg) {
	return dynamic_cast<tlp::DoubleProperty*> (_property)->getEdgeMax(sg->asGraph());
}

void QDoubleProperty::uniformQuantification(unsigned int i) {
	dynamic_cast<tlp::DoubleProperty*> (_property)->uniformQuantification(i);
}
