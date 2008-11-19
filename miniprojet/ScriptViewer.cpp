/*
 * ScriptViewer.cpp
 *
 *  Created on: 29 oct. 2008
 *      Author: chuet
 */

#include <iostream>

#include <QtScript>
#include <QtScript/QScriptEngine>

#include "CurveGroup.h"
#include "HistogramGroup.h"
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

void ScriptViewer::addGraphic(IData<float>* dat, Graphic<float>* graphic)
{
	QData* data = new Data(dat);
	QScriptValue value = _engine->newQObject(data);
	_engine->globalObject().setProperty("data"+QString::number(_mapGraphics.size()), value);
	Viewer::addGraphic(data, graphic);
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

void ScriptViewer::addCurve(Data* data)
{
	Graphic<float>* g = new CurveGroup(data);
	addGraphic(data, g);
}

void ScriptViewer::addHistogram(Data* data)
{
	Graphic<float>* g = new HistogramGroup(data);
	addGraphic(data, g);
}
