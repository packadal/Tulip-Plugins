/*
 * Data.cpp
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#include "Data.h"

void Data::setX(int index, float value)
{
	if(index < _array.size())
	{
	}
}

void Data::setY(int index, float value)
{

}

float Data::getX(int i) const
{
	return _array.at(i).first;
}

float Data::getY(int i) const
{
	return _array.at(i).second;
}
