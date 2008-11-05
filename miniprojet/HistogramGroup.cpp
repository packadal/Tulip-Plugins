/*
 * HistogramViewer.cpp
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#include "HistogramGroup.h"

#include <iostream>
#include <QPen>

HistogramGroup::HistogramGroup(IData<float>* data)
: _color(QColor(0, 0, 0))
{
	setData(data);
}

void HistogramGroup::setData(IData<float>* data)
{
	QList<QGraphicsItem*> list = childItems();
	for(QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it)
		removeFromGroup(*it);
	const int rectWidth = 5;
	for(unsigned int i = 0; i < data->size(); ++i)
	{
		int x = data->getX(i);
		int y = data->getY(i);
		QGraphicsRectItem* rect = new QGraphicsRectItem(x-(rectWidth/2), 0, rectWidth, -y);
		rect->setPen(QPen(_color));
		addToGroup(rect);
	}
}
