#include "Viewer.h"

Viewer::Viewer()
:QWidget(), _scene(new QGraphicsScene), _view(new QGraphicsView(_scene))
{
	/*_scene = new QGraphicsScene();
	_view = new QGraphicsView(_scene);*/

}

Viewer::Viewer(Graphic<float>* graphic)
:QWidget(), _scene(new QGraphicsScene), _view(new QGraphicsView(_scene))
{
	_graphic = graphic;
	_scene->addItem(_graphic);
}
