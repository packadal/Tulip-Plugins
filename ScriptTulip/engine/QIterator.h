/*
 * QIterator.h
 *
 *  Created on: 7 janv. 2009
 *      Author: chuet
 */

#ifndef QITERATOR_H_
#define QITERATOR_H_

#include <QtCore/QObject>

#include "tulip/Iterator.h"
#include "tulip/Node.h"
#include "tulip/Edge.h"
#include "tulip/Graph.h"

class QNode;
class QEdge;
//class QGraph;

enum type { invalid, node, edge, graph };

class QIterator : public QObject {
	Q_OBJECT
public:
	virtual ~QIterator();
	QIterator();
	QIterator(tlp::Iterator<tlp::node>*);
	QIterator(tlp::Iterator<tlp::edge>*);
	QIterator(tlp::Iterator<tlp::Graph *>*);
	type getType();
public slots:
	QObject* next();
	bool hasNext();

private:
	type _type;
    tlp::Iterator<tlp::Graph *>* _graphIterator;
	tlp::Iterator<tlp::node>* _nodeIterator;
	tlp::Iterator<tlp::edge>* _edgeIterator;
};

class QStringIterator : public QObject {
	Q_OBJECT
public:
	virtual ~QStringIterator();
	QStringIterator();
	QStringIterator(tlp::Iterator<std::string>*);
public slots:
	QString next();
	bool hasNext();

private:
    tlp::Iterator<std::string>* _stringIterator;
};

#endif /* QITERATOR_H_ */
