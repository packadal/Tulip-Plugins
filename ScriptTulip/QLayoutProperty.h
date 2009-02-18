/*
 * QLayoutProperty.h
 *
 *  Created on: 18 févr. 2009
 *      Author: lburelou
 */

#ifndef QLAYOUTPROPERTY_H_
#define QLAYOUTPROPERTY_H_

#include "QProperty.h"

#include <tulip/LayoutProperty.h>
#include <QPoint>
#include <QLine>

class QLayoutProperty : public QProperty {
	Q_OBJECT
public:
	QLayoutProperty();
	QLayoutProperty(QGraph*);
	QLayoutProperty(tlp::LayoutProperty*);
	virtual ~QLayoutProperty();
	tlp::LayoutProperty* asLayoutProperty();

public slots:
	QPoint* getNodeDefaultValue();
	QLine* getEdgeDefaultValue();
	QPoint* getNodeValue(const QNode* n );
	QLine* getEdgeValue(const QEdge* e);
	void setNodeValue(const QNode* n, const QPoint* &v);
	void setEdgeValue(const QEdge* e, const QLine* &v);
	void setAllNodeValue(const QPoint* &v);
	void setAllEdgeValue(const QLine* &v);

private:
	tlp::LayoutProperty* _property;
};

#endif /* QLAYOUTPROPERTY_H_ */
