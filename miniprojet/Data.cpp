/*
 * Data.cpp
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#include "Data.h"

#include <stdexcept>

void Data::setX(size_t index, float value)
{
	if(index >= _array.size())
		throw new std::out_of_range("Data: index out of range");
	_array[index].first = value;
}

void Data::setY(size_t index, float value)
{
	if(index >= _array.size())
		throw new std::out_of_range("Data: index out of range");
	_array[index].second = value;
}
