#include <iostream>

#include "Viewer.h"
#include "Data.h"

Viewer::Viewer() :
	QWidget(), _scene(new QGraphicsScene()), _view(new QGraphicsView(_scene)), _axis(new Axis())
{
	_graphicLegend = new GraphicLegend<float> ();
}

Viewer::Viewer(IData<float>* data, Graphic<float>* graphic) :
	QWidget(), _scene(new QGraphicsScene()), _view(new QGraphicsView(_scene)), _axis(new Axis())
{
	_graphicLegend = new GraphicLegend<float> ();
	addGraphic(data, graphic);
}

void Viewer::addGraphic(IData<float>* data, Graphic<float>* graphic)
{
	if(_mapGraphics.size() == 0)
		_scene->addItem(_axis);

	std::pair<IData<float>*, Graphic<float>*> pair(data, graphic);
	_mapGraphics.insert(pair);
	_graphicLegend->addGraphic(graphic);
	data->addObserver(this);
	update(data);
}

void Viewer::changeGraphic(Graphic<float>* oldGraphic, Graphic<float>* newGraphic)
{
	IData<float> *data = 0;
	for(std::multimap<IData<float>*, Graphic<float>*>::iterator it = _mapGraphics.begin(); it != _mapGraphics.end(); ++it)
	{
		if(it->second == oldGraphic)
		{
			data = it->first;
		}
	}

	if (data)
	{
		removeGraphic(data, oldGraphic);
		addGraphic(data, newGraphic);
	}
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
	_graphicLegend->removeGraphic(graphic);
	for(std::multimap<IData<float>*, Graphic<float>*>::iterator it = _mapGraphics.lower_bound(data); it != _mapGraphics.upper_bound(data); it++)
	{
		if(it->second == graphic && _scene->items().contains(it->second))
		{
			_scene->removeItem(it->second);
			_mapGraphics.erase(it);
		}
	}
	update(data);
	if(_mapGraphics.size() == 0)
		_scene->removeItem(_axis);
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
	float xmin = -10., xmax = 10., ymin = -10., ymax = 10.;
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

	_axis->updateAxis(xmin, xmax, ymin, ymax);
}

void Viewer::show()
{
	_view->show();
}
