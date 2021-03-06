#ifndef QNODE_H_
#define QNODE_H_

#include <QtCore/QObject>

#include <tulip/Node.h>

class QScriptValue;
class QScriptContext;
class QScriptEngine;

class QNode : public QObject {
	Q_OBJECT
public:
	QNode();
	QNode(tlp::node);
	virtual ~QNode();

	tlp::node asNode() const { return _node; }
private:
	Q_DISABLE_COPY(QNode);
	const tlp::node _node;
};

#endif /* QNODE_H_ */
