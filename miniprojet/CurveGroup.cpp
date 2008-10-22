/*
 * CurveGroup.cpp
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#include "CurveGroup.h"

CurveGroup::CurveGroup(IData<float>* graphic)
{
	setGraphic(graphic);
}

void CurveGroup::setGraphic(IData<float>* graphic)
{
	_array = graphic;
	QGraphicsLineItem* qgi;
	for(unsigned int i = 1; i < _array->size(); i++)
	{
		qgi = new QGraphicsLineItem(_array->getX(i-1), _array->getY(i-1), _array->getX(i), _array->getY(i));
		addToGroup(qgi);
	}
}
