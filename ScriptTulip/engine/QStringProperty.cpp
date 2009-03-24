#include "QStringProperty.h"
#include "QGraph.h"

QStringProperty::QStringProperty(const QGraph* g) :
	QProperty(new tlp::StringProperty(g->asGraph())) {
}

QStringProperty::QStringProperty(tlp::StringProperty* p) :
	QProperty(p) {
}

QStringProperty::~QStringProperty() {
	delete _property;
}

tlp::StringProperty* QStringProperty::asProperty() {
	return dynamic_cast<tlp::StringProperty*>(_property);
}

const QString& QStringProperty::getNodeDefaultValue() {
	return QString::fromStdString(dynamic_cast<tlp::StringProperty*>(_property)->getNodeDefaultValue());
}

const QString& QStringProperty::getEdgeDefaultValue() {
	return QString::fromStdString(dynamic_cast<tlp::StringProperty*>(_property)->getEdgeDefaultValue());
}

const QString& QStringProperty::getNodeValue(QNode* n) {
	return QString::fromStdString(dynamic_cast<tlp::StringProperty*>(_property)->getNodeValue(n->asNode()));
}

const QString& QStringProperty::getEdgeValue(QEdge* e) {
	return QString::fromStdString(dynamic_cast<tlp::StringProperty*>(_property)->getEdgeValue(e->asEdge()));
}

void QStringProperty::setNodeValue(QNode* n, QString* v) {
	dynamic_cast<tlp::StringProperty*>(_property)->setNodeValue(n->asNode(), v->toStdString());
}

void QStringProperty::setEdgeValue(QEdge* e, QString* v) {
	dynamic_cast<tlp::StringProperty*>(_property)->setEdgeValue(e->asEdge(), v->toStdString());
}

void QStringProperty::setAllNodeValue(QString* v) {
	dynamic_cast<tlp::StringProperty*>(_property)->setAllNodeValue(v->toStdString());
}

void QStringProperty::setAllEdgeValue(QString* v) {
	dynamic_cast<tlp::StringProperty*>(_property)->setAllEdgeValue(v->toStdString());
}
