#include "QStringProperty.h"
#include "QGraph.h"

QStringProperty::QStringProperty(const QGraph* g) {
        _property = new tlp::StringProperty(g->asGraph());
}

QStringProperty::QStringProperty(tlp::StringProperty* p) :
        _property(p) {
}

QStringProperty::~QStringProperty() {
        delete _property;
}

tlp::StringProperty* QStringProperty::asProperty() {
        return _property;
}

QString* QStringProperty::getNodeDefaultValue() {
        return new QString(_property->getNodeDefaultValue());
}

QString* QStringProperty::getEdgeDefaultValue() {
        return new QString(_property->getEdgeDefaultValue());
}

QString* QStringProperty::getNodeValue(const QNode* n) {
        return new QString(_property->getNodeValue(n->asNode()));
}

QString* QStringProperty::getEdgeValue(const QEdge* e) {
        return new QString(_property->getEdgeValue(e->asEdge()));
}

void QStringProperty::setNodeValue(const QNode* n, const QString* v) {
        _property->setNodeValue(n->asNode(), v->toStdString());
}

void QStringProperty::setEdgeValue(const QEdge* e, const QString* v) {
        _property->setEdgeValue(e->asEdge(), v->toStdString());
}

void QStringProperty::setAllNodeValue(const QString* v) {
        _property->setAllNodeValue(v->toStdString());
}

void QStringProperty::setAllEdgeValue(const QString* v) {
        _property->setAllEdgeValue(v->toStdString());
}
