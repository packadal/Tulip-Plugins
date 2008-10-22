/*
 * IGraphicContainer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: rnappee
 */

#ifndef ICURVECONTAINER_H_
#define ICURVECONTAINER_H_

#include "IData.h"

template <typename T>class IGraphic{
	public :
		virtual void setGraphic(IData<T>*) = 0;
		virtual IData<T>* getGraphic() = 0;
		virtual void setScale(float) = 0;
		virtual float getScale() = 0;
};

#endif /* IGraphicContainer_H_ */
