/*
 * Model.cpp
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#include "Model.h"

Model::~Model()
{
	std::vector<IData<float>*>::iterator it; // = _array.begin();
	while(it != _array.end())
	{
		delete *it;
		*it = NULL;
		it = _array.erase(it);
	}
}

void Model::erase(const IData<float>* d)
{
	std::vector<IData<float>*>::iterator it = _array.begin();
	while(it != _array.end())
	{
		if((*it) == d)
			it = _array.erase(it);
		else
			++it;
	}
}
