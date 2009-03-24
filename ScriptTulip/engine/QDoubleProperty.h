#ifndef QDOUBLEPROPERTY_H_
#define QDOUBLEPROPERTY_H_

#include "QProperty.h"

#include <QObject>

#include <tulip/DoubleProperty.h>

class QDoubleProperty: public QProperty
{

Q_OBJECT

public:

	QDoubleProperty(const QGraph * g);
	QDoubleProperty(tlp::DoubleProperty*);
	virtual ~QDoubleProperty();
	tlp::DoubleProperty* asProperty();

public slots:

	// Bindings from AbstractProperty
	double getNodeDefaultValue();
	double getEdgeDefaultValue();
	double getNodeValue( QNode* n);
	double getEdgeValue( QEdge* e);
	void setNodeValue(QNode* n, double v);
	void setEdgeValue(QEdge* e, double v);
	void setAllNodeValue(double v);
	void setAllEdgeValue(double v);

	// Specific methods
	double getNodeMin(const QGraph *sg = 0);
	double getNodeMax(const QGraph *sg = 0);
	double getEdgeMin(const QGraph *sg = 0);
	double getEdgeMax(const QGraph *sg = 0);
	void uniformQuantification(unsigned int);

};

#endif /* QDOUBLEPROPERTY_H_ */

