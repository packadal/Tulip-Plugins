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
        QBooleanProperty(tlp::BooleanProperty*);
        virtual ~QBooleanProperty();
        tlp::BooleanProperty* asProperty();

public slots:

        // Bindings from AbstractProperty
        bool getNodeDefaultValue();
        bool getEdgeDefaultValue();
        bool getNodeValue(const QNode* n);
        bool getEdgeValue(const QEdge* e);
        void setNodeValue(const QNode* n, bool v);
        void setEdgeValue(const QEdge* e, bool v);
        void setAllNodeValue(bool v);
        void setAllEdgeValue(bool v);

        // Specific methods
        void reverse();
        void reverseEdgeDirection();
        QIterator* getNodesEqualTo(const bool val, QGraph * = 0);
        QIterator* getEdgesEqualTo(const bool val, QGraph * = 0);

private:

        tlp::BooleanProperty* _property;
};

#endif /* QBOOLEANPROPERTY_H_ */

