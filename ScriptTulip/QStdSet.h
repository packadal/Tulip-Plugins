/*
 * QEdgeSet.cpp
 *
 *  Created on: 3 mars 2009
 *      Author: chuet
 */

#ifndef QEDGESET_H_
#define QEDGESET_H_

#include <QtCore/QSet>

#define QSTDSET(Type, tlpType) class Q##Type##Set: QSet<Q##Type*>\
{\
public:\
\
	Q##Type##Set(std::set<tlpType> s) {\
		std::set<tlpType>::iterator it = s.begin();\
		while(it != s.end())\
			insert(new Q##Type(*it));\
		}\
\
	std::set<tlpType> as##Type() {\
		std::set<tlpType> ret;\
		QSet<Q##Type*>::iterator it = this->begin();\
		while(it != this->end())\
			ret.insert((*it)->as##Type());\
		return ret;\
	}\
\
	std::set<tlpType> asGraph() {\
		return as##Type();\
	}\
}

#include <QtCore/QVector>

#define QSTDVECTOR(Type, tlpType) class Q##Type##Vector: QVector<Q##Type*>\
{\
public:\
\
	Q##Type##Vector(std::vector<tlpType> s) {\
		std::vector<tlpType>::iterator it = s.begin();\
		while(it != s.end())\
			push_back(new Q##Type(*it));\
		}\
\
	std::vector<tlpType> as##Type() {\
		std::vector<tlpType> ret;\
		QVector<Q##Type*>::iterator it = this->begin();\
		while(it != this->end())\
			ret.push_back((*it)->as##Type());\
		return ret;\
	}\
\
	std::vector<tlpType> asGraph() {\
		return as##Type();\
	}\
}

#endif /* QEDGESET_H_ */
