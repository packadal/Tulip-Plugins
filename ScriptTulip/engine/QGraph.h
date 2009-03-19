/*
 * QGraph.h
 *
 *  Created on: 10 déc. 2008
 *      Author: chuet
 */

#ifndef QGRAPH_H_
#define QGRAPH_H_

#include <fstream>

#include <tulip/Graph.h>
#include "tulip/AbstractProperty.h"
#include "tulip/DoubleProperty.h"
#include "tulip/StringProperty.h"
#include "tulip/BooleanProperty.h"
#include "tulip/LayoutProperty.h"
#include "tulip/IntegerProperty.h"
#include "tulip/ColorProperty.h"
#include "tulip/SizeProperty.h"
#include "tulip/GraphProperty.h"


#include "Scriptmacros.h"
#include "QEdge.h"
#include "QNode.h"
#include "QProperty.h"
#include "QIterator.h"

#include <QtCore/QObject>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptContext>


class QGraph : public QObject {
	Q_OBJECT
public:
	QGraph(tlp::Graph*);
	QGraph();
	virtual ~QGraph();
	tlp::Graph* asGraph() const;
	QGraph* clone();
public slots:

	static bool applyAlgorithm(QGraph *graph, const QString &errorMsg, tlp::DataSet *dataSet =0, const QString &alg="hierarchical", tlp::PluginProgress *plugProgress=0)
	{
		std::string stdErrorMsg = errorMsg.toStdString();
		std::string stdAlg = alg.toStdString();
		return tlp::applyAlgorithm(graph->asGraph(), stdErrorMsg, dataSet, stdAlg, plugProgress);
	}

	static void exportGraph(QGraph* graph, const QString &fileName, const QString &alg, tlp::DataSet &dataset, tlp::PluginProgress* plugProgress=0)
	{
		std::ofstream os(fileName.toStdString().c_str());
		tlp::exportGraph(graph->asGraph(), os, alg.toStdString(), dataset, plugProgress);
	}

	static QGraph* newGraph()
	{
		return new QGraph(tlp::newGraph());
	}

	static void importGraph(const QString& alg, tlp::DataSet &dataSet, tlp::PluginProgress *plugProgress=0, QGraph* newGraph=0)
	{
		tlp::Graph* graph = (newGraph == 0 ? 0 : newGraph->asGraph());
		tlp::importGraph(alg.toStdString(), dataSet, plugProgress, graph);
	}

	static void saveGraph(const QGraph* g, const QString &filename)
	{
		tlp::saveGraph(g->asGraph(), filename.toStdString());
	}

	static QGraph* loadGraph(const QString &filename)
	{
		return new QGraph(tlp::loadGraph(filename.toStdString()));
	}

	static void delimiter() { }

	void clear();
	QGraph* addSubGraph(tlp::BooleanProperty* selection=0);

	void delSubGraph(const QGraph *);
	void delAllSubGraphs(const QGraph *);
	QGraph* getSuperGraph()const;

	QGraph* getFather()const {
		std::cerr << __PRETTY_FUNCTION__ << " is deprecated, use getSuperGraph() instead." << std::endl;
		return getSuperGraph();
	  }
	QGraph* getRoot() const;
	void setSuperGraph(const QGraph *);
	void setFather(const QGraph *sg) {
		std::cerr << __PRETTY_FUNCTION__ << " is deprecated, use setSuperGraph() instead." << std::endl;
		setFather(sg);
	  }
	QIterator* getSubGraphs() const;

	//==============================================================================
	// Modification of the graph structure
	//==============================================================================
	QNode* addNode();
	void addNode(const QNode*);
	void delNode(const QNode*);
	void delAllNode(const QNode*);

	QEdge* addEdge(const QNode*, const QNode*);
	void addEdge(const QEdge*);
	void delEdge(const QEdge*);
	void delAllEdge(const QEdge*);

