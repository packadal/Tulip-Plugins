/*
 * IData.h
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#ifndef IDATA_H_
#define IDATA_H_

template<typename T> class IData
{
	public:
		virtual size_t size() const = 0;
		virtual void add(T, T) = 0;
		virtual T getX(int) const = 0;
		virtual T getY(int) const = 0;
		virtual void setX(size_t, T) = 0;
		virtual void setY(size_t, T) = 0;
};

#endif /* IDATA_H_ */
