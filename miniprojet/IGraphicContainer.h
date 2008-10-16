/*
 * IGraphicContainer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: rnappee
 */

#ifndef ICURVECONTAINER_H_
#define ICURVECONTAINER_H_

class IGraphicContainer{
	public :
		virtual void addGraphic(IData*) = 0;
		virtual void removeGraphic(IData*) = 0;
		virtual void removeAll() = 0;
		virtual void setScale(IData*, float) = 0;
};

#endif /* IGraphicContainer_H_ */
