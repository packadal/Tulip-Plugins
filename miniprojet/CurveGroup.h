/*
 * CurveGroup.h
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#ifndef CURVEGROUP_H_
#define CURVEGROUP_H_

#include <qwidget.h>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>

#include "Graphic.h"

class CurveGroup : public Graphic<float>
{
public:
	CurveGroup(IData<float>*);
	void setGraphic(IData<float>*);
	inline IData<float>* getGraphic(){return _graphic;};
	void setScale(float f){_scale = f; scale(f,f);}
	inline float getScale(){return _scale;};
private:
	IData<float>* _graphic;
	float _scale;
};


#endif /* CURVEGROUP_H_ */
