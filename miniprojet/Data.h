/*
 * Data.h
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#ifndef DATA_H_
#define DATA_H_

#include <vector>
#include <map>

#include "IData.h"

/**
 * Implements the IData interface, so this will be manipulable as an IData item.
 * This is implemented using a vector of pairs, to represent a function
 * (pair.first ~= x; pair.second ~= y)
 */
template <typename T>class Data : public IData<T>
{
public:
	inline size_t size() const { return _array.size(); }
	inline void add(T x, T y) { _array.push_back(std::pair<T, T>(x, y)); }
	inline float getX(int i) const { return _array.at(i).first; }
	inline float getY(int i) const { return _array.at(i).second; }
	void setX(size_t, T);
	void setY(size_t, T);
private:
	std::vector<std::pair<T, T> > _array;
};

#endif /* DATA_H_ */
