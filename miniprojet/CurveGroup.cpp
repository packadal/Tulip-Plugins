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
	_scale = 1;
}

void CurveGroup::setGraphic(IData<float>* graphic)
{
	_graphic = graphic;
	QGraphicsLineItem* qgi;
	for(unsigned int i = 1; i < _graphic->size(); i++)
	{
		qgi = new QGraphicsLineItem(_graphic->getX(i-1), -_graphic->getY(i-1), _graphic->getX(i), -_graphic->getY(i));
		addToGroup(qgi);
	}
}

CurveGroup::~CurveGroup()
{
	delete(_graphic);
}
