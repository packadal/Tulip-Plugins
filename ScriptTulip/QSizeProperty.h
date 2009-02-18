#ifndef QSIZEPROPERTY_H_
#define QSIZEPROPERTY_H_

#include <QObject>
#include <QSize>
#include <QVector>

#include <tulip/SizeProperty.h>

#include "QIterator.h"

class QSizeProperty: public QProperty {

Q_OBJECT

public:

	QSizeProperty(QGraph *);
	QSizeProperty(tlp::SizeProperty*);
	virtual ~QSizeProperty();
	tlp::SizeProperty* asProperty();

public slots:

	// Bindings from AbstractProperty
	QSize getNodeDefaultValue();
	QSize getEdgeDefaultValue();
	QSize getNodeValue(const QNode* n);
	QSize getEdgeValue(const QEdge* e);
	void setNodeValue(const QNode* n, QSize v);
	void setEdgeValue(const QEdge* e, QSize v);
	void setAllNodeValue(QSize v);
	void setAllEdgeValue(QSize v);

	// Specific methods
	QSize getMax(QGraph *sg=0);
	QSize getMin(QGraph *sg=0);
	void scale( const QVector*, QGraph *sg=0 );
	void scale( const QVector, QIterator*, QIterator*);


private:

	tlp::SizeProperty* _property;

#endif /* QSIZEPROPERTY_H_ */
