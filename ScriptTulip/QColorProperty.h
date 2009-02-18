#ifndef QCOLORPROPERTY_H_
#define QCOLORPROPERTY_H_

#include <QObject>
#include <QColor>

#include <tulip/ColorProperty.h>

class QColorProperty: public QProperty {

Q_OBJECT

public:

	QColorProperty(QGraph *);
	QColorProperty(tlp::ColorProperty*);
	virtual ~QColorProperty();
	tlp::ColorProperty* asProperty();

public slots:

	// Bindings from AbstractProperty
	QColor getNodeDefaultValue();
	QColor getEdgeDefaultValue();
	QColor getNodeValue(const QNode* n);
	QColor getEdgeValue(const QEdge* e);
	void setNodeValue(const QNode* n, QColor v);
	void setEdgeValue(const QEdge* e, QColor v);
	void setAllNodeValue(QColor v);
	void setAllEdgeValue(QColor v);

private:

	tlp::ColorProperty* _property;

#endif /* QCOLORPROPERTY_H_ */
