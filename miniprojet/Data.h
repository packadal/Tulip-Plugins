/*
 * Data.h
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet, rpatau, rnappee
 */

#ifndef DATA_H_
#define DATA_H_

#include <stdexcept>
#include <vector>
#include <map>

#include "IData.h"
#include "Observable.h"

/**
 * Implements the IData interface, so this will be manipulable as an IData item.
 * This is implemented using a vector of pairs, to represent a function
 * (pair.first ~= x; pair.second ~= y)
 */
template <typename T>class Data : public IData<T>, public Observable
{
public:
	inline size_t size() const { return _array.size(); }
	inline void add(T x, T y) { _array.push_back(std::pair<T, T>(x, y)); notifyObservers(); }
	inline T getX(int i) const { return _array.at(i).first; }
	inline T getY(int i) const { return _array.at(i).second; }
	virtual void setX(size_t index, T value)
	{
		if(index >= _array.size())
			throw new std::out_of_range("Data: index out of range");
		_array[index].first = value;
	}
	virtual void setY(size_t index, T value)
	{
		if(index >= _array.size())
			throw new std::out_of_range("Data: index out of range");
		_array[index].second = value;
	}
private:
	std::vector<std::pair<T, T> > _array;
};

#endif /* DATA_H_ */
