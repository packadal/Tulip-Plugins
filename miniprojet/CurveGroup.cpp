#include "CurveGroup.h"

#include <QGraphicsScene>
#include <QPen>

CurveGroup::CurveGroup() :
	_color(QColor(0, 0, 0))
{}

CurveGroup::CurveGroup(IData<float>* data) :
	_color(QColor(0, 0, 0))
{
	setData(data);
}

void CurveGroup::setData(IData<float>* data)
{
	QList<QGraphicsItem*> list = childItems();

	for(QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it)
	{
		removeFromGroup(*it);
		if(scene() != 0)
			scene()->removeItem(*it);
	}

	QGraphicsLineItem* qgi;
	for(unsigned int i = 1; i < data->size(); i++)
	{
		qgi = new QGraphicsLineItem(data->getX(i - 1), -data->getY(i - 1), data->getX(i), -data->getY(i));
		qgi->setPen(QPen(_color));
		addToGroup(qgi);
	}
}
