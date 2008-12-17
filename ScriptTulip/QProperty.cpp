#include "QProperty.h"

using namespace tlp;

QProperty::QProperty()
:_property()
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
	//return QString::fromStdString(_property->getNodeStringValue(node->asNode()));
	return QString("");
}

bool QProperty::setNodeStringValue(QNode *node, QString value) {
	//return _property->setNodeStringValue(node->asNode(), value.toStdString());
	return true;
}

QString QProperty::getNodeDefaultStringValue() {
	return QString::fromStdString(_property->getNodeDefaultStringValue());
}

QString QProperty::getEdgeDefaultStringValue() {
	return QString::fromStdString(_property->getEdgeDefaultStringValue());
}
