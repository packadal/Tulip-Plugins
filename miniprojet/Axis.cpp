/*
 * Axis.cpp
 *
 *  Created on: 6 nov. 2008
 *      Author: chuet
 */

#include "Axis.h"

#include <QGraphicsLineItem>
#include <QGraphicsScene>

Axis::Axis()
{
}

void Axis::updateAxis(float xmin, float xmax, float ymin, float ymax)
{
	QList<QGraphicsItem*> list = childItems();
	for(QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		removeFromGroup(*it);
			scene()->removeItem(*it);
	}

	//X axis
	addToGroup(new QGraphicsLineItem(xmin, 0, xmax, 0));
	//X axis arrow
	addToGroup(new QGraphicsLineItem(xmax - 2, -2, xmax, 0));
	addToGroup(new QGraphicsLineItem(xmax - 2, 2, xmax, 0));

	//Y axis
	addToGroup(new QGraphicsLineItem(0, -ymin, 0, -ymax));
	//Y axis arrow
	addToGroup(new QGraphicsLineItem(-2, -ymax + 2, 0, -ymax));
	addToGroup(new QGraphicsLineItem(2, -ymax + 2, 0, -ymax));


}