	void setEdgeOrder(const QNode*, const std::vector<QEdge*> & );
	void swapEdgeOrder(const QNode*, const QEdge*, const QEdge*);
	void reverse(const QEdge*);

	//================================================================================
	//Iterators on the graph structure.
	//================================================================================
	virtual QNode* getOneNode() const;
	virtual QIterator* getNodes() const;
	virtual QNode* getInNode(const QNode*, unsigned int)const;
	virtual QIterator* getInNodes(const QNode*) const;
	virtual QNode* getOutNode(const QNode*, unsigned int) const;
	virtual QIterator* getOutNodes(const QNode*) const;
	virtual QIterator* getInOutNodes(const QNode*) const;
	virtual QIterator* getEdges() const;
	virtual QEdge* getOneEdge() const;
	virtual QIterator* getOutEdges(const QNode*) const;
	virtual QIterator* getInOutEdges(const QNode*) const;
	virtual QIterator* getInEdges(const QNode*) const;

	//================================================================================
	// Graph, nodes and edges informations about the graph stucture
	//================================================================================
	int getId() const {return _graph->getId();}
	virtual unsigned int numberOfNodes()const;
	virtual unsigned int numberOfEdges()const;
	virtual unsigned int deg(const QNode*)const;
	virtual unsigned int indeg(const QNode*)const;
	virtual unsigned int outdeg(const QNode*)const;
	virtual QNode* source(const QEdge*)const;
	virtual QNode* target(const QEdge*)const;
	virtual QNode* opposite(const QEdge*, const QNode*)const;
	virtual bool isElement(const QNode*) const;
	virtual bool isElement(const QEdge*) const;
	virtual bool isMetaNode(const QNode*) const;
	virtual bool isMetaEdge(const QEdge*) const;
	virtual QEdge* existEdge(const QNode*, const QNode*) const;
	//================================================================================
	// Access to the graph attributes and to the node/edge property.
	//================================================================================
	/*
	virtual DataSet & getAttributes() =0;
	template<typename ATTRIBUTETYPE>
	ATTRIBUTETYPE getAttribute(const std::string &name);
	template<typename ATTRIBUTETYPE>
	void setAttribute(const std::string &name,const ATTRIBUTETYPE &value);
	virtual  void addLocalProperty(const std::string &name, PropertyInterface *prop)=0;
	*/

//	QProperty getLocalProperty(const QString &name);

	bool computeProperty(const QString &algorithm, const QProperty* property, const QString &message, const QObject* dataSet);

	//template<typename Proxytype>
	//Proxytype* getProperty(const std::string &name);
	QProperty* getGraphProperty(QString name);
	QProperty* getDoubleProperty(QString name);
	QProperty* getLayoutProperty(QString name);
	QProperty* getStringProperty(QString name);
	QProperty* getIntegerProperty(QString name);
	QProperty* getColorProperty(QString name);
	QProperty* getSizeProperty(QString name);
	QProperty* getBooleanProperty(QString name);
	QProperty* getProperty(QString name);
	bool existProperty(const QString name);
	bool existLocalProperty(const QString name);
	void delLocalProperty(const QString name);
	QStringIterator* getLocalProperties();
	QStringIterator* getInheritedProperties();
	QStringIterator* getProperties();

	//updates management
	virtual void push();
	virtual void pop();
	virtual void unpop();
	virtual bool canPop();
	virtual bool canUnpop();
private:
	tlp::Graph* _graph;
	QScriptEngine* _engine;
};

void saveGraph(const QGraph* graph, QString filename);
QGraph* loadGraph(QString filename);
QGraph* newGraph();
QScriptValue saveGraph(QScriptContext *context, QScriptEngine *engine);
QScriptValue loadGraph(QScriptContext *context, QScriptEngine *engine);
QScriptValue applyAlgorithm(QScriptContext *context, QScriptEngine *engine);

#endif /* QGRAPH_H_ */
