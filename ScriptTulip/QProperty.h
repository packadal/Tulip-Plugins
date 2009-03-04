#ifndef QPROPERTY_H_
#define QPROPERTY_H_

#include <QtCore/QObject>
#include <QtCore/QString>

#include <tulip/AbstractProperty.h>
#include <tulip/PropertyAlgorithm.h>

class QNode;
class QEdge;
class QGraph;

class QProperty: public QObject {

Q_OBJECT

public:

	QProperty();
	QProperty(tlp::PropertyInterface*);
	virtual ~QProperty();
	tlp::PropertyInterface* asProperty();

public slots:

	void erase(const QNode*);
	void erase(const QEdge*);
	void copy(const QNode*, const QNode*, QProperty*);
	void copy(const QEdge*, const QEdge*, QProperty*);
	QProperty* clonePrototype(QGraph*, QString);
	QString getTypename();
	static QString getTypename(QProperty*);

	// Untyped accessors
	QString getNodeDefaultStringValue();
	QString getEdgeDefaultStringValue();
	QString getNodeStringValue(const QNode *node);
	QString getEdgeStringValue(const QEdge *edge);
	bool setNodeStringValue(const QNode *node, const QString value);
	bool setEdgeStringValue(const QEdge *edge, const QString value);
	bool setAllNodeStringValue(const QString value);
	bool setAllEdgeStringValue(const QString value);

	//TODO Check if we need to implements methods below

	// the ones below are used by GraphUpdatesRecorder
	/*Iterator<node>* getNonDefaultValuatedNodes()=0;
	 Iterator<edge>* getNonDefaultValuatedEdges()=0;
	 DataMem* getNodeDefaultDataMemValue() = 0;
	 DataMem* getEdgeDefaultDataMemValue() = 0;
	 DataMem* getNodeDataMemValue(const node n) = 0;
	 DataMem* getEdgeDataMemValue(const edge e) = 0;
	 DataMem* getNonDefaultDataMemValue(const node n) = 0;
	 DataMem* getNonDefaultDataMemValue(const edge e) = 0;
	 void setNodeDataMemValue(const node n, const DataMem* v) = 0;
	 void setEdgeDataMemValue(const edge e, const DataMem* v) = 0;
	 void setAllNodeDataMemValue(const DataMem* v) = 0;
	 void setAllEdgeDataMemValue(const DataMem* v) = 0;*/

private:

	tlp::PropertyInterface* _property;

};

#endif /* QPROPERTY_H_ */
