/*
 * CurveGroup.cpp
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#include "CurveGroup.h"

CurveGroup::CurveGroup(IData<float>* graphic)
{
	setGraphic(graphic);
	_scale = 1;
	_graphic->addObserver(this);
}

CurveGroup::~CurveGroup()
{
	delete _graphic;
}

void CurveGroup::updateGroup()
{
	QGraphicsLineItem* qgi;
	for(unsigned int i = 1; i < _graphic->size(); i++)
	{
		qgi = new QGraphicsLineItem(_graphic->getX(i-1), -_graphic->getY(i-1), _graphic->getX(i), -_graphic->getY(i));
		addToGroup(qgi);
	}
}

void CurveGroup::update(Observable * subject)
{
	QList<QGraphicsItem*> list = children();
	for(QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it)
		removeFromGroup(*it);
	updateGroup();
}

