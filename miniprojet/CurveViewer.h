/*
 * CurveViewer.h
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#ifndef CURVEVIEWER_H_
#define CURVEVIEWER_H_

#include <qwidget.h>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>

#include "IGraphic.h"

class CurveViewer : public QGraphicsItemGroup, public IGraphic<float>
{
public:
	CurveViewer();
	void setGraphic(IData<float>*);
	inline IData<float>* getGraphic(){return _array;};
	void setScale(float);
	inline float getScale(){return _scale;};
private:
	IData<float>* _array;
	float _scale;
};


#endif /* CURVEVIEWER_H_ */
