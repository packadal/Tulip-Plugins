/**
 *     +-------------------------------------------+
 *     |  _____  ___  ____   _  ___  ______        |
 *     |  | __/ / __/ |   \ | | |  \ |_  _|        |
 *     |  |__ | | |_  | ° / | | |° /   ||          |
 *     |  /___| \__ \ |_|_\ |_| |_|    || ULIP     |
 *     |                                           |
 *     |         A XP Project by...                |
 * 	   +-------------------------------------------+
 *	   | Red Ranger ----------------- Romain Patau |
 *	   | Blue Ranger ----------------- Rudy Nappée |
 *	   | Pink Ranger <3 ------------- Charles Huet |
 *	   | Pink Ranger bis ----------- Loïc Bureloux |
 *	   | Black Ranger -------------- Quentin Enard |
 *	   | Green Ranger -------------- Damien Mothes |
 *	   | S???mix Zero -------------- Maxxx Orbison |
 *     +-------------------------------------------+
 *     |   Copyright © XP Ranger Team 2008-2009    |
 *     |      May the soucoupe be with you !       |
 *	   +-------------------------------------------+
 */


#include "QGraph.h"

#include <QtGui/QColor>

#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>

#include <tulip/Node.h>
#include <tulip/Edge.h>
#include "tulip/Algorithm.h"

#include "QEdge.h"
#include "QNode.h"

using namespace tlp;

QGraph::QGraph()
:_graph(tlp::newGraph())
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

void saveGraph(const QGraph* graph, QString filename)
{
	tlp::saveGraph(graph->asGraph(), filename.toStdString());
}

#ifndef JAMBI_BUILD

#include "ScriptFunctions.h"

QScriptValue saveGraph(QScriptContext* context, QScriptEngine *)
{
	QString filename= context->argument(1).toString();
	QGraph *graph = (QGraph *)(context->argument(0).toQObject());
	saveGraph(graph, filename);
	return QScriptValue();
}
ADD_FUNCTION(saveGraph);

QGraph* loadGraph(QString filename){
	tlp::Graph* graph = tlp::loadGraph(filename.toStdString());
	QGraph *qgraph = new QGraph(graph);
	return qgraph;
}
QScriptValue loadGraph(QScriptContext *context, QScriptEngine *engine){
	QString filename= context->argument(0).toString();
	QGraph *qgraph = loadGraph(filename);
	QScriptValue value = engine->newQObject(qgraph);
	return value;
}
ADD_FUNCTION(loadGraph);

QGraph* newGraph() {
	return new QGraph(tlp::newGraph());
}
QScriptValue newGraph(QScriptContext*, QScriptEngine *engine){
	QGraph *qgraph = new QGraph(tlp::newGraph());
	QScriptValue value = engine->newQObject(qgraph);
	return value;
}
ADD_FUNCTION(newGraph);

QScriptValue applyAlgorithm(QScriptContext *context, QScriptEngine*) {

	QGraph* graph = qobject_cast<QGraph*>(context->argument(0).toQObject());
	std::string errorMsg = context->argument(1).toString().toStdString();
	QScriptValue dataSet = context->argument(2);
	std::string alg = context->argument(3).toString().toStdString();
	QScriptValue plugProgress = context->argument(4);

	tlp::DataSet* set = new tlp::DataSet();

	if(dataSet.isObject())
	{
		//TODO use properties from now on
		QScriptValueIterator it(dataSet);
		while(it.hasNext()) {
			it.next();
			if(it.value().isBoolean())
				set->set<bool>(it.name().toStdString(), it.value().toBoolean());
			if(it.value().isString())
				set->set<std::string>(it.name().toStdString(), it.value().toString().toStdString());
			if(it.value().isNumber())
				set->set<int>(it.name().toStdString(), it.value().toInt32());
//			std::cout << "dataSet[" << it.name().toStdString() << "] : " << qPrintable(it.value().toString()) << std::endl;
		}
	}

	tlp::applyAlgorithm(graph->asGraph(), errorMsg, set, alg/*, plugProgress*/);
	return QScriptValue();
}
ADD_FUNCTION(applyAlgorithm);

