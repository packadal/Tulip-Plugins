#ifndef QEDGE_H_
#define QEDGE_H_

#include <QObject>
#include <tulip/Graph.h>

class QEdge : public QObject, public tlp::edge {
	Q_OBJECT
public:
	QEdge();
	virtual ~QEdge();
};

#endif /* QEDGE_H_ */
