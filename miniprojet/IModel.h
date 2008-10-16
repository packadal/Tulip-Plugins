/*
 * IData.h
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#ifndef IMODEL_H_
#define IMODEL_H_

#include "IData.h"

/**
 * This interface describes an array of IData.
 * This typically is a list of functions.
 */
template <typename T> class IModel
{
	public:
		virtual size_t nbFunctions() = 0;
//		IData operator[](int);
		virtual IData<T>* get(int) = 0;
		virtual void add(const IData<T> *) = 0;
		virtual void erase(const IData<T>&) = 0;
};

#endif /* IMODEL_H_ */
