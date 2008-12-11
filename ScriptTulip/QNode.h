#ifndef QNODE_H_
#define QNODE_H_

#include <QObject>

#include <tulip/Node.h>

class QNode : public QObject {
	Q_OBJECT
public:
	QNode();
	QNode(const tlp::node&);
	virtual ~QNode();

	tlp::node asNode() const { return *_node; }
private:
	Q_DISABLE_COPY(QNode);
	const tlp::node* _node;
};

#endif /* QNODE_H_ */
