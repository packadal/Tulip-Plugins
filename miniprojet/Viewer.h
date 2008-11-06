#ifndef VIEWER_H_
#define VIEWER_H_

#include "Graphic.h"
#include "Axis.h"
#include "GraphicLegend.h"

#include <QGraphicsScene>
#include <QGraphicsView>

class Viewer : public QWidget, public Observer
{
public:
	Viewer();
	Viewer(IData<float>*, Graphic<float>*);

	void addGraphic(IData<float>*, Graphic<float>*);
	std::set<Graphic<float>*> getGraphics(IData<float>*);
	void removeGraphic(IData<float>*, Graphic<float>*);
	void setData(IData<float>*, Graphic<float>*);

	void show();
	inline void scale(float factor) { _view->scale(factor, factor); }

protected:
	void updateAxis();
	//void paintEvent(QPaintEvent* event);
	QGraphicsScene* _scene; //do not delete, it's Qt's job
	QGraphicsView* _view; //do not delete, it's Qt's job
	Axis* _axis; //do not delete, it's Qt's job
	GraphicLegend<float>* _graphicLegend;

	void update(Observable * subject);

	std::multimap<IData<float>*, Graphic<float>* > _mapGraphics;
};

#endif /* VIEWER_H_ */
