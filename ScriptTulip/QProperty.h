#ifndef QPROPERTY_H_
#define QPROPERTY_H_

#include <QObject>
#include <QString>
#include <QScriptValue>

#include <tulip/AbstractProperty.h>

#include "QNode.h"

class QProperty : public QObject {
	Q_OBJECT
	public:
		QProperty();
		QProperty(tlp::PropertyInterface *property);
		virtual ~QProperty();
	public slots:
		QString getNodeStringValue(QNode *node);
		bool setNodeStringValue(QNode *node, QString value);

		QString getNodeDefaultStringValue();
		QString getEdgeDefaultStringValue();

		/*virtual void erase(const node) =0;
		virtual void erase(const edge) =0;
		virtual void copy(const node, const node, PropertyInterface *) =0;
		virtual void copy(const edge, const edge, PropertyInterface *) =0;
		virtual PropertyInterface* clonePrototype(Graph *, std::string) =0;
		virtual std::string getTypename() = 0;
		static  std::string getTypename( PropertyInterface * );

		virtual std::string getEdgeStringValue( const edge e ) = 0;

		virtual bool setEdgeStringValue( const edge e, const std::string & v ) = 0;
		virtual bool setAllNodeStringValue( const std::string & v ) = 0;
		virtual bool setAllEdgeStringValue( const std::string & v ) = 0;
		virtual Iterator<node>* getNonDefaultValuatedNodes()=0;
		virtual Iterator<edge>* getNonDefaultValuatedEdges()=0;*/
	private:
		tlp::PropertyInterface *_property;
};

QScriptValue qPropertyToScriptValue(QScriptEngine *engine, const QProperty &prop);
void qPropertyFromScriptValue(const QScriptValue &obj, QProperty &prop);

#endif /* QPROPERTY_H_ */
