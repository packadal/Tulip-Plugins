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
        QColor* getNodeValue(QNode* n);
        QColor* getEdgeValue(QEdge* e);
        void setNodeValue(QNode* n, QColor* v);
        void setEdgeValue(QEdge* e, QColor* v);
        void setAllNodeValue(QColor* v);
        void setAllEdgeValue(QColor* v);

};

#endif /* QCOLORPROPERTY_H_ */

