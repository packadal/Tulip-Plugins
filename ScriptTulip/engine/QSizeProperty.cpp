#include "QSizeProperty.h"
#include "QGraph.h"

QSizeProperty::QSizeProperty(const QGraph* g) :
	QProperty(new tlp::SizeProperty(g->asGraph())) {
}

QSizeProperty::QSizeProperty(tlp::SizeProperty* p) :
	QProperty(p) {
}

QSizeProperty::~QSizeProperty() {
	delete _property;
}

tlp::SizeProperty* QSizeProperty::asProperty() {
	return dynamic_cast<tlp::SizeProperty*> (_property);
}

QSize3D* QSizeProperty::getNodeDefaultValue() {
	return new QSize3D(
			dynamic_cast<tlp::SizeProperty*> (_property)->getNodeDefaultValue());
}

QSize3D* QSizeProperty::getEdgeDefaultValue() {
	return new QSize3D(
			dynamic_cast<tlp::SizeProperty*> (_property)->getEdgeDefaultValue());
}

QSize3D* QSizeProperty::getNodeValue(const QNode* n) {
	return new QSize3D(
			dynamic_cast<tlp::SizeProperty*> (_property)->getNodeValue(
					n->asNode()));
}

QSize3D* QSizeProperty::getEdgeValue(const QEdge* e) {
	return new QSize3D(
			dynamic_cast<tlp::SizeProperty*> (_property)->getEdgeValue(
					e->asEdge()));
}

void QSizeProperty::setNodeValue(const QNode* n, const QSize3D* v) {
	dynamic_cast<tlp::SizeProperty*> (_property)->setNodeValue(n->asNode(),
			v->asSize3D());
}

void QSizeProperty::setEdgeValue(const QEdge* e, const QSize3D* v) {
	dynamic_cast<tlp::SizeProperty*> (_property)->setEdgeValue(e->asEdge(),
			v->asSize3D());
}

void QSizeProperty::setAllNodeValue(const QSize3D* v) {
	dynamic_cast<tlp::SizeProperty*> (_property)->setAllNodeValue(v->asSize3D());
}

void QSizeProperty::setAllEdgeValue(const QSize3D* v) {
	dynamic_cast<tlp::SizeProperty*> (_property)->setAllEdgeValue(v->asSize3D());
}

QSize3D* QSizeProperty::getMax(const QGraph *sg) {
	return new QSize3D(dynamic_cast<tlp::SizeProperty*> (_property)->getMax(
			sg->asGraph()));
}

QSize3D* QSizeProperty::getMin(const QGraph *sg) {
	return new QSize3D(dynamic_cast<tlp::SizeProperty*> (_property)->getMin(
			sg->asGraph()));
}

