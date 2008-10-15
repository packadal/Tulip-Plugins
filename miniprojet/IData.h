/*
 * IData.h
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#ifndef IDATA_H_
#define IDATA_H_

class IData<T>
{
	public:
		virtual void add(T, T) = 0;
		virtual T getX(int) = 0;
		virtual T getY(int) = 0;
		virtual void setX(int, T) = 0;
		virtual void setY(int, T) = 0;
};

#endif /* IDATA_H_ */
