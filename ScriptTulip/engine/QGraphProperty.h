#ifndef QGRAPHPROPERTY_H_
#define QGRAPHPROPERTY_H_

#include "QProperty.h"
#include "QStdSet.h"

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
	QGraph* getNodeValue(const QNode* n);
	QEdgeSet* getEdgeValue(const QEdge* e);
	void setNodeValue(const QNode* n, const QGraph* v);
	void setEdgeValue(const QEdge* e, const QEdgeSet* v);
	void setAllNodeValue(const QGraph* v);
	void setAllEdgeValue(const QEdgeSet* v);

	// Specific methods
	void destroy(const QGraph *);
	bool setNodeStringValue(const QNode* n, const QString* v);
	bool setAllNodeStringValue(const QString* v);
	bool setEdgeStringValue( const QEdge* e, const QString* v);
	bool setAllEdgeStringValue(const QString* v);

private:

	tlp::GraphProperty* _property;

};

#endif /* QGRAPHPROPERTY_H_ */

