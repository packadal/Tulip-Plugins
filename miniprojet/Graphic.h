/*
 * IGraphicContainer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: rnappee
 */

#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include <QGraphicsItemGroup>

#include "Observer.h"
#include "IData.h"

template <typename T>
class Graphic : public QGraphicsItemGroup
{
	public :
		virtual void setData(IData<T>*) = 0;
		virtual void setColor(const QColor&) = 0;
		virtual QColor getColor() = 0;
		virtual QString getType() = 0;
};

#endif /* GRAPHIC_H_ */
