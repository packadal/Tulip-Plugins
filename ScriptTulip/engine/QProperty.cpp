#include "QProperty.h"
#include "QEdge.h"
#include "QNode.h"
#include "QGraph.h"

using namespace tlp;

QProperty::QProperty() :
	_property(0)
{
}

QProperty::QProperty(tlp::PropertyInterface* property) :
	_property(property) {
}

QProperty::~QProperty() {
	delete _property;
}

tlp::PropertyInterface* QProperty::asProperty() const {
	return _property;
}

QString QProperty::getNodeStringValue(const QNode *node) {
	return QString::fromStdString(_property->getNodeStringValue(node->asNode()));
}

QString QProperty::getEdgeStringValue(const QEdge *edge) {
	return QString::fromStdString(_property->getEdgeStringValue(edge->asEdge()));
}

bool QProperty::setNodeStringValue(const QNode *node, const QString value) {
	return _property->setNodeStringValue(node->asNode(), value.toStdString());
}

bool QProperty::setEdgeStringValue(const QEdge *edge, const QString value) {
	return _property->setEdgeStringValue(edge->asEdge(), value.toStdString());
}

QString QProperty::getNodeDefaultStringValue() {
	return QString::fromStdString(_property->getNodeDefaultStringValue());
}

QString QProperty::getEdgeDefaultStringValue() {
	return QString::fromStdString(_property->getEdgeDefaultStringValue());
}

bool QProperty::setAllNodeStringValue(const QString value) {
	return _property->setAllNodeStringValue(value.toStdString());
}

bool QProperty::setAllEdgeStringValue(const QString value) {
	return _property->setAllEdgeStringValue(value.toStdString());
}

void QProperty::erase(const QNode* node) {
	_property->erase(node->asNode());
}

void QProperty::erase(const QEdge* edge) {
	_property->erase(edge->asEdge());
}

void QProperty::copy(const QNode* node, const QNode* node2, QProperty* prop) {
	_property->copy(node->asNode(), node2->asNode(), prop->asProperty());
}

void QProperty::copy(const QEdge* edge, const QEdge* edge2, QProperty* prop) {
	_property->copy(edge->asEdge(), edge2->asEdge(), prop->asProperty());
}

QProperty* QProperty::clonePrototype(QGraph *graph, QString s) {
	return new QProperty(_property->clonePrototype(graph->asGraph(), s.toStdString()));
}

QString QProperty::getTypename() {
	return QString::fromStdString(_property->getTypename());
}

QString QProperty::getTypename(QProperty *prop) {
	return QString::fromStdString(PropertyInterface::getTypename(prop->asProperty()));
}
