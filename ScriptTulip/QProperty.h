#ifndef QPROPERTY_H_
#define QPROPERTY_H_

#include <QObject>
#include <QString>

#include <tulip/AbstractProperty.h>
#include <tulip/PropertyAlgorithm.h>

#include "QNode.h"
#include "QEdge.h"

class QProperty : public QObject {
	Q_OBJECT
	public:
		QProperty();
		QProperty(tlp::PropertyInterface*);
		virtual ~QProperty();
		tlp::PropertyInterface* asProperty();
	public slots:
		QString getNodeStringValue(QNode *node);
		bool setNodeStringValue(QNode *node, QString value);

		QString getNodeDefaultStringValue();
		QString getEdgeDefaultStringValue();

		void erase(const QNode*);
		void erase(const QEdge*);
		void copy(const QNode*, const QNode*, QProperty*);
		void copy(const QEdge*, const QEdge*, QProperty*);
		/*virtual PropertyInterface* clonePrototype(Graph *, std::string) =0;
		virtual std::string getTypename() = 0;
		static  std::string getTypename( PropertyInterface * );

		virtual std::string getEdgeStringValue( const edge e ) = 0;

		virtual bool setEdgeStringValue( const edge e, const std::string & v ) = 0;
		virtual bool setAllNodeStringValue( const std::string & v ) = 0;
		virtual bool setAllEdgeStringValue( const std::string & v ) = 0;
		virtual Iterator<node>* getNonDefaultValuatedNodes()=0;
		virtual Iterator<edge>* getNonDefaultValuatedEdges()=0;*/
	private:
		tlp::PropertyInterface* _property;
};

#endif /* QPROPERTY_H_ */
