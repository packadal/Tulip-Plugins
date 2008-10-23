/*
 * HistogramViewer.cpp
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#include "HistogramGroup.h"

#include <iostream>

HistogramGroup::HistogramGroup(IData<float>* graphic)
:_graphic(graphic), _scale(1)
{
	updateGroup();
}

HistogramGroup::~HistogramGroup()
{
	delete _graphic;
}

void HistogramGroup::updateGroup()
{
	QList<QGraphicsItem*> list = QGraphicsItemGroup::children();
	for(QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it)
		removeFromGroup(*it);
	const int rectWidth = 5;
	for(unsigned int i = 0; i < _graphic->size(); ++i)
	{
//		int x = _graphic->getX(i);
		int y = _graphic->getY(i);
		addToGroup(new QGraphicsRectItem(rectWidth*2*i, 0, rectWidth, -y));
	}
}
