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

QGraph::QGraph(QScriptEngine* engine, tlp::Graph* g)
:_graph(g),_engine(engine)
{
}

QGraph::~QGraph() {

}

QScriptValue QGraph::getPrivateScriptValue(QObject* o) const
{
	return _engine->newQObject(o, QScriptEngine::ScriptOwnership);
}

QScriptValue graphFactory(QScriptContext*, QScriptEngine *engine)
{
    QObject *graph = new QGraph(engine, tlp::newGraph());
    return engine->newQObject(graph);
}

QScriptValue saveGraph(QScriptContext* context, QScriptEngine *)
{
	QString filename= context->argument(1).toString();
	QGraph *graph = (QGraph *)(context->argument(0).toQObject());
	tlp::saveGraph(graph->asGraph(), filename.toStdString());
	return QScriptValue();
}

QScriptValue loadGraph(QScriptContext *context, QScriptEngine *engine){
	QString filename= context->argument(0).toString();
	tlp::Graph* graph = tlp::loadGraph(filename.toStdString());
	QGraph *qgraph = new QGraph(engine,graph);
	QScriptValue value = engine->newQObject(qgraph);
	return value;
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

//this should be remplaced by the upper method when the properties will work
QScriptValue QGraph::addSubGraph()
{
	QGraph* g = new QGraph(_engine, _graph->addSubGraph());
	return getPrivateScriptValue(g);
}

void QGraph::delSubGraph(QGraph *g)
{
	_graph->delSubGraph(g->asGraph());
}

void QGraph::delAllSubGraphs(QGraph *g)
{
	_graph->delAllSubGraphs(g->asGraph());
}

QScriptValue QGraph::getSuperGraph()const
{
	return getPrivateScriptValue(new QGraph(_engine, _graph->getSuperGraph()));
}

QScriptValue QGraph::getRoot() const
{
	return getPrivateScriptValue(new QGraph(_engine, _graph->getRoot()));
}

void QGraph::setSuperGraph(QGraph *g)
{
	_graph->setSuperGraph(g->asGraph());
}
/*
Iterator<Graph *> * QGraph::getSubGraphs() const
{
	_graph->getSubGraphs();
}*/


QScriptValue QGraph::addNode()
{
	return getPrivateScriptValue(new QNode(_graph->addNode()));
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


QScriptValue QGraph::addEdge(const QNode* n1, const QNode* n2)
{
	return getPrivateScriptValue(new QEdge(_graph->addEdge(n1->asNode(), n2->asNode())));
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

QScriptValue QGraph::getProperty(QString name) {
	if(_graph->existProperty(name.toStdString()))
		return _engine->newQObject(new QProperty(_graph->getProperty(name.toStdString())));
	else return QScriptValue();

}

unsigned int QGraph::numberOfNodes()const
{
	return _graph->numberOfNodes();
}

unsigned int QGraph::numberOfEdges()const
{
	return _graph->numberOfEdges();
}

unsigned int QGraph::deg(const QNode* n)const
{
	return _graph->deg(n->asNode());
}

unsigned int QGraph::indeg(const QNode* n)const
{
	return _graph->indeg(n->asNode());
}

unsigned int QGraph::outdeg(const QNode* n)const
{
	return _graph->outdeg(n->asNode());
}

QScriptValue QGraph::source(const QEdge* e)const
{
	return getPrivateScriptValue(new QNode(_graph->source(e->asEdge())));
}

QScriptValue QGraph::target(const QEdge* e)const
{
	return getPrivateScriptValue(new QNode(_graph->target(e->asEdge())));
}

QScriptValue QGraph::opposite(const QEdge* e, const QNode* n)const
{
	return getPrivateScriptValue(new QNode(_graph->opposite(e->asEdge(), n->asNode())));
}

bool QGraph::isElement(const QNode* n) const
{
	return _graph->isElement(n->asNode());
}

bool QGraph::isElement(const QEdge* e) const
{
	return _graph->isElement(e->asEdge());
}

QScriptValue QGraph::existEdge(const QNode* n1, const QNode* n2) const
{
	return getPrivateScriptValue(new QEdge(_graph->existEdge(n1->asNode(), n2->asNode())));
}
