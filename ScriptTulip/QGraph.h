#ifndef QGRAPH_H_
#define QGRAPH_H_

#include <QObject>
#include <tulip/Graph.h>

class QGraph : public QObject, public tlp::Graph {
public:
	QGraph();
	virtual ~QGraph();
};

#endif /* QGRAPH_H_ */
