/*
 * Axis.h
 *
 *  Created on: 6 nov. 2008
 *      Author: chuet
 */

#ifndef AXIS_H_
#define AXIS_H_

#include <QString>
#include <QGraphicsItemGroup>

class Axis: public QGraphicsItemGroup
{
public:
	Axis();
	void updateAxis(float, float, float, float);
private:
	void addtext(float, float, int, int fontSize = 3);
};

#endif /* AXIS_H_ */
