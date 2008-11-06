#include <iostream>

#include "Viewer.h"
#include "Data.h"

Viewer::Viewer() :
	QWidget(), _scene(new QGraphicsScene()), _view(new QGraphicsView(_scene)), _axis(0)
{
}

Viewer::Viewer(IData<float>* data, Graphic<float>* graphic) :
	QWidget(), _scene(new QGraphicsScene()), _view(new QGraphicsView(_scene)), _axis(0)
{
	addGraphic(data, graphic);
}

void Viewer::addGraphic(IData<float>* data, Graphic<float>* graphic)
{
	std::pair<IData<float>*, Graphic<float>*> pair(data, graphic);
	_mapGraphics.insert(pair);
	data->addObserver(this);
	update(data);
}

void Viewer::setData(IData<float>* data, Graphic<float>* graphic)
{
	for(std::multimap<IData<float>*, Graphic<float>*>::iterator it = _mapGraphics.begin(); it != _mapGraphics.end(); ++it)
	{
		if(it->second == graphic)
		{
			_mapGraphics.erase(it);
			continue;
		}
	}
	_mapGraphics.insert(std::pair<IData<float>*, Graphic<float>*>(data, graphic));
	graphic->setData(data);
	data->addObserver(this);
	update(data);
}

std::set<Graphic<float>*> Viewer::getGraphics(IData<float>* data)
{
	std::set<Graphic<float>*> result;
	for(std::multimap<IData<float>*, Graphic<float>*>::const_iterator it = _mapGraphics.lower_bound(data); it != _mapGraphics.upper_bound(data); it++)
	{
		result.insert(it->second);
	}
	return result;
}

void Viewer::removeGraphic(IData<float>* data, Graphic<float>* graphic)
{
	for(std::multimap<IData<float>*, Graphic<float>*>::iterator it = _mapGraphics.lower_bound(data); it != _mapGraphics.upper_bound(data); it++)
	{
		if(it->second == graphic && _scene->items().contains(it->second))
		{
			_scene->removeItem(it->second);
			_mapGraphics.erase(it);
		}
	}
	update(data);
}

void Viewer::update(Observable* subject)
{
	updateAxis();
	for(std::multimap<IData<float>*, Graphic<float>*>::iterator it = _mapGraphics.lower_bound((IData<float>*)(subject)); it != _mapGraphics.upper_bound((IData<
	        float>*)(subject)); it++)
	{
		if(_scene->items().contains(it->second))
			_scene->removeItem(it->second);
		it->second->setData(it->first);
		_scene->addItem(it->second);
	}
}

void Viewer::updateAxis()
{
	if (_axis != 0)
		_scene->removeItem(_axis);

	float xmin = 0., xmax = 0., ymin = 0., ymax = 0.;
	for(std::multimap<IData<float>*, Graphic<float>*>::const_iterator it = _mapGraphics.begin(); it != _mapGraphics.end(); it++)
	{
		if(it->first->getXMin() < xmin)
			xmin = it->first->getXMin();
		if(it->first->getYMin() < ymin)
			ymin = it->first->getYMin();
		if(it->first->getXMax() > xmax)
			xmax = it->first->getXMax();
		if(it->first->getYMax() > ymax)
			ymax = it->first->getYMax();
	}

	_axis = new QGraphicsItemGroup();
	_axis->addToGroup(new QGraphicsLineItem(xmin, 0, xmax, 0));
	_axis->addToGroup(new QGraphicsLineItem(xmax - 2, -2, xmax, 0));
	_axis->addToGroup(new QGraphicsLineItem(xmax - 2, 2, xmax, 0));
	_axis->addToGroup(new QGraphicsLineItem(0, -ymin, 0, -ymax));
	_axis->addToGroup(new QGraphicsLineItem(-2, -ymax + 2, 0, -ymax));
	_axis->addToGroup(new QGraphicsLineItem(2, -ymax + 2, 0, -ymax));

	_scene->addItem(_axis);
}

//void Viewer::paintEvent(QPaintEvent* event)
//{
//	QPainter painter(this);
//
////	painter.setColor
////	painter.drawLine(width())
//	painter.setPen(QPen(QColor(255, 0, 0)));
//	painter.drawLine(width()-50, height()-50, width()+50, height()+50);
//
//	int i = 0;
//	for (std::multimap<IData<float>*, Graphic<float>* >::const_iterator it = _mapGraphics.begin();
//		it != _mapGraphics.end();//
//		it++)
//	{
//
//		painter.setPen(QPen(it->second->getColor()));
//		painter.drawLine(width()-50, height()-50, width()+50, height()+50);
//
//		i++;
//	}
//
//}

void Viewer::show()
{
	_view->show();
}
