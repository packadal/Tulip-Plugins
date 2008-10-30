/*
 * CurveGroup.cpp
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#include "CurveGroup.h"
#include <QPen>

CurveGroup::CurveGroup(IData<float>* data)
:_color(QColor(0, 0, 0))
{
	setData(data);
}

void CurveGroup::setData(IData<float>* data)
{
	QList<QGraphicsItem*> list = children();
	for(QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it)
		removeFromGroup(*it);
	QGraphicsLineItem* qgi;
	for(unsigned int i = 1; i < data->size(); i++)
	{
		qgi = new QGraphicsLineItem(data->getX(i-1), -data->getY(i-1), data->getX(i), -data->getY(i));
		qgi->setPen(QPen(_color));
		addToGroup(qgi);
	}
}

void CurveGroup::setColor(QColor color)
{
	_color = color;
}

