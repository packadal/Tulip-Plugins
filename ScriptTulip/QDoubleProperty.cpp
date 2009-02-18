/*
 * QDoubleProperty.cpp
 *
 *  Created on: 18 févr. 2009
 *      Author: lburelou
 */

#include "QDoubleProperty.h"

QDoubleProperty::QDoubleProperty() {
	// TODO Auto-generated constructor stub

}

QDoubleProperty::~QDoubleProperty() {
	delete _property;
}

QDoubleProperty::QDoubleProperty(QGraph* g){
	_property = new tlp::DoubleProperty(g->asGraph());
}

QDoubleProperty::QDoubleProperty(tlp::DoubleProperty* p)
:_property(p)
{
}

tlp::DoubleProperty* QDoubleProperty::asDoubleProperty(){
	return _property;
}

double QDoubleProperty::getNodeDefaultValue(){
	return _property->getNodeDefaultValue();
}

double QDoubleProperty::getEdgeDefaultValue(){
	return _property->getEdgeDefaultValue();
}

double QDoubleProperty::getNodeValue(const QNode* n ){
	return _property->getNodeValue(n->asNode());
}

double QDoubleProperty::getEdgeValue(const QEdge* e){
	return _property->getEdgeValue(e->asEdge());
}

void QDoubleProperty::setNodeValue(const QNode* n, const double &v){
	_property->setNodeValue(n->asNode(), v);
}

void QDoubleProperty::setEdgeValue(const QEdge* e, const double &v){
	_property->setEdgeValue(e->asEdge(), v);
}

void QDoubleProperty::setAllNodeValue(const double &v){
	_property->setAllNodeValue(v);
}

void QDoubleProperty::setAllEdgeValue(const double &v){
	_property->setAllEdgeValue(v);
}
