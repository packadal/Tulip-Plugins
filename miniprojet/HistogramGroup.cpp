/*
 * HistogramViewer.cpp
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#include "HistogramGroup.h"

#include <iostream>

HistogramGroup::HistogramGroup(IData<float>* graphic)
:_graphic(graphic)
{
	updateGroup();
}

void HistogramGroup::updateGroup()
{
	addToGroup(new QGraphicsLineItem(
			QLine(0, _graphic->getYMin(), 0, _graphic->getYMax())));
	addToGroup(new QGraphicsLineItem(
			QLine(0, 0, _graphic->getXMax(), 0)));

	const int rectWidth = 5;
	for(unsigned int i = 0; i < _graphic->size(); ++i)
	{
//		int x = _graphic->getX(i);
		int y = _graphic->getY(i);
		addToGroup(new QGraphicsRectItem(rectWidth*2*i, 0, rectWidth, -y));
	}
}
