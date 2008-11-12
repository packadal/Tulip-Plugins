#include <QApplication>

#include "Application.h"

#include "Data.h"
#include "CurveGroup.h"
#include "HistogramGroup.h"
#include "Viewer.h"

Application::Application()
{
	IData<float>* d = new Data(),
		*d2 = new Data();
	d->add(10, 3);
	d->add(30, 4);
	d->add(40, -10);
	d->add(50, 6);
	d->add(60, 12);

	d2->add(10, -5);
	d2->add(20, 10);
	d2->add(30, 50);

	CurveGroup* cg = new CurveGroup(d);
	HistogramGroup* hg = new HistogramGroup(d),
		*hg2 = new HistogramGroup(d2);
	hg->setColor(QColor(255, 0, 0, 10));
	hg2->setColor(QColor(0, 255, 0));
	cg->setColor(QColor(0, 0, 255));
	//	cg->setScale(10);
	//	hg->setScale(10);
	Viewer* v1 = new Viewer(d, hg);
	v1->show();
	d->add(-70, -40);
//	v1->addGraphic(d2, hg2);
	v1->addGraphic(d, cg);
	v1->removeGraphic(d, cg);
	v1->addGraphic(d, cg);
	v1->scale(3);

	v1->setData(d2, hg);

	QList<QGraphicsItem*> itemList = hg->scene()->items();
	QList<QGraphicsItem*> items;
	for(int i = 0; i < itemList.size(); i++)
		if(itemList.value(i) == hg)
			items = itemList.value(i)->childItems();

	for(int i = 0; i < items.size(); i++)
	{
		QGraphicsItem* g = items.value(i);
		QGraphicsLineItem* h = dynamic_cast<QGraphicsLineItem*> (g);
		if(h != 0)
		{
			//the coordinates system in Qt have the origin in the upper left corner
			//the conventional cartesian system have the origin in the lower left corner
			//so we invert the Y coordinates
			std::cout << h->line().x1() << std::endl;
			std::cout << h->line().y1() << std::endl;
			std::cout << h->line().x2() << std::endl;
			std::cout << h->line().y2() << std::endl;
		}
	}

/*	QScriptEngine* engine = new QScriptEngine();

	QScriptValue value = engine->newQObject(hg);
	engine->globalObject().setProperty("histo", value);

	engine->evaluate("histo.setScale(10);");*/
}

Application::~Application()
{

}

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	Application appli;

	return app.exec();
}
