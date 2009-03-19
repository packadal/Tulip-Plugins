/*
 * editor.h
 *
 *  Created on: 7 janv. 2009
 *      Author: chuet
 */

#ifndef EDITOR_H_
#define EDITOR_H_

#include <QApplication>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

#include "scriptedit.h"
#include "TulipScriptEngine.h"
#include "QGraph.h"

#include <tulip/View.h>

class Editor : public tlp::View {
        Q_OBJECT
public:
        /* tulip view plugin API */
        QWidget* construct(QWidget* parent) {

                QWidget* widget = new QWidget(parent);
                _editor = new ScriptEdit();
                QPushButton* button = new QPushButton("Evaluate");
                _label = new QLabel();
                QVBoxLayout* layout = new QVBoxLayout();

                layout->addWidget(_editor);
                layout->addWidget(_label);
                layout->addWidget(button);

                widget->setLayout(layout);

                widget->connect(button, SIGNAL(clicked()), this, SLOT(evaluate()));

                _engine = new TulipScriptEngine();
                return widget;
        }

        void setData(tlp::Graph *graph,tlp::DataSet) {
                modifyGraph(graph);
        }

        void getData(tlp::Graph **graph,tlp::DataSet*) {
                *graph = _graph->asGraph();
        }

        tlp::Graph *getGraph() {return _graph->asGraph();}

        std::list<QAction *> *getInteractorsActionList() {
                return new std::list<QAction*>;
        }

        void installInteractor(QAction*) {}


public slots:
        void evaluate() {
                _engine->evaluate(_editor->document()->toPlainText());
                if(_engine->hasUncaughtException())
                        _label->setText(_engine->uncaughtException().toString());
                else
                        _label->setText(QString::null);
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

        QGraph* _graph;
        TulipScriptEngine* _engine;
        QLabel* _label;
        ScriptEdit* _editor;
};

#endif /* EDITOR_H_ */
