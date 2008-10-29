/*
 * ScriptViewer.cpp
 *
 *  Created on: 29 oct. 2008
 *      Author: chuet
 */

#include "ScriptViewer.h"

#include <iostream>

using namespace std;

ScriptViewer::ScriptViewer(QData* data, Graphic<float>* graphic)
:Viewer(data, graphic), _engine(new QScriptEngine())
{
	ui.setupUi(this);
//	ui.graphicsView = _view;
	ui.verticalLayout->addWidget(_view);


	QScriptValue value = _engine->newQObject(ui.pushButton);
	_engine->globalObject().setProperty("button", value);

	value = _engine->newQObject(data);
	_engine->globalObject().setProperty("data", value);

	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(evaluate()));
	connect(ui.textEdit, SIGNAL(textChanged()), this, SLOT(check()));
}

ScriptViewer::~ScriptViewer()
{
	delete _engine;
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

QScriptValue ScriptViewer::addGraphic()
{
	QScriptValue q;
	return q;
}
