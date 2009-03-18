#include "QLayoutProperty.h"
#include "QGraph.h"

QLayoutProperty::QLayoutProperty(const QGraph* g) {
        _property = new tlp::LayoutProperty(g->asGraph());
}

QLayoutProperty::QLayoutProperty(tlp::LayoutProperty* p) :
        _property(p) {
}

QLayoutProperty::~QLayoutProperty() {
        delete _property;
}

tlp::LayoutProperty* QLayoutProperty::asProperty() {
        return _property;
}

QSize3D* QLayoutProperty::getNodeDefaultValue() {
        return new QSize3D(_property->getNodeDefaultValue());
}

QSize3DVector* QLayoutProperty::getEdgeDefaultValue() {
        return new QSTDVECTOR(Size3D, tlp::Coord)(_property->getEdgeDefaultValue());
}

QSize3D* QLayoutProperty::getNodeValue(const QNode* n) {
        return new QSize3D(_property->getNodeValue(n->asNode()));
}

QSize3DVector* QLayoutProperty::getEdgeValue(const QEdge* e) {
        return new QSTDVECTOR(Size3D, tlp::Coord)(_property->getEdgeValue(e->asEdge()));
}

void QLayoutProperty::setNodeValue(const QNode* n, QSize3D* v) {
        _property->setNodeValue(n->asNode(), v->asCoord());
}

void QLayoutProperty::setEdgeValue(const QEdge* e, const QSize3DVector* v) {
        _property->setEdgeValue(e->asEdge(), v->asCoord());
}

void QLayoutProperty::setAllNodeValue(QSize3D* v) {
        _property->setAllNodeValue(v->asCoord());
}

void QLayoutProperty::setAllEdgeValue(const QSize3DVector* v) {
        _property->setAllEdgeValue(v->asCoord());
}
