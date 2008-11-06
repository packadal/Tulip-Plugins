/*
 * HistogramViewer.cpp
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#include "HistogramGroup.h"

#include <QGraphicsScene>
#include <iostream>
#include <algorithm>
#include <set>
#include <QPen>

HistogramGroup::HistogramGroup(IData<float>* data) :
	_color(QColor(0, 0, 0)), _rectWidth(1)
{
	setData(data);
}

void HistogramGroup::setData(IData<float>* data)
{
	QList<QGraphicsItem*> list = childItems();

	for(QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		removeFromGroup(*it);
		if(scene() != 0)
			scene()->removeItem(*it);
	}

	float espaceMin = INT_MAX, difference = 0, lastDiff = 0;
	std::set<float> sortedX;
	for(unsigned int i = 0; i < data->size(); ++i)
		sortedX.insert(data->getX(i));

	for(std::set<float>::const_iterator it = sortedX.begin(); it != sortedX.end(); ++it)
	{
		if(it != sortedX.begin())
		{
			difference = *it - lastDiff;
			espaceMin = std::min(espaceMin, difference);
		}
		lastDiff = *it;
	}
	_rectWidth = espaceMin/2;

	for(unsigned int i = 0; i < data->size(); ++i)
	{
		int x = data->getX(i);
		int y = data->getY(i);
		QGraphicsRectItem* rect = new QGraphicsRectItem(x - (_rectWidth / 2), 0, _rectWidth, -y);
		rect->setBrush(QBrush(_color));
		addToGroup(rect);
	}
}
