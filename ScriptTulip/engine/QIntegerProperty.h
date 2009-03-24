#ifndef QINTEGERPROPERTY_H_
#define QINTEGERPROPERTY_H_

#include "QProperty.h"

#include <QObject>

#include <tulip/IntegerProperty.h>

class QIntegerProperty: public QProperty
{

Q_OBJECT

public:

        QIntegerProperty(const QGraph *);
        QIntegerProperty(tlp::IntegerProperty*);
        virtual ~QIntegerProperty();
        tlp::IntegerProperty* asProperty();

public slots:

        // Bindings from AbstractProperty
        int getNodeDefaultValue();
        int getEdgeDefaultValue();
        int getNodeValue(QNode* n);
        int getEdgeValue(QEdge* e);
        void setNodeValue(QNode* n, int v);
        void setEdgeValue(QEdge* e, int v);
        void setAllNodeValue(int v);
        void setAllEdgeValue(int v);

        // Specific methods
        int getNodeMin();
        int getNodeMax();
        int getEdgeMin();
        int getEdgeMax();

};

#endif /* QINTEGERPROPERTY_H_ */

