#ifndef QBOOLEANPROPERTY_H_
#define QBOOLEANPROPERTY_H_

#include "QProperty.h"
#include "QIterator.h"

#include <QObject>

#include <tulip/BooleanProperty.h>


class QBooleanProperty: public QProperty
{

Q_OBJECT

public:

        QBooleanProperty(const QGraph *);
        QBooleanProperty(tlp::BooleanProperty* p);
        virtual ~QBooleanProperty();
        tlp::BooleanProperty* asProperty();

public slots:

        // Bindings from AbstractProperty
        bool getNodeDefaultValue();
        bool getEdgeDefaultValue();
        bool getNodeValue(QNode* n);
        bool getEdgeValue(QEdge* e);
        void setNodeValue(QNode* n, bool v);
        void setEdgeValue(QEdge* e, bool v);
        void setAllNodeValue(bool v);
        void setAllEdgeValue(bool v);

        // Specific methods
        void reverse();
        void reverseEdgeDirection();
        QIterator* getNodesEqualTo(bool val, QGraph * = 0);
        QIterator* getEdgesEqualTo(bool val, QGraph * = 0);
};

#endif /* QBOOLEANPROPERTY_H_ */

