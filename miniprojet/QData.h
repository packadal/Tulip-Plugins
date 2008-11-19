/*
 * QData.h
 *
 *  Created on: 29 oct. 2008
 *      Author: chuet
 */

#ifndef QDATA_H_
#define QDATA_H_

#include <QObject>

#include "IData.h"

class QData : public QObject, public IData<float>
{
	Q_OBJECT
public slots:
		virtual size_t size() const = 0;
		virtual void add(float, float) = 0;
		virtual float getX(int) const = 0;
		virtual float getY(int) const = 0;
		virtual void setX(unsigned int, float) = 0;
		virtual void setY(unsigned int, float) = 0;
		virtual float getXMin() const = 0;
		virtual float getYMin() const = 0;
		virtual float getXMax() const = 0;
		virtual float getYMax() const = 0;
};

#endif /* QDATA_H_ */
