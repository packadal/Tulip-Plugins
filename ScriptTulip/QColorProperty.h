#ifndef QCOLORPROPERTY_H_
#define QCOLORPROPERTY_H_

#include "QProperty.h"

#include <QObject>
#include <QColor>

#include <tulip/ColorProperty.h>

class QColorProperty: public QProperty
{

Q_OBJECT

public:

        QColorProperty(const QGraph *);
        QColorProperty(tlp::ColorProperty*);
        virtual ~QColorProperty();
        tlp::ColorProperty* asProperty();

public slots:

        // Bindings from AbstractProperty
        QColor* getNodeDefaultValue();
        QColor* getEdgeDefaultValue();
        QColor* getNodeValue(const QNode* n);
        QColor* getEdgeValue(const QEdge* e);
        void setNodeValue(const QNode* n, const QColor* v);
        void setEdgeValue(const QEdge* e, const QColor* v);
        void setAllNodeValue(const QColor* v);
        void setAllEdgeValue(const QColor* v);

private:

        tlp::ColorProperty* _property;
};

#endif /* QCOLORPROPERTY_H_ */

