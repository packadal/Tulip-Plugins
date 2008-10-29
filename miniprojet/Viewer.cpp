#include <iostream>

#include "Viewer.h"

Viewer::Viewer(QWidget* parent)
:QWidget(), _scene(new QGraphicsScene(parent)), _view(new QGraphicsView(_scene))
{
	_view->show();
}

Viewer::Viewer(IData<float>* data, Graphic<float>* graphic)
:QWidget(), _scene(new QGraphicsScene), _view(new QGraphicsView(_scene))
{
	addGraphic(data, graphic);
	_view->show();
}


//void Viewer::addGraphic(Graphic<float>* graphic)
//{
//	_graphic = graphic;
//	_scene->addItem(_graphic);
//	setAxes();
//}

void Viewer::addGraphic(IData<float>* data, Graphic<float>* graphic)
{
	std::pair<IData<float>*, Graphic<float>*> pair(data, graphic);
	_mapGraphics.insert(pair);
	update((Observable *)(data));
}

std::set<Graphic<float>*> Viewer::getGraphics(IData<float>* data)
{
	std::set<Graphic<float>*> result;
	for (
		std::multimap<IData<float>*, Graphic<float>* >::const_iterator it = _mapGraphics.lower_bound(data);
		it != _mapGraphics.upper_bound(data);
		it++
	) {
		result.insert(it->second);
	}
	return result;
}

void Viewer::removeGraphic(IData<float> * data, Graphic<float>* graphic)
{
	for (
		std::multimap<IData<float>*, Graphic<float>* >::iterator it = _mapGraphics.lower_bound(data);
		it != _mapGraphics.upper_bound(data);
		it++
	) {
		if (it->second == graphic)
			_mapGraphics.erase(it);
	}
	update((Observable *)(data));
}

//void Viewer::setAxes()
//{
//
//	float xmin,xmax, ymin, ymax;
//	IData<float>* id = _graphic->getGraphic();
//	xmin = id->getXMin();
//	xmax = id->getXMax();
//	ymin = id->getYMin();
//	ymax = id->getYMax();
//	QGraphicsItemGroup* axes = new QGraphicsItemGroup();
//	axes->addToGroup(new QGraphicsLineItem(xmin, 0, xmax, 0));
//	axes->addToGroup(new QGraphicsLineItem(0, -ymin, 0, -ymax));
//	_scene->addItem(axes);
//	_view->show();
//}

void Viewer::update(Observable * subject)
{

}

