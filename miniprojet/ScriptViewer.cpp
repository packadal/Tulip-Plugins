#include <iostream>

#include <QtScript>
#include <QtScript/QScriptEngine>

#include "ScriptViewer.h"

using namespace std;

ScriptViewer::ScriptViewer()
:Viewer(), _engine(new QScriptEngine())
{
	ui.setupUi(this);
	ui.verticalLayout->addWidget(_view);

	QScriptValue value = _engine->newQObject(this);
	_engine->globalObject().setProperty("viewer", value);

	QScriptValue ctor = _engine->newFunction(dataFactory);
	_engine->globalObject().setProperty("Data", ctor);

	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(evaluate()));
	connect(ui.textEdit, SIGNAL(textChanged()), this, SLOT(check()));
}

ScriptViewer::~ScriptViewer()
{
	delete _engine;
}

void ScriptViewer::check()
{
	ui.pushButton->setEnabled(_engine->canEvaluate(ui.textEdit->toPlainText()));
}

void ScriptViewer::evaluate()
{
	_engine->evaluate(ui.textEdit->toPlainText());
	if(_engine->hasUncaughtException())
	{
		ui.label->setText(_engine->uncaughtException().toString());
		cout << qPrintable(_engine->uncaughtException().toString()) << endl;
	}
	else
		ui.label->setText("");
}

void ScriptViewer::refresh()
{
	Viewer::update();
}

QScriptValue ScriptViewer::addCurve(Data* data)
{
	CurveGroup *curve = new CurveGroup(data);
	addGraphic(data, curve);
	return _engine->newQObject(curve, QScriptEngine::ScriptOwnership);
}

QScriptValue ScriptViewer::addHistogram(Data* data)
{
	HistogramGroup *histogram = new HistogramGroup(data);
	addGraphic(data, histogram);
	return _engine->newQObject(histogram, QScriptEngine::ScriptOwnership);
}

QScriptValue dataFactory(QScriptContext *context, QScriptEngine *engine)
{
	(void) context; //to avoid a warning, we need this function signature
    QObject *object = new Data();
    return engine->newQObject(object, QScriptEngine::ScriptOwnership);
}
