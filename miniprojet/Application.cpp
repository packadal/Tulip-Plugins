#include <QApplication>

#include "Application.h"

#include "Data.h"
#include "CurveGroup.h"
#include "HistogramGroup.h"
#include "ScriptViewer.h"

Application::Application()
{
	// Before instanciate the viewer...
	IData<float>* d = new Data();
	d->add(10, 3);
	d->add(30, 4);
	d->add(40, -10);
	CurveGroup* cg = new CurveGroup(d);

	// Display the viewer window
	ScriptViewer* v1 = new ScriptViewer();
	v1->show();
	v1->scale(3);

	// ...or after
	v1->addGraphic(d, cg);
	d->add(50, 6);
	d->add(60, 12);
	cg->setColor(QColor(50, 0, 255, 255));
	HistogramGroup* hg = new HistogramGroup(d);
	hg->setColor(QColor(255, 0, 0, 100));
	v1->addGraphic(d, hg);
	d->add(70, -40);

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
