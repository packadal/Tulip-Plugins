/*
 * editor.cpp
 *
 *  Created on: 7 janv. 2009
 *      Author: chuet
 */

#include "editor.h"

Editor::Editor()
:QWidget()
{
	_editor = new ScriptEdit();
	QPushButton* button = new QPushButton("Evaluate");
	_label = new QLabel();
	QVBoxLayout* layout = new QVBoxLayout();

	layout->addWidget(_editor);
	layout->addWidget(_label);
	layout->addWidget(button);

	setLayout(layout);

	connect(button, SIGNAL(clicked()), this, SLOT(evaluate()));

	_engine = new TulipScriptEngine();
}

Editor::~Editor() {
	// TODO Auto-generated destructor stub
}

void Editor::evaluate()
{
	_engine->evaluate(_editor->document()->toPlainText());
	if(_engine->hasUncaughtException())
		_label->setText(_engine->uncaughtException().toString());
	else
		_label->setText(QString::null);
}
