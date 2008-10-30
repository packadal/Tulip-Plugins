/*
 * ScriptViewer.cpp
 *
 *  Created on: 29 oct. 2008
 *      Author: chuet
 */

#include "ScriptViewer.h"
#include "Data.h"
#include <iostream>

using namespace std;

ScriptViewer::ScriptViewer()
:Viewer(), _engine(new QScriptEngine())
{
	ui.setupUi(this);
//	ui.graphicsView = _view;
	ui.verticalLayout->addWidget(_view);


	/*
	QScriptValue value = _engine->newQObject(ui.pushButton);
	_engine->globalObject().setProperty("button", value);

	value = _engine->newQObject(data);
	_engine->globalObject().setProperty("data", value);

	QData* d = new DataScript(_engine);
	_engine->globalObject().setProperty("Data", d->constructor());*/


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
//	cout << "check()" << _engine->canEvaluate(ui.textEdit->toPlainText()) << ":" << qPrintable(ui.textEdit->toPlainText()) << endl;
	ui.pushButton->setEnabled(_engine->canEvaluate(ui.textEdit->toPlainText()));
}

void ScriptViewer::evaluate()
{
//	ui.pushButton->setText("MWAHAHA");
	_engine->evaluate(ui.textEdit->toPlainText());
	if(_engine->hasUncaughtException())
	{
		ui.label->setText(_engine->uncaughtException().toString());
		cout << qPrintable(_engine->uncaughtException().toString()) << endl;
	}
	else
		ui.label->setText("");
}

/*
void ScriptViewer::addGraphic()
{
	QScriptValue q;
	return q;
}*/
