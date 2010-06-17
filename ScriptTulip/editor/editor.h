/*
 * editor.h
 *
 *  Created on: 7 janv. 2009
 *      Author: chuet
 */

#ifndef EDITOR_H_
#define EDITOR_H_

#include <QtGui/QApplication>
#include <QtGui/QAction>
#include <QtGui/QShortcut>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QFileDialog>
#include <QtCore/QFile>
#include <QtScriptTools/QScriptEngineDebugger>
#include <QtScriptTools/QtScriptTools>
#include "scriptedit.h"
#include "TulipScriptEngine.h"
#include "QGraph.h"
#include "Translater.h"

#include <tulip/View.h>
#include "ScriptInteractor.h"

class Editor : public tlp::View {
        Q_OBJECT;
public:
  
	Editor()
	  : _interactors(new std::list<tlp::Interactor*>()), _engine(new TulipScriptEngine()), _debugger(new QScriptEngineDebugger()){
	}
	
	~Editor()
	{
	  delete _engine;
	}
	
        /* tulip view plugin API */
        QWidget* construct(QWidget* parent) {

		_debugger->attachTo(_engine);
	  
                this->_widget = new QWidget(parent);
		this->_widget->setMinimumSize(QSize(500, 300));
                _editor = new ScriptEdit();
                _button = new QPushButton("Evaluate");
                _label = new QLabel();
                QVBoxLayout* layout = new QVBoxLayout();

// 		QWidget* widget = _debugger->widget(QScriptEngineDebugger::CodeWidget);
// 		std::cout << widget->metaObject()->className() << std::endl;
// 		QScriptDebuggerCodeWidget* codeWidget = qobject_cast<QScriptDebuggerCodeWidget* >(widget);
// 		codeWidget
		
                layout->addWidget(_editor);
                layout->addWidget(_label);
                layout->addWidget(_button);

                this->_widget->setLayout(layout);

		this->_widget->connect(_editor, SIGNAL(textChanged()), this, SLOT(checkEvaluationPossible()));
                this->_widget->connect(_button, SIGNAL(clicked()), this, SLOT(evaluate()));
// 		
		ScriptInteractor* interactor = new ScriptInteractor("Generate C++");
		this->_interactors->push_back(interactor);
		connect (interactor->getAction(), SIGNAL(triggered()), this, SLOT(generate()));
		
		interactor = new ScriptInteractor("Save Script");
		this->_interactors->push_back(interactor);
		connect (interactor->getAction(), SIGNAL(triggered()), this, SLOT(saveScript()));
		
		interactor = new ScriptInteractor("Load Script");
		this->_interactors->push_back(interactor);
		connect (interactor->getAction(), SIGNAL(triggered()), this, SLOT(loadScript()));

		interactor = new ScriptInteractor("Show Debugger");
		this->_interactors->push_back(interactor);
		connect (interactor->getAction(), SIGNAL(triggered()), this, SLOT(fireDebugger()));
		
		QShortcut *undo = new QShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_Z), this->_widget);
                QObject::connect(undo, SIGNAL(activated()), this, SLOT(undo()));
		
		QShortcut *evaluateMe = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Return), this->_widget);
		QObject::connect(evaluateMe, SIGNAL(activated()), this, SLOT(evaluate())); 
	  
                return this->_widget;
        }

	QWidget* getWidget() 
        {
	  return this->_widget;
	}

        void setData(tlp::Graph *graph,tlp::DataSet) {
                modifyGraph(graph);
        }

        void getData(tlp::Graph **graph,tlp::DataSet*) {
                *graph = _graph->asGraph();
        }

        tlp::Graph *getGraph() 
        {
	  return _engine->getGraph()->asGraph();
	}

        /* tulip view plugin API */
        //TODO check this makes any sense
        virtual void setInteractors(const std::list<tlp::Interactor *> &interactors) 
        {
	  this->_interactors->clear();
	  std::list<tlp::Interactor *>::const_iterator it = interactors.begin();
	  while(it != interactors.end())
	  {
	    this->_interactors->push_back(*it);
	    ++it;
	  }
	}
        
        virtual std::list<tlp::Interactor *> getInteractors() 
        {
	  return *_interactors;
	}
	
	//TODO implement
        virtual void setActiveInteractor(tlp::Interactor *) {}
        virtual void createPicture(const std::string &,int =0, int =0) {}

public slots:

	void fireDebugger() {
	  _debugger->action(QScriptEngineDebugger::InterruptAction)->trigger();
	}
	
	void generate() {
		Translater t(_engine);
		QString res = t.parse(_editor->document()->toPlainText());
		QFileDialog dialog;
		dialog.setDirectory(QDir::homePath());
		dialog.setAcceptMode(QFileDialog::AcceptSave);
		dialog.setFileMode(QFileDialog::AnyFile);
		if (dialog.exec())
		{
			QFile file(dialog.selectedFiles().at(0));
			file.open(QIODevice::WriteOnly);
			file.write(res.toAscii());
			file.close();
		}
	}

	void saveScript(){
		QFileDialog dialog;
		dialog.setDirectory(QDir::homePath());
		dialog.setAcceptMode(QFileDialog::AcceptSave);
		dialog.setFileMode(QFileDialog::AnyFile);
		if (dialog.exec())
		{
			QFile file(dialog.selectedFiles().at(0));
			file.open(QIODevice::WriteOnly);
			file.write(_editor->document()->toPlainText().toAscii());
			file.close();
		}

	}

	void loadScript(){
		QFileDialog dialog;
		dialog.setDirectory(QDir::homePath());
		dialog.setAcceptMode(QFileDialog::AcceptOpen);
		dialog.setFileMode(QFileDialog::ExistingFile);
		if (dialog.exec())
		{
			QFile file(dialog.selectedFiles().at(0));
			file.open(QIODevice::ReadOnly);
			_editor->document()->setPlainText(QString(file.readAll()));
			file.close();
		}

	}

	void evaluate() {
	  if(this->_engine->canEvaluate(_editor->document()->toPlainText()))
	  {
			_engine->evaluate(_editor->document()->toPlainText());
			
			_label->setText(_engine->hasUncaughtException() ? _engine->uncaughtException().toString() : QString::null);
			QString backtrace = QString();
			foreach(const QString element, _engine->uncaughtExceptionBacktrace()) {
				backtrace += element + "\n";
			}
			_label->setToolTip(backtrace);
	  }
	}

	void undo() {
	  if(_graph->canPop())
	  {
	    _graph->pop();
	  }
	}

	void checkEvaluationPossible() {
// 	  std::cout << "checking if possible (" << this->_engine->canEvaluate(_editor->document()->toPlainText()) << ")" << std::endl; 
	  bool canEvaluate = this->_engine->canEvaluate(_editor->document()->toPlainText());
	  
	  this->_button->setEnabled(canEvaluate);
	}

        /* tulip view plugin API */
        void draw() {}
        void refresh() {}
        void init() {}
        void setGraph(tlp::Graph *graph) {
	  modifyGraph(graph);
	}
private:
        void modifyGraph(tlp::Graph *graph) {
		_engine->setGraph(graph);
		_graph = _engine->getGraph();
        }

	QWidget* _widget;
        std::list<tlp::Interactor *>* _interactors;
        QGraph* _graph;
        TulipScriptEngine* _engine;
	QScriptEngineDebugger* _debugger;
        QLabel* _label;
        
	ScriptEdit* _editor;
	QPushButton* _button;
};

#endif /* EDITOR_H_ */
