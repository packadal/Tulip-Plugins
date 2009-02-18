/*
 * QStringProperty.h
 *
 *  Created on: 18 févr. 2009
 *      Author: lburelou
 */

#ifndef QSTRINGPROPERTY_H_
#define QSTRINGPROPERTY_H_

#include "QProperty.h"

#include <tulip/StringProperty.h>

class QStringProperty : public QProperty {
	Q_OBJECT
public:
	QStringProperty();
	QStringProperty(QGraph*);
	QStringProperty(tlp::StringProperty*);
	virtual ~QStringProperty();
	tlp::StringProperty* asStringProperty();

public slots:
	QString getNodeDefaultValue();
	QString getEdgeDefaultValue();
	QString getNodeValue(const QNode* n );
	QString getEdgeValue(const QEdge* e);
	void setNodeValue(const QNode* n, const QString &v);
	void setEdgeValue(const QEdge* e, const QString &v);
	void setAllNodeValue(const QString &v);
	void setAllEdgeValue(const QString &v);

private:
	tlp::StringProperty* _property;
};

#endif /* QSTRINGPROPERTY_H_ */
