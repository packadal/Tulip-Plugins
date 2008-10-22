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
	~CurveGroup();

	inline void setGraphic(IData<float>* graphic) { _graphic = graphic; updateGroup(); }
	inline IData<float>* getGraphic(){return _graphic;};
	void setScale(float f){_scale = f; scale(f,f);}
	inline float getScale(){return _scale;};
	void update(Observable * subject);
private:
	void updateGroup();
	IData<float>* _graphic;
	float _scale;
};


#endif /* CURVEGROUP_H_ */
