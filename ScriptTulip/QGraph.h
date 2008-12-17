/*
 * QGraph.h
 *
 *  Created on: 10 déc. 2008
 *      Author: chuet
 */

#ifndef QGRAPH_H_
#define QGRAPH_H_

#include <tulip/Graph.h>

#include "QEdge.h"
#include "QNode.h"

#include <QtCore/QObject>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptContext>

class QGraph : public QObject {
	Q_OBJECT
public:
	QGraph(QScriptEngine* engine, tlp::Graph*);
	QGraph();
	virtual ~QGraph();
	tlp::Graph* asGraph();
public slots:
	void clear();
//	QGraph *addSubGraph(BooleanProperty *selection=0);
	void delSubGraph(QGraph *);
	void delAllSubGraphs(QGraph *);
	QGraph* getSuperGraph()const;

	QGraph* getFather()const {
		std::cerr << __PRETTY_FUNCTION__ << " is deprecated, use getSuperGraph() instead." << std::endl;
		return getSuperGraph();
	  }
	QGraph* getRoot() const;
	void setSuperGraph(QGraph *);
	void setFather(QGraph *sg) {
		std::cerr << __PRETTY_FUNCTION__ << " is deprecated, use setSuperGraph() instead." << std::endl;
		setFather(sg);
	  }
//	Iterator<Graph *> * getSubGraphs() const;
	QScriptValue addNode();
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
	/*
	virtual node getOneNode() const =0;
	virtual Iterator<node>* getNodes() const =0;
	virtual node getInNode(const node,unsigned int )const =0;
	virtual Iterator<node>* getInNodes(const node) const =0;
	virtual node getOutNode(const node,unsigned int) const =0;
	virtual Iterator<node>* getOutNodes(const node) const =0;
	virtual Iterator<node>* getInOutNodes(const node) const =0;
	virtual Iterator<edge>* getEdges() const =0;
	virtual edge getOneEdge() const =0;
	virtual Iterator<edge>* getOutEdges(const node) const =0;
	virtual Iterator<edge>* getInOutEdges(const node) const =0;
	virtual Iterator<edge>* getInEdges(const node) const =0;
	*/

	//================================================================================
	// Graph, nodes and edges informations about the graph stucture
	//================================================================================
	int getId() const {return id;}
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
	virtual QEdge* existEdge(const QNode* , const QNode*) const;
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
	template<typename Proxytype>
	Proxytype* getLocalProperty(const std::string &name);
	template<typename Proxytype>
	bool computeProperty(const std::string &algorithm, Proxytype result, std::string &msg,
				   PluginProgress *progress=0, DataSet *data=0);
	template<typename Proxytype>
	Proxytype* getProperty(const std::string &name);
	virtual PropertyInterface* getProperty(const std::string& name)=0;
	virtual  bool existProperty(const std::string& name)=0;
	virtual  bool existLocalProperty(const std::string& name)=0;
	virtual  void delLocalProperty(const std::string& name)=0;
	virtual Iterator<std::string>* getLocalProperties()=0;
	virtual Iterator<std::string>* getInheritedProperties()=0;
	virtual Iterator<std::string>* getProperties()=0;
	*/
private:
	unsigned int id;
	tlp::Graph* _graph;
	QScriptEngine* _engine;
};

QScriptValue graphFactory(QScriptContext *context, QScriptEngine *engine);
QScriptValue saveGraph(QScriptContext *context, QScriptEngine *engine);

#endif /* QGRAPH_H_ */
