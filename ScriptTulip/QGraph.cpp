/**
 *     +-------------------------------------------+
 *     |  _____  ___  ____   _  ___  ______        |
 *     |  | __/ / __/ |   \ | | |  \ |_  _|        |
 *     |  |__ | | |_  | ° / | | |° /   ||          |
 *     |  /___| \__ \ |_|_\ |_| |_|    || ULIP  |
 *     |                                           |
 *     |         A XP Project by...                |
 * 	   +-------------------------------------------+
 *	   | Red Ranger ----------------- Romain Patau |
 *	   | Blue Ranger ----------------- Rudy Nappée |
 *	   | Pink Ranger <3 ------------- Charles Huet |
 *	   | Pink Ranger bis ------------ Loïc Burelou |
 *	   | Black Ranger -------------- Quentin Enard |
 *	   | Green Ranger -------------- Damien Mothes |
 *	   | Spermix Zero -------------- Maxxx Orbison |
 *     +-------------------------------------------+
 *     |   Copyright © XP Ranger Team 2008-2009    |
 *     |      May the soucoupe be with you !       |
 *	   +-------------------------------------------+
 */


#include "QGraph.h"

#include <QtScript/QScriptEngine>

#include <tulip/Node.h>
#include <tulip/Edge.h>

#include "QEdge.h"
#include "QNode.h"

using namespace tlp;

QGraph::QGraph()
:_graph(newGraph())
{
}

QGraph::QGraph(tlp::Graph* g)
:_graph(g)
{
}

QGraph::~QGraph() {

}

QGraph* QGraph::clone(){
	return new QGraph(tlp::newCloneSubGraph(asGraph()));
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
	QGraph *qgraph = new QGraph(graph);
	QScriptValue value = engine->newQObject(qgraph);
	return value;
}

void QGraph::clear()
{
	_graph->clear();
}


QGraph* QGraph::addSubGraph(BooleanProperty *selection)
{
	return new QGraph(_graph->addSubGraph(selection));
}

QIterator* QGraph::getSubGraphs() const
{
	return new QIterator(_graph->getSubGraphs());
}

void QGraph::delSubGraph(QGraph *g)
{
	_graph->delSubGraph(g->asGraph());
}

void QGraph::delAllSubGraphs(QGraph *g)
{
	_graph->delAllSubGraphs(g->asGraph());
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
	_graph->setSuperGraph(g->asGraph());
}


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
	return new QEdge(_graph->addEdge(n1->asNode(), n2->asNode()));
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

QNode* QGraph::getOneNode() const
{
	return new QNode(_graph->getOneNode());
}

QNode* QGraph::getInNode(const QNode* n, unsigned int i)const
{
	return new QNode(_graph->getInNode(n->asNode(), i));
}

QNode* QGraph::getOutNode(const QNode* n, unsigned int i) const
{
	return new QNode(_graph->getOutNode(n->asNode(), i));
}

QEdge* QGraph::getOneEdge() const
{
	return new QEdge(_graph->getOneEdge());
}

QIterator* QGraph::getNodes() const
{
	return new QIterator(_graph->getNodes());
}

QIterator* QGraph::getInNodes(const QNode* n) const
{
	return new QIterator(_graph->getInNodes(n->asNode()));
}

QIterator* QGraph::getOutNodes(const QNode* n) const
{
	return new QIterator(_graph->getOutNodes(n->asNode()));
}

QIterator* QGraph::getInOutNodes(const QNode* n) const
{
	return new QIterator(_graph->getInOutNodes(n->asNode()));
}

QIterator* QGraph::getEdges() const
{
	return new QIterator(_graph->getEdges());
}

QIterator* QGraph::getOutEdges(const QNode* n) const
{
	return new QIterator(_graph->getOutEdges(n->asNode()));
}

QIterator* QGraph::getInOutEdges(const QNode* n) const
{
	return new QIterator(_graph->getInOutEdges(n->asNode()));
}

QIterator* QGraph::getInEdges(const QNode* n) const
{
	return new QIterator(_graph->getInEdges(n->asNode()));
}

tlp::Graph* QGraph::asGraph() const
{
	return _graph;
}

QProperty* QGraph::getProperty(QString name) {
	/*if(_graph->existProperty(name.toStdString()))
		return new QProperty(_graph->getProperty(name.toStdString()));
	else*/ return new QProperty();

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

QNode*  QGraph::source(const QEdge* e)const
{
	return new QNode(_graph->source(e->asEdge()));
}

QNode* QGraph::target(const QEdge* e)const
{
	return new QNode(_graph->target(e->asEdge()));
}

QNode* QGraph::opposite(const QEdge* e, const QNode* n)const
{
	return new QNode(_graph->opposite(e->asEdge(), n->asNode()));
}

bool QGraph::isElement(const QNode* n) const
{
	return _graph->isElement(n->asNode());
}

bool QGraph::isElement(const QEdge* e) const
{
	return _graph->isElement(e->asEdge());
}

QEdge* QGraph::existEdge(const QNode* n1, const QNode* n2) const
{
	return new QEdge(_graph->existEdge(n1->asNode(), n2->asNode()));
}
