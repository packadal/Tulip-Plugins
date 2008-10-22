/*
 * CurveViewer.h
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#ifndef CURVEVIEWER_H_
#define CURVEVIEWER_H_

#include <qwidget.h>

#include "IGraphic.h"

class CurveViewer : public QWidget, public IGraphic<float>
{
public:
	CurveViewer();
	void setGraphic(IData<float>*);
	IData<float>* getGraphic();
	void setScale(float);
	float getScale();
private:
	IData<float>* _array;
	float _scale;
};


#endif /* CURVEVIEWER_H_ */
