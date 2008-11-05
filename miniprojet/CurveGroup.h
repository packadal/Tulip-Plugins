/*
 * CurveGroup.h
 *
 *  Created on: 22 oct. 2008
 *      Author: lburelou
 */

#ifndef CURVEGROUP_H_
#define CURVEGROUP_H_

#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>

#include "Graphic.h"

class CurveGroup : public Graphic<float>
{
public:
	CurveGroup(IData<float>*);

	void setData(IData<float>*);
	inline void setColor(QColor color) { _color = color; }
	inline QColor getColor() { return _color; }
private:
	QColor _color;

};

#endif /* CURVEGROUP_H_ */
