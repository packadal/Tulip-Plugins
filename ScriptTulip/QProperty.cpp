#include "QProperty.h"

using namespace tlp;

QProperty::QProperty() {
}

QProperty::QProperty(PropertyInterface *property)
:_property(property) {
}

QProperty::~QProperty() {
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

QScriptValue qPropertyToScriptValue(QScriptEngine *engine, const QProperty &prop) {

	//TODO: finir  ça
	QScriptValue ret;// = engine->newObject()->ret;


	return ret;
}

void qPropertyFromScriptValue(const QScriptValue &obj, QProperty &prop) {

}
