/*
 * Axis.h
 *
 *  Created on: 6 nov. 2008
 *      Author: chuet
 */

#ifndef AXIS_H_
#define AXIS_H_

#include <QGraphicsItemGroup>

class Axis : public QGraphicsItemGroup
{
public:
	Axis();
	void updateAxis(float, float, float, float);
};

#endif /* AXIS_H_ */
