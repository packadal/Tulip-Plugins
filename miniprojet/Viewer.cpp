#include "Viewer.h"

Viewer::Viewer()
:QWidget(), _scene(new QGraphicsScene), _view(new QGraphicsView(_scene))
{
	_view->show();
}

Viewer::Viewer(Graphic<float>* graphic)
:QWidget(), _scene(new QGraphicsScene), _view(new QGraphicsView(_scene)), _graphic(graphic)
{
	_scene->addItem(_graphic);
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
}
