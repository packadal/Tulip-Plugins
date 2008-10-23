#ifndef VIEWER_H_
#define VIEWER_H_

#include "Graphic.h"

#include <QGraphicsScene>
#include <QGraphicsView>

class Viewer : public QWidget, public Observer
{
public:
	Viewer();
	Viewer(Graphic<float>*);
	~Viewer();

	void setGraphic(Graphic<float>*);
	inline Graphic<float>* getGraphic() { return _graphic; }

private:
	void setAxes();
	QGraphicsScene* _scene; //do not delete, it's Qt's job
	QGraphicsView* _view; //do not delete, it's Qt's job
	Graphic<float>* _graphic;

	void update(Observable * subject);
};

#endif /* VIEWER_H_ */
