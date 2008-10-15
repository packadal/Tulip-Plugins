/*
 * IData.h
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#ifndef IMODEL_H_
#define IMODEL_H_

class IModel
{
	public:
		IData operator[](int);
		virtual IData get(int) = 0;
		virtual void add(IData) = 0;
		virtual void erase(IData) = 0;
};

#endif /* IMODEL_H_ */
