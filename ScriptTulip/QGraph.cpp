/*
 * QGraph.cpp
 *
 *  Created on: 10 déc. 2008
 *      Author: chuet
 */

#include "QGraph.h"

#include <QtScript/QScriptEngine>

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

/*
node QGraph::addNode()
{
	return _graph->addNode();
}*/

void QGraph::addNode(const node n)
{
	_graph->addNode(n);
}

void QGraph::delNode(const node n)
{
	_graph->delNode(n);
}

void QGraph::delAllNode(const node n)
{
	_graph->delAllNode(n);
}

/*
edge QGraph::addEdge(const node n1, const node n2)
{
	return _graph->addEdge(n1, n2);
}*/

void QGraph::addEdge(const edge e)
{
	_graph->addEdge(e);
}

void QGraph::delEdge(const edge e)
{
	_graph->delEdge(e);
}

void QGraph::delAllEdge(const edge e)
{
	_graph->delAllEdge(e);
}

void QGraph::setEdgeOrder(const node n,const std::vector<edge> & ve)
{
	_graph->setEdgeOrder(n, ve);
}

void QGraph::swapEdgeOrder(const node n,const edge e1, const edge e2)
{
	_graph->swapEdgeOrder(n, e1, e2);
}

void QGraph::reverse(const edge e)
{
	_graph->reverse(e);
}

tlp::Graph* QGraph::asGraph()
{
	return _graph;
}

