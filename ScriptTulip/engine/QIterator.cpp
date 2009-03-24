#include "QIterator.h"

#include "QNode.h"
#include "QEdge.h"
#include "QGraph.h"

QIterator::QIterator(tlp::Iterator<tlp::node>* i)
:QObject(), _type(node), _nodeIterator(i)
{
}

QIterator::QIterator(tlp::Iterator<tlp::edge>* i)
:QObject(), _type(edge), _edgeIterator(i)
{
}

QIterator::QIterator(tlp::Iterator<tlp::Graph *>* i)
:QObject(), _type(graph), _graphIterator(i)
{
}

type QIterator::getType()
{
	return _type;
}

QObject* QIterator::next()
{
	if(_type == node)
		return (QObject*) new QNode(_nodeIterator->next());
	else if (_type == edge)
		return (QObject*) new QEdge(_edgeIterator->next());
	else if (_type == graph)
		return (QObject*) new QGraph(_graphIterator->next());
}

bool QIterator::hasNext()
{
	if(_type == node)
		return _nodeIterator->hasNext();
	else if (_type == edge)
		return _edgeIterator->hasNext();
	else if(_type == graph)
		return _graphIterator->hasNext();
}

QIterator::~QIterator() {
	if(_type == node)
		delete _nodeIterator;
	else if (_type == edge)
		delete _edgeIterator;
	else if(_type == graph)
		delete _graphIterator;
}

QStringIterator::QStringIterator()
:QObject()
{
}

QStringIterator::QStringIterator(tlp::Iterator<std::string>* i)
:QObject(), _stringIterator(i)
{
}

QString QStringIterator::next()
{
	return QString::fromStdString(_stringIterator->next());
}

bool QStringIterator::hasNext()
{
	return _stringIterator->hasNext();
}

QStringIterator::~QStringIterator() {
	delete _stringIterator;
}
