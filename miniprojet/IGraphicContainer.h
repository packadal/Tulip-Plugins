/*
 * IGraphicContainer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: rnappee
 */

#ifndef ICURVECONTAINER_H_
#define ICURVECONTAINER_H_

#include "IData.h"

template <typename T>class IGraphicContainer{
	public :
		virtual void addGraphic(IData<T>*) = 0;
		virtual void removeGraphic(IData<T>*) = 0;
		virtual void removeAll() = 0;
		virtual void setScale(IData<T>*, float) = 0;
};

#endif /* IGraphicContainer_H_ */
