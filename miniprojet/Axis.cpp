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

	//Y axis
	addToGroup(new QGraphicsLineItem(xmin, 0, xmax, 0));
	//Y axis arrow
	addToGroup(new QGraphicsLineItem(xmax - 2, -2, xmax, 0));
	addToGroup(new QGraphicsLineItem(xmax - 2, 2, xmax, 0));

	//X axis
	addToGroup(new QGraphicsLineItem(0, -ymin, 0, -ymax));
	//X axis arrow
	addToGroup(new QGraphicsLineItem(-2, -ymax + 2, 0, -ymax));
	addToGroup(new QGraphicsLineItem(2, -ymax + 2, 0, -ymax));

	float nbSpace = xmax - xmin;
	for(float i = xmin; i < xmax; i++)
	{
		if((int)i % 10 == 0 && i != 0)
		{
			addToGroup(new QGraphicsLineItem(i, 2, i, -2));
			addtext(i - 4.5, 2., i, 2);
		}
		else if((int)i % 5 == 0 && nbSpace < 500)
		{
			addToGroup(new QGraphicsLineItem(i, 1, i, -1));
			//addtext(i-3.5, 2., i, 1);
			//gets in the way of lisibility
		}
		else if(nbSpace < 100)
		{
			addToGroup(new QGraphicsLineItem(i, 0.5, i, -0.5));
		}
	}

	nbSpace = ymin - ymax;
	for(float i = -ymin; i > -ymax; i--)
	{
		if((int)i % 10 == 0)
		{
			addToGroup(new QGraphicsLineItem(2, i, -2, i));
			addtext(-8, i - 4.5, -i, 2);
		}
		else if((int)i % 5 == 0 && nbSpace < 500)
		{
			addToGroup(new QGraphicsLineItem(1, i, -1, i));
		}
		else if(nbSpace < 100)
		{
			addToGroup(new QGraphicsLineItem(0.5, i, -0.5, i));
		}
	}
}

void Axis::addtext(float x, float y, int i, int fontSize)
{
	QGraphicsTextItem* text = new QGraphicsTextItem();
	text->setFont(QFont("Helvetica [Cronyx]", fontSize));
	text->setPlainText(QString::number(i));
	text->setPos(x, y);
	addToGroup(text);
}
