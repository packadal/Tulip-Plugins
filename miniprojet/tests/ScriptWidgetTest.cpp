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
	cg->setScale(10);
	hg->setScale(10);
	new Viewer(cg);
	new Viewer(hg);
	d->add(70, -40);

	QScriptEngine* engine = new QScriptEngine();

	QScriptValue value = engine->newQObject(hg);
	engine->globalObject().setProperty("histo", value);

	engine->evaluate("histo.setScale(10);");
}
