/*
 * QGraphProperty.cpp
 *
 *  Created on: 18 févr. 2009
 *      Author: lburelou
 */

#include "QGraphProperty.h"

QGraphProperty::QGraphProperty() {
	// TODO Auto-generated constructor stub

}

QGraphProperty::~QGraphProperty() {
	delete _property;
}

QGraphProperty::QGraphProperty(QGraph* g){
	_property = new tlp::GraphProperty(g->asGraph());
}

QGraphProperty::QGraphProperty(tlp::GraphProperty* p)
:_property(p)
{

}

tlp::GraphProperty* QGraphProperty::asGraphProperty(){
	return _property;
}

QGraph* QGraphProperty::getNodeDefaultValue(){
	return new QGraph(_property->getNodeDefaultValue());
}

QGraph* QGraphProperty::getEdgeDefaultValue(){
	//return new QGraph(_property->getEdgeDefaultValue());
}

QGraph* QGraphProperty::getNodeValue(const QNode* n ){
	return new QGraph(_property->getNodeValue(n->asNode()));
}

QGraph* QGraphProperty::getEdgeValue(const QEdge* e){
	//return new QGraph(_property->getEdgeValue(e->asEdge()));
}

void QGraphProperty::setNodeValue(const QNode* n, const QGraph* &v){
	//_property->setNodeValue(n->asNode(), v);
}

void QGraphProperty::setEdgeValue(const QEdge* e, const QGraph* &v){
	//_property->setEdgeValue(e->asEdge(), v);
}

void QGraphProperty::setAllNodeValue(const QGraph* &v){
	//_property->setAllNodeValue(v);
}

void QGraphProperty::setAllEdgeValue(const QGraph* &v){
	//_property->setAllEdgeValue(v);
}
