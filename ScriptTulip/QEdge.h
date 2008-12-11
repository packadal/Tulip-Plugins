#ifndef QEDGE_H_
#define QEDGE_H_

#include <QObject>

#include <tulip/Edge.h>

class QEdge : public QObject {
	Q_OBJECT
public:
	QEdge();
	QEdge(const tlp::edge&);
	virtual ~QEdge();

	tlp::edge asEdge() const { return *_edge; }
private:
	Q_DISABLE_COPY(QEdge)
	const tlp::edge* _edge;
};

#endif /* QEDGE_H_ */
