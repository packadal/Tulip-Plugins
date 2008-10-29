#include <iostream>

#include "Viewer.h"

Viewer::Viewer(QWidget* parent)
:QWidget(parent), _scene(new QGraphicsScene()), _view(new QGraphicsView(_scene))
{
	_view->show();
}

Viewer::Viewer(IData<float>* data, Graphic<float>* graphic, QWidget* parent)
:QWidget(parent), _scene(new QGraphicsScene()), _view(new QGraphicsView(_scene))
{
	std::cout << "totototocacacaca1" << std::endl;
	addGraphic(data, graphic);
	std::cout << "totototocacacaca2" << std::endl;
	_view->show();
	std::cout << "totototocacacaca3" << std::endl;

}

void Viewer::addGraphic(IData<float>* data, Graphic<float>* graphic)
{
	std::pair<IData<float>*, Graphic<float>*> pair(data, graphic);
	std::cout << "totototocacacaca6" << std::endl;

	_mapGraphics.insert(pair);
	std::cout << "totototocacacaca5" << std::endl;

	update((Observable *)(data));
	std::cout << "totototocacacaca4" << std::endl;


}

std::set<Graphic<float>*> Viewer::getGraphics(IData<float>* data)
{
	std::set<Graphic<float>*> result;
	std::cout << "totototocacacaca" << std::endl;

	for (
		std::multimap<IData<float>*, Graphic<float>* >::const_iterator it = _mapGraphics.lower_bound(data);
		it != _mapGraphics.upper_bound(data);
		it++
	) {
		std::cout << "totototocacacaca" << std::endl;

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
	update((Observable*)(data));
}

void Viewer::update(Observable* subject)
{
	updateAxis();
	for (
		std::multimap<IData<float>*, Graphic<float>* >::iterator it = _mapGraphics.lower_bound((IData<float>*)(subject));
		it != _mapGraphics.upper_bound((IData<float>*)(subject));
		it++
	) {
		it->second->setData(it->first);
		_scene->addItem(it->second);
	}
}

void Viewer::updateAxis()
{
	//if (_axis != 0)
		//_scene->removeItem(_axis);

	float xmin, xmax, ymin, ymax;
	for (
		std::multimap<IData<float>*, Graphic<float>* >::const_iterator it = _mapGraphics.begin();
		it != _mapGraphics.end();
		it++
	) {
		if (it->first->getXMin() < xmin) xmin = it->first->getXMin();
		if (it->first->getYMin() < ymin) ymin = it->first->getYMin();
		if (it->first->getXMax() > xmax) xmax = it->first->getXMax();
		if (it->first->getYMax() > ymax) ymax = it->first->getYMax();
	}

	_axis = new QGraphicsItemGroup();
	_axis->addToGroup(new QGraphicsLineItem(xmin, 0, xmax, 0));
	_axis->addToGroup(new QGraphicsLineItem(0, -ymin, 0, -ymax));
	_scene->addItem(_axis);
	_view->show();
}
