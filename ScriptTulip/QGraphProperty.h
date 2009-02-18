/*
 * QGraphProperty.h
 *
 *  Created on: 18 févr. 2009
 *      Author: lburelou
 */

#ifndef QGRAPHPROPERTY_H_
#define QGRAPHPROPERTY_H_

#include "QProperty.h"
#include "QGraph.h"

#include <tulip/GraphProperty.h>

class QGraphProperty : public QProperty {
	Q_OBJECT
public:
	QGraphProperty();
	QGraphProperty(QGraph*);
	QGraphProperty(tlp::GraphProperty*);
	virtual ~QGraphProperty();
	tlp::GraphProperty* asGraphProperty();

public slots:
	QGraph* getNodeDefaultValue();
	QGraph* getEdgeDefaultValue();
	QGraph* getNodeValue(const QNode* n );
	QGraph* getEdgeValue(const QEdge* e);
	void setNodeValue(const QNode* n, const QGraph* &v);
	void setEdgeValue(const QEdge* e, const QGraph* &v);
	void setAllNodeValue(const QGraph* &v);
	void setAllEdgeValue(const QGraph* &v);

private:
	tlp::GraphProperty* _property;
};

#endif /* QGRAPHPROPERTY_H_ */
