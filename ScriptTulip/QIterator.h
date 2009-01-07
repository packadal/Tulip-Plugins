/*
 * QIterator.h
 *
 *  Created on: 7 janv. 2009
 *      Author: chuet
 */

#ifndef QITERATOR_H_
#define QITERATOR_H_

#include <QObject>

#include "tulip/Iterator.h"
#include "tulip/Node.h"
#include "tulip/Edge.h"

#include "QNode.h"
#include "QEdge.h"

const bool node = true;
const bool edge = false;

class QIterator : public QObject {
	Q_OBJECT
public:
	virtual ~QIterator();
	QIterator();
	QIterator(tlp::Iterator<tlp::node>*);
	QIterator(tlp::Iterator<tlp::edge>*);
public slots:
	QObject* next();
	bool hasNext();

private:
	bool _type;
	tlp::Iterator<tlp::node>* _nodeIterator;
	tlp::Iterator<tlp::edge>* _edgeIterator;
};

#endif /* QITERATOR_H_ */
