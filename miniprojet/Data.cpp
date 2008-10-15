/*
 * Data.cpp
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#include "Data.h"

#include <stdexcept>

template<typename T>
void Data<T>::setX(size_t index, T value)
{
	if(index >= _array.size())
		throw new std::out_of_range("Data: index out of range");
	_array[index].first = value;
}

template<typename T>
void Data<T>::setY(size_t index, T value)
{
	if(index >= _array.size())
		throw new std::out_of_range("Data: index out of range");
	_array[index].second = value;
}
