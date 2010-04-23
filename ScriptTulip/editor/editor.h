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
#include <QFileDialog>
#include <QFile>
#include "scriptedit.h"
#include "TulipScriptEngine.h"
#include "QGraph.h"
#include "Translater.h"

#include <tulip/View.h>

class Editor : public tlp::View {
        Q_OBJECT;
public:
        /* tulip view plugin API */
        QWidget* construct(QWidget* parent) {

                this->_widget = new QWidget(parent);
                _editor = new ScriptEdit();
                QPushButton* button = new QPushButton("Evaluate");
                _label = new QLabel();
                QVBoxLayout* layout = new QVBoxLayout();

                layout->addWidget(_editor);
                layout->addWidget(_label);
                layout->addWidget(button);

                this->_widget->setLayout(layout);

                this->_widget->connect(button, SIGNAL(clicked()), this, SLOT(evaluate()));

                _engine = new TulipScriptEngine();

//                 _interactors = new std::list<tlp::Interactor*>();
//                 QAction* compile = new QAction("Generate C++", this);
//                 _interactors->push_back(compile);
//                 connect (compile, SIGNAL(triggered()), this, SLOT(generate()));

//                 QAction* save = new QAction("Save Script", this);
// 				_interactors->push_back(save);
// 				connect (save, SIGNAL(triggered()), this, SLOT(saveScript()));

//                 QAction* load = new QAction("Load Script", this);
// 				_interactors->push_back(load);
// 				connect (load, SIGNAL(triggered()), this, SLOT(loadScript()));

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
	  return _graph->asGraph();
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
        virtual void setActiveInteractor(tlp::Interactor *interactor) {}
        virtual void createPicture(const std::string &pictureName,int width=0, int height=0) {}

public slots:

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
			_engine->evaluate(_editor->document()->toPlainText());
			
			_label->setText(_engine->hasUncaughtException() ? _engine->uncaughtException().toString() : QString::null);
        }

        /* tulip view plugin API */
        void draw() {}
        void refresh() {}
        void init() {}
        void setGraph(tlp::Graph *graph) {modifyGraph(graph);}
private:
        void modifyGraph(tlp::Graph *graph) {
                _graph = new QGraph(graph);
                _engine->addQObject(_graph, "graph");
        }

	QWidget* _widget;
        std::list<tlp::Interactor *>* _interactors;
        QGraph* _graph;
        TulipScriptEngine* _engine;
        QLabel* _label;
        ScriptEdit* _editor;
};

#endif /* EDITOR_H_ */
