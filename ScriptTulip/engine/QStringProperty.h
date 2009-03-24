#ifndef QSTRINGPROPERTY_H_
#define QSTRINGPROPERTY_H_

#include "QProperty.h"

#include <QObject>

#include <tulip/StringProperty.h>

class QStringProperty: public QProperty
{

Q_OBJECT

public:

	QStringProperty(const QGraph *);
	QStringProperty(tlp::StringProperty*);
	virtual ~QStringProperty();
	tlp::StringProperty* asProperty();

public slots:

	// Bindings from AbstractProperty
	const QString& getNodeDefaultValue();
	const QString& getEdgeDefaultValue();
	const QString& getNodeValue(QNode* n);
	const QString& getEdgeValue(QEdge* e);
	void setNodeValue(QNode* n, QString* v);
	void setEdgeValue(QEdge* e, QString* v);
	void setAllNodeValue(QString* v);
	void setAllEdgeValue(QString* v);

};

#endif /* QSTRINGPROPERTY_H_ */

