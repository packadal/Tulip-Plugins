/*
 * HistogramViewer.cpp
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#include "HistogramGroup.h"

#include <iostream>

HistogramGroup::HistogramGroup(IData<float>* data)
{
	setData(data);
}

void HistogramGroup::setData(IData<float>* data)
{
	QList<QGraphicsItem*> list = QGraphicsItemGroup::children();
	for(QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it)
		removeFromGroup(*it);
	const int rectWidth = 5;
	for(unsigned int i = 0; i < data->size(); ++i)
	{
//		int x = data->getX(i);
		int y = data->getY(i);
		addToGroup(new QGraphicsRectItem(rectWidth*2*i, 0, rectWidth, -y));
	}
}