#endif //JAMBI_BUILD

tlp::DataSet* DataSetFromQScriptValue(const QScriptValue& dataSet) {
  tlp::DataSet* set = new tlp::DataSet();
  
  QScriptValueIterator it(dataSet);
  while(it.hasNext()) {
    it.next();
    //std::cout << it.name().toStdString() << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;borderWidth
    QString name(it.name());
    QVariant value = it.value().toVariant();
    
    if(it.value().isBool()) {
      set->set<bool>(name.toStdString(), value.toBool());
      std::cout << "setting : " << it.name().toStdString() << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
    }
    else if(it.value().isString()) {
      std::cout << "setting : " << it.name().toStdString() << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      set->set<std::string>(name.toStdString(), value.toString().toStdString());
    }
    else if(it.value().isNumber()) {
      std::cout << "setting : " << it.name().toStdString() << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      set->set<int>(name.toStdString(), value.toInt());
    }
    else if(it.value().isObject()) {
      QVariant variant = it.value().toVariant();
      if(variant.type() == QVariant::Color)
      {
	QColor c = value.value<QColor>();
	tlp::Color col = Color(c.red(), c.green(), c.blue(), c.alpha());
	set->set<tlp::Color>(name.toStdString(), col);
	std::cout << "setting : " << it.name().toStdString() << ": (" << c.red() << "," << c.green() << "," <<  c.blue() << "," << c.alpha() << ")" << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      }
    }
    else if(it.value().isQObject()) {
      QObject* object = it.value().toQObject();
      std::cout << object->metaObject()->className() << std::endl;
      
      if(object->metaObject()->className() == "QProperty")
      {
	std::cout << "not setting anything : " << it.name().toStdString() << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      }
      else if(object->metaObject()->className() == QString("QDoubleProperty"))
      {
	tlp::DoubleProperty* prop = qobject_cast<QDoubleProperty*>(object)->asProperty();
	set->set<tlp::DoubleProperty*>(name.toStdString(), prop);
	std::cout << "setting : " << it.name().toStdString() << ":" << it.value().toString().toStdString() << "(" << it.value().toVariant().typeName() << ")" << std::endl;
      }
    }
  }

  return set;
}

bool QGraph::computeProperty(const QString &algo, const QProperty* qproperty, const QString &msg, const QScriptValue& data)
{
        std::string algorithm = algo.toStdString();
        std::string message = msg.toStdString();

        tlp::DataSet* set = DataSetFromQScriptValue(data);

        const std::string Typename = qproperty->asProperty()->getTypename();
	bool res = false;
	tlp::PropertyContext context;
	if (Typename == "double")
	  res = asGraph()->computeProperty(algorithm, dynamic_cast<DoubleProperty*>(qproperty->asProperty()), message, 0, set);
	else if (Typename == "layout")
	  res = asGraph()->computeProperty(algorithm, dynamic_cast<LayoutProperty*>(qproperty->asProperty()), message, 0, set);
	else if (Typename == "string")
	  res = asGraph()->computeProperty(algorithm, dynamic_cast<StringProperty*>(qproperty->asProperty()), message, 0, set);
	else if (Typename == "int")
	  res = asGraph()->computeProperty(algorithm, dynamic_cast<IntegerProperty*>(qproperty->asProperty()), message, 0, set);
	else if (Typename == "color") {
//	  ColorProperty::PAlgorithm *algo = ColorProperty::factory->getPluginObject(algorithm, context);
//	  algo->getParameters().getField()
	  res = asGraph()->computeProperty(algorithm, dynamic_cast<ColorProperty*>(qproperty->asProperty()), message, 0, set);
	}
	else if (Typename == "size")
	  res = asGraph()->computeProperty(algorithm, dynamic_cast<SizeProperty*>(qproperty->asProperty()), message, 0, set);
	else if (Typename == "bool")
	  res = asGraph()->computeProperty(algorithm, dynamic_cast<BooleanProperty*>(qproperty->asProperty()), message, 0, set);

	delete set;
	return res;
   }

