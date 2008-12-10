#include <QObject>
#include <tulip/Graph.h>

#ifndef QNODE_H_
#define QNODE_H_

class QNode : public QObject, public tlp::node {
public:
	Q_OBJECT
	QNode();
	virtual ~QNode();
};

#endif /* QNODE_H_ */
