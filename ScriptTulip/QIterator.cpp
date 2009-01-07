/*
 * QIterator.cpp
 *
 *  Created on: 7 janv. 2009
 *      Author: chuet
 */

#include "QIterator.h"

QIterator::QIterator()
:QObject()
{
}

QIterator::QIterator(tlp::Iterator<tlp::node>* i)
:QObject(), _type(node), _nodeIterator(i)
{
}

QIterator::QIterator(tlp::Iterator<tlp::edge>* i)
:QObject(), _type(edge), _edgeIterator(i)
{
}

QObject* QIterator::next()
{
	return (_type == node ? (QObject*)new QNode(_nodeIterator->next()) : (QObject*)new QEdge(_edgeIterator->next()));
}

bool QIterator::hasNext()
{
	return (_type == node ? _nodeIterator->hasNext() : _edgeIterator->hasNext());
}

QIterator::~QIterator() {
	if(_type == node)
		delete _nodeIterator;
	else
		delete _edgeIterator;
}
