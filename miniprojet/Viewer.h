#ifndef VIEWER_H_
#define VIEWER_H_

#include "Graphic.h"

#include <QGraphicsScene>
#include <QGraphicsView>

class Viewer : public QWidget
{
public:
	Viewer();
	Viewer(Graphic<float>*);

private:
	QGraphicsScene* _scene;
	QGraphicsView* _view;
	Graphic<float>* _graphic;
};

#endif /* VIEWER_H_ */
