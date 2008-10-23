#include <iostream>

#include "Viewer.h"

Viewer::Viewer()
:QWidget(), _scene(new QGraphicsScene), _view(new QGraphicsView(_scene))
{
	_view->show();
}

Viewer::Viewer(Graphic<float>* graphic)
:QWidget(), _scene(new QGraphicsScene), _view(new QGraphicsView(_scene)), _graphic(graphic)
{
	_graphic->getGraphic()->addObserver(this);
	_scene->addItem(_graphic);
	setAxes();
	_view->show();
}

Viewer::~Viewer()
{
	delete _graphic;
}

void Viewer::setGraphic(Graphic<float>* graphic)
{
	_graphic = graphic;
	_scene->addItem(_graphic);
	setAxes();
}

void Viewer::setAxes()
{

	float xmin,xmax, ymin, ymax;
	IData<float>* id = _graphic->getGraphic();
	xmin = id->getXMin();
	xmax = id->getXMax();
	ymin = id->getYMin();
	ymax = id->getYMax();
	QGraphicsItemGroup* axes = new QGraphicsItemGroup();
	axes->addToGroup(new QGraphicsLineItem(xmin, 0, xmax, 0));
	axes->addToGroup(new QGraphicsLineItem(0, ymin, 0, ymax));
	_scene->addItem(axes);
	_view->show();
}

void Viewer::update(Observable * subject)
{
	QList<QGraphicsItem*> list = _graphic->children();
	for(QList<QGraphicsItem*>::iterator it = list.begin(); it != list.end(); ++it)
		_graphic->removeFromGroup(*it);
	_graphic->updateGroup();
}

