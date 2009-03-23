/*
 * QEdgeSet.cpp
 *
 *  Created on: 3 mars 2009
 *      Author: chuet
 */

#ifndef QEDGESET_H_
#define QEDGESET_H_

#include <QSet>

#define QSTDSET(Type, tlpType) QSTDCONTAINER(Set, std::set, insert, Type, tlpType)

#define QSTDVECTOR(Type, tlpType) QSTDCONTAINER(Vector, std::vector, push_back, Type, tlpType)

#define QSTDCONTAINER(CONTAINER_NAME, CONTAINER_TYPE, INSERT_FUNCTION, Type, tlpType) class Q##Type##CONTAINER_NAME: QSet<Q##Type*>\
{\
public:\
\
	Q##Type##CONTAINER_NAME(CONTAINER_TYPE<tlpType> s) {\
		CONTAINER_TYPE<tlpType>::iterator it = s.begin();\
		while(it != s.end())\
			insert(new Q##Type(*it));\
		}\
\
	CONTAINER_TYPE<tlpType> as##Type() const {\
		CONTAINER_TYPE<tlpType> ret;\
		QSet<Q##Type*>::const_iterator it = this->begin();\
		while(it != this->end())\
			ret.INSERT_FUNCTION((*it)->as##Type());\
		return ret;\
	}\
\
	CONTAINER_TYPE<tlpType> asGraph() const {\
		return as##Type();\
	}\
}

#endif /* QEDGESET_H_ */
