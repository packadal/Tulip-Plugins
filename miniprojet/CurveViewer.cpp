/*
 * CurveViewer.cpp
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#include "CurveViewer.h"

CurveViewer::CurveViewer()
{
}

void CurveViewer::setGraphic(IData<float>* array)
{
	_array = array;
}

IData<float>* CurveViewer::getGraphic()
{
	return _array;
}

void CurveViewer::setScale(float scale)
{
	_scale = scale;
}

float CurveViewer::getScale()
{
	return _scale;
}
