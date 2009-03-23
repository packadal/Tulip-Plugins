#include "QLayoutProperty.h"
#include "QGraph.h"

QLayoutProperty::QLayoutProperty(const QGraph* g) :
	QProperty(new tlp::LayoutProperty(g->asGraph())) {
}

QLayoutProperty::QLayoutProperty(tlp::LayoutProperty* p) :
	QProperty(p) {
}

QLayoutProperty::~QLayoutProperty() {
	delete _property;
}

tlp::LayoutProperty* QLayoutProperty::asProperty() {
	return dynamic_cast<tlp::LayoutProperty*> (_property);
}

QSize3D* QLayoutProperty::getNodeDefaultValue() {
	return new QSize3D(
			dynamic_cast<tlp::LayoutProperty*> (_property)->getNodeDefaultValue());
}

QSize3DVector* QLayoutProperty::getEdgeDefaultValue() {
	return new QSize3DVector(
			dynamic_cast<tlp::LayoutProperty*> (_property)->getEdgeDefaultValue());
}

QSize3D* QLayoutProperty::getNodeValue(const QNode* n) {
	return new QSize3D(
			dynamic_cast<tlp::LayoutProperty*> (_property)->getNodeValue(
					n->asNode()));
}

QSize3DVector* QLayoutProperty::getEdgeValue(const QEdge* e) {
	return new QSize3DVector(
			dynamic_cast<tlp::LayoutProperty*> (_property)->getEdgeValue(
					e->asEdge()));
}

void QLayoutProperty::setNodeValue(const QNode* n, const QSize3D* v) {
	dynamic_cast<tlp::LayoutProperty*> (_property)->setNodeValue(n->asNode(),
			v->asCoord());
}

void QLayoutProperty::setEdgeValue(const QEdge* e, const QSize3DVector* v) {
	dynamic_cast<tlp::LayoutProperty*> (_property)->setEdgeValue(e->asEdge(),
			v->asGraph());
}

void QLayoutProperty::setAllNodeValue(const QSize3D* v) {
	dynamic_cast<tlp::LayoutProperty*> (_property)->setAllNodeValue(
			v->asCoord());
}

void QLayoutProperty::setAllEdgeValue(const QSize3DVector* v) {
	dynamic_cast<tlp::LayoutProperty*> (_property)->setAllEdgeValue(
			v->asGraph());
}
