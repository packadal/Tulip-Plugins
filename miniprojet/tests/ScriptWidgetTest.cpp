#include <QtScript>

#include "ScriptWidgetTest.h"
#include "Viewer.h"
#include "CurveGroup.h"
#include "HistogramGroup.h"
#include "Data.h"

ScriptWidgetTest::ScriptWidgetTest()
{
	IData<float>* d = new Data();
	d->add(10, 3);
	d->add(30, 4);
	d->add(40, -10);
	d->add(50, 6);
	d->add(60, 12);

	CurveGroup* cg = new CurveGroup(d);
	HistogramGroup* hg = new HistogramGroup(d);
//	cg->setScale(10);
//	hg->setScale(10);
	Viewer* v1 = new Viewer(d, cg);
	v1->show();
	Viewer* v2 = new Viewer(d, hg);
	v2->show();
	d->add(70, -40);
	v1->addGraphic(d, hg);
	v1->removeGraphic(d, hg);
	v1->scale(3);
	v2->scale(2);
/*	QScriptEngine* engine = new QScriptEngine();

	QScriptValue value = engine->newQObject(hg);
	engine->globalObject().setProperty("histo", value);

	engine->evaluate("histo.setScale(10);");*/
}
