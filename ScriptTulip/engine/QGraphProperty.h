#ifndef QGRAPHPROPERTY_H_
#define QGRAPHPROPERTY_H_

#include "QProperty.h"
#include "QStdSet.h"
#include "QEdge.h"

#include <QObject>

#include <tulip/GraphProperty.h>

QSTDSET(Edge, tlp::edge);

class QGraphProperty: public QProperty
{

Q_OBJECT

public:

	QGraphProperty(const QGraph *);
	QGraphProperty(tlp::GraphProperty*);
	virtual ~QGraphProperty();
	tlp::GraphProperty* asProperty();

public slots:

	// Bindings from AbstractProperty
	QGraph* getNodeDefaultValue();
	QEdgeSet* getEdgeDefaultValue();
	QGraph* getNodeValue(QNode* n);
	QEdgeSet* getEdgeValue(QEdge* e);
	void setNodeValue(QNode* n, QGraph* v);
	void setEdgeValue(QEdge* e, QEdgeSet* v);
	void setAllNodeValue(QGraph* v);
	void setAllEdgeValue(QEdgeSet* v);

	// Specific methods
	void destroy(QGraph *);
	bool setNodeStringValue(QNode* n, QString* v);
	bool setAllNodeStringValue(QString* v);
	bool setEdgeStringValue(QEdge* e, QString* v);
	bool setAllEdgeStringValue(QString* v);

};

#endif /* QGRAPHPROPERTY_H_ */

