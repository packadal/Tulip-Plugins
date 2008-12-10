#include "scripteditor.h"

ScriptEditor::ScriptEditor(QWidget *parent)
    : QWidget(parent), _engine(new QScriptEngine())
{
	ui.setupUi(this);
	//_view = new QWidget();
	//ui.verticalLayout->addWidget(_view);
	

	QScriptValue value = _engine->newQObject(this);
	_engine->globalObject().setProperty("viewer", value);

	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(evaluate()));
	connect(ui.textEdit, SIGNAL(textChanged()), this, SLOT(check()));
}

ScriptEditor::~ScriptEditor()
{
	delete _engine;
}

void ScriptEditor::check()
{
	ui.pushButton->setEnabled(_engine->canEvaluate(ui.textEdit->toPlainText()));
}

void ScriptEditor::evaluate()
{
	_engine->evaluate(ui.textEdit->toPlainText());
	if(_engine->hasUncaughtException())
	{
		ui.label->setText(_engine->uncaughtException().toString());
		std::cout << qPrintable(_engine->uncaughtException().toString()) << std::endl;
	}
	else
		ui.label->setText("");
}

void ScriptEditor::refresh()
{
	update();
}
