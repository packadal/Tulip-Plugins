/*
 * IGraphicContainer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: rnappee
 */

#ifndef QGRAPHIC_H_
#define QGRAPHIC_H_

#include <QGraphicsItemGroup>

#include "Graphic.h"
#include "Observer.h"
#include "IData.h"

class QGraphic : public QObject, public Graphic<float>
{
	Q_OBJECT
public slots :
	virtual void setGraphic(IData<float>*) = 0;
	virtual IData<float>* getGraphic() = 0;
	virtual void setScale(float) = 0;
	virtual float getScale() = 0;

	virtual void update(Observable * subject) = 0;
};

#endif /* QGRAPHIC_H_ */
