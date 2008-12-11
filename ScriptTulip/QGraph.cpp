/*
 * QGraph.cpp
 *
 *  Created on: 10 déc. 2008
 *      Author: chuet
 */

#include "QGraph.h"

#include <QtScript/QScriptEngine>

#include <tulip/Node.h>
#include <tulip/Edge.h>

#include "QEdge.h"
#include "QNode.h"

using namespace tlp;

QGraph::QGraph() {
}

QGraph::QGraph(tlp::Graph* g)
:_graph(g)
{
}

QGraph::~QGraph() {

}

QScriptValue graphFactory(QScriptContext*, QScriptEngine *engine)
{
    QObject *graph = new QGraph(tlp::newGraph());
    return engine->newQObject(graph);
}

QScriptValue saveGraph(QScriptContext* context, QScriptEngine *engine)
{
	(void) engine;
	QGraph *graph = (QGraph *)(context->argument(0).toQObject());
	QString filename= context->argument(1).toString();
	tlp::saveGraph(graph->asGraph(), filename.toStdString());
	return QScriptValue();
}

void QGraph::clear()
{
	_graph->clear();
}

/*
QGraph *QGraph::addSubGraph(BooleanProperty *selection)
{
	return new QGraph(_graph->addSubGraph(selection));
}*/

void QGraph::delSubGraph(QGraph *g)
{
	_graph->delSubGraph(g->asGraph());
}

void QGraph::delAllSubGraphs(QGraph *g)
{
	return _graph->delAllSubGraphs(g->asGraph());
}

QGraph* QGraph::getSuperGraph()const
{
	return new QGraph(_graph->getSuperGraph());
}

QGraph* QGraph::getRoot() const
{
	return new QGraph(_graph->getRoot());
}

void QGraph::setSuperGraph(QGraph *g)
{
	return _graph->setSuperGraph(g->asGraph());
}
/*
Iterator<Graph *> * QGraph::getSubGraphs() const
{
	_graph->getSubGraphs();
}*/


QNode* QGraph::addNode()
{
	return new QNode(_graph->addNode());
}

void QGraph::addNode(const QNode* n)
{
	_graph->addNode(n->asNode());
}

void QGraph::delNode(const QNode* n)
{
	_graph->delNode(n->asNode());
}

void QGraph::delAllNode(const QNode* n)
{
	_graph->delAllNode(n->asNode());
}


QEdge* QGraph::addEdge(const QNode* n1, const QNode* n2)
{
	return new QEdge(_graph->addEdge(n1->asNode(), n2->asNode()));;
}

void QGraph::addEdge(const QEdge* e)
{
	_graph->addEdge(e->asEdge());
}

void QGraph::delEdge(const QEdge* e)
{
	_graph->delEdge(e->asEdge());
}

void QGraph::delAllEdge(const QEdge* e)
{
	_graph->delAllEdge(e->asEdge());
}

void QGraph::setEdgeOrder(const QNode* n, const std::vector<QEdge*> &v)
{
	std::vector<tlp::edge> vec;
	for(std::vector<QEdge*>::const_iterator it = v.begin(); it != v.end(); ++it)
		vec.push_back((*it)->asEdge());
	_graph->setEdgeOrder(n->asNode(), vec);
}

void QGraph::swapEdgeOrder(const QNode* n, const QEdge* e1, const QEdge* e2)
{
	_graph->swapEdgeOrder(n->asNode(), e1->asEdge(), e2->asEdge());
}

void QGraph::reverse(const QEdge* e)
{
	_graph->reverse(e->asEdge());
}

tlp::Graph* QGraph::asGraph()
{
	return _graph;
}

