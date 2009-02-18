/*
 * QDoubleProperty.h
 *
 *  Created on: 18 févr. 2009
 *      Author: lburelou
 */

#ifndef QDOUBLEPROPERTY_H_
#define QDOUBLEPROPERTY_H_

#include "QProperty.h"
#include "QGraph.h"

#include <tulip/DoubleProperty.h>

class QDoubleProperty : public QProperty {
	Q_OBJECT
public:
	QDoubleProperty();
	QDoubleProperty(QGraph*);
	QDoubleProperty(tlp::DoubleProperty*);
	virtual ~QDoubleProperty();
	tlp::DoubleProperty* asDoubleProperty();

public slots:
	double getNodeDefaultValue();
	double getEdgeDefaultValue();
	double getNodeValue(const QNode* n );
	double getEdgeValue(const QEdge* e);
	void setNodeValue(const QNode* n, const double &v);
	void setEdgeValue(const QEdge* e, const double &v);
	void setAllNodeValue(const double &v);
	void setAllEdgeValue(const double &v);

private:
	tlp::DoubleProperty* _property;
};

#endif /* QDOUBLEPROPERTY_H_ */
