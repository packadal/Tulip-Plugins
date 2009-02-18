/*
 * QStringProperty.cpp
 *
 *  Created on: 18 févr. 2009
 *      Author: lburelou
 */

#include "QStringProperty.h"

QStringProperty::QStringProperty() {
	// TODO Auto-generated constructor stub

}

QStringProperty::~QStringProperty() {
	// TODO Auto-generated destructor stub
}

QStringProperty::QStringProperty(QGraph*){

}

QStringProperty::QStringProperty(tlp::StringProperty*){

}

tlp::StringProperty* QStringProperty::asStringProperty(){

}

QString QStringProperty::getNodeDefaultValue(){

}

QString QStringProperty::getEdgeDefaultValue(){

}

QString QStringProperty::getNodeValue(const QNode* n ){

}

QString QStringProperty::getEdgeValue(const QEdge* e){

}

void QStringProperty::setNodeValue(const QNode* n, const QString &v){

}

void QStringProperty::setEdgeValue(const QEdge* e, const QString &v){

}

void QStringProperty::setAllNodeValue(const QString &v){

}

void QStringProperty::setAllEdgeValue(const QString &v){

}
