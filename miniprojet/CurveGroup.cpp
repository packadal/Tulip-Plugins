/*
 * CurveGroup.cpp
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#include "CurveGroup.h"

CurveGroup::CurveGroup(IData<float>* data)
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
		addToGroup(qgi);
	}
}