void QGraph::clear()
{
	_graph->clear();
}

QGraph* QGraph::addSubGraph(QBooleanProperty *selection)
{
  tlp::BooleanProperty* property = (selection == 0 ? 0 : selection->asProperty());
	return new QGraph(_graph->addSubGraph(property));
}

QIterator* QGraph::getSubGraphs() const
{
	return new QIterator(_graph->getSubGraphs());
}

void QGraph::delSubGraph(const QGraph *g)
{
	_graph->delSubGraph(g->asGraph());
}

void QGraph::delAllSubGraphs(const QGraph *g)
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

void QGraph::setSuperGraph(const QGraph *g)
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

QGraphProperty* QGraph::getGraphProperty(QString name) {
	return new QGraphProperty(_graph->getProperty<tlp::GraphProperty>(name.toStdString()));
}

QDoubleProperty* QGraph::getDoubleProperty(QString name){
	return new QDoubleProperty(_graph->getProperty<tlp::DoubleProperty>(name.toStdString()));
}

QLayoutProperty* QGraph::getLayoutProperty(QString name){
	return new QLayoutProperty(_graph->getProperty<tlp::LayoutProperty>(name.toStdString()));
}

QStringProperty* QGraph::getStringProperty(QString name){
	return new QStringProperty(_graph->getProperty<tlp::StringProperty>(name.toStdString()));
}

QIntegerProperty* QGraph::getIntegerProperty(QString name){
	return new QIntegerProperty(_graph->getProperty<tlp::IntegerProperty>(name.toStdString()));
}

QColorProperty* QGraph::getColorProperty(QString name){
	return new QColorProperty(_graph->getProperty<tlp::ColorProperty>(name.toStdString()));
}

QSizeProperty* QGraph::getSizeProperty(QString name){
	return new QSizeProperty(_graph->getProperty<tlp::SizeProperty>(name.toStdString()));
}

QBooleanProperty* QGraph::getBooleanProperty(QString name){
	return new QBooleanProperty(_graph->getProperty<tlp::BooleanProperty>(name.toStdString()));
}

QProperty* QGraph::getProperty(QString name) {
		return new QProperty(_graph->getProperty(name.toStdString()));
}

bool QGraph::existProperty(const QString name){
	return _graph->existProperty(name.toStdString());
}

bool QGraph::existLocalProperty(const QString name){
	return _graph->existLocalProperty(name.toStdString());
}

void QGraph::delLocalProperty(const QString name){
	_graph->delLocalProperty(name.toStdString());
}

QStringIterator* QGraph::getLocalProperties(){
	return new QStringIterator(_graph->getLocalProperties());
}

QStringIterator* QGraph::getInheritedProperties(){
	return new QStringIterator(_graph->getInheritedProperties());
}

QStringIterator* QGraph::getProperties(){
	return new QStringIterator(_graph->getProperties());
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

bool QGraph::isMetaNode(const QNode* node) const
{
	return _graph->isMetaNode(node->asNode());
}

bool QGraph::isMetaEdge(const QEdge* edge) const
{
	return _graph->isMetaEdge(edge->asEdge());
}

QEdge* QGraph::existEdge(const QNode* n1, const QNode* n2) const
{
	return new QEdge(_graph->existEdge(n1->asNode(), n2->asNode()));
}

void QGraph::push()
{
	_graph->push();
}

void QGraph::pop()
{
	_graph->pop();
}

void QGraph::unpop()
{
	_graph->unpop();
}

bool QGraph::canPop()
{
	return _graph->canPop();
}

bool QGraph::canUnpop()
{
	return _graph->canUnpop();
}

/*bool QGraph::computeProperty(const QString &algorithm, Proxytype result, QString &msg,
				   QPluginProgress *progress=0, tlp::DataSet *data=0)
{
}*/
