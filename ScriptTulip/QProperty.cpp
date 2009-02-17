#include "QProperty.h"

using namespace tlp;

QProperty::QProperty()
{
}

QProperty::QProperty(tlp::PropertyInterface* property)
:_property(property) {
}

QProperty::~QProperty() {
}

tlp::PropertyInterface* QProperty::asProperty() {
	return _property;
}

QString QProperty::getNodeStringValue(QNode *node) {
	return QString::fromStdString(_property->getNodeStringValue(node->asNode()));
}

bool QProperty::setNodeStringValue(QNode *node, QString value) {
	return _property->setNodeStringValue(node->asNode(), value.toStdString());
}

QString QProperty::getNodeDefaultStringValue() {
	return QString::fromStdString(_property->getNodeDefaultStringValue());
}

QString QProperty::getEdgeDefaultStringValue() {
	return QString::fromStdString(_property->getEdgeDefaultStringValue());
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

