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
		virtual void setGraphic(IData<T>*) = 0;
		virtual IData<T>* getGraphic() = 0;
		virtual void setScale(float) = 0;
		virtual float getScale() = 0;
		virtual void updateGroup() = 0;
};

#endif /* GRAPHIC_H_ */
