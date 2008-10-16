/*
 * ICurveContainer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: rnappee
 */

#ifndef ICURVECONTAINER_H_
#define ICURVECONTAINER_H_

class ICurveContainer{
	public :
		virtual void addCurve(IData*)=0;
		virtual void removeCurve(IData*)=0;
		virtual void removeAll()=0;
		virtual void setScale(IData*, float)=0;
};

#endif /* ICURVEContainer_H_ */
