/*
 * CurveViewer.cpp
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#include "CurveViewer.h"

CurveViewer::CurveViewer()
{
}

void CurveViewer::setGraphic(IData<float>* array)
{
	_array = array;
	QGraphicsLineItem* qgi;
	for(unsigned int i = 1; i < _array->size(); i++)
	{
		qgi = new QGraphicsLineItem(_array->getX(i-1), _array->getY(i-1), _array->getX(i), _array->getY(i));
		addToGroup(qgi);
	}
}

void CurveViewer::setScale(float scale)
{
	_scale=scale;
}
