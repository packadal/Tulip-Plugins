/*
 * QLayoutProperty.cpp
 *
 *  Created on: 18 févr. 2009
 *      Author: lburelou
 */

#include "QLayoutProperty.h"

QLayoutProperty::QLayoutProperty() {
	// TODO Auto-generated constructor stub

}

QLayoutProperty::~QLayoutProperty() {
	// TODO Auto-generated destructor stub
}

QLayoutProperty::QLayoutProperty(QGraph*){

}

QLayoutProperty::QLayoutProperty(tlp::LayoutProperty*){

}

tlp::LayoutProperty* QLayoutProperty::asLayoutProperty(){

}

QPoint* QLayoutProperty::getNodeDefaultValue(){

}

QLine* QLayoutProperty::getEdgeDefaultValue(){

}

QPoint* QLayoutProperty::getNodeValue(const QNode* n ){

}

QLine* QLayoutProperty::getEdgeValue(const QEdge* e){

}

void QLayoutProperty::setNodeValue(const QNode* n, const QPoint* &v){

}

void QLayoutProperty::setEdgeValue(const QEdge* e, const QLine* &v){

}

void QLayoutProperty::setAllNodeValue(const QPoint* &v){

}

void QLayoutProperty::setAllEdgeValue(const QLine* &v){

}
