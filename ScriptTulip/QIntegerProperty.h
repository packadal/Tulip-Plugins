#ifndef QINTEGERPROPERTY_H_
#define QINTEGERPROPERTY_H_

#include "QProperty.h"

#include <QObject>

#include <tulip/IntegerProperty.h>

class QIntegerProperty: public QProperty
{

Q_OBJECT

public:

	QIntegerProperty(QGraph *);
	QIntegerProperty(tlp::IntegerProperty*);
	virtual ~QIntegerProperty();
	tlp::IntegerProperty* asProperty();

public slots:

	// Bindings from AbstractProperty
	int getNodeDefaultValue();
	int getEdgeDefaultValue();
	int getNodeValue(const QNode* n);
	int getEdgeValue(const QEdge* e);
	void setNodeValue(const QNode* n, int v);
	void setEdgeValue(const QEdge* e, int v);
	void setAllNodeValue(int v);
	void setAllEdgeValue(int v);

	// Specific methods
	int getNodeMin();
	int getNodeMax();
	int getEdgeMin();
	int getEdgeMax();

private:

	tlp::IntegerProperty* _property;

};

#endif /* QINTEGERPROPERTY_H_ */
