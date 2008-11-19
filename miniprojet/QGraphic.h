/*
 * IGraphicContainer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: rnappee
 */

#ifndef QGRAPHIC_H_
#define QGRAPHIC_H_

#include <QGraphicsItemGroup>
#include <QScriptable>

#include "Graphic.h"
#include "Observer.h"
#include "IData.h"

class QGraphic : public QObject, public Graphic<float>
{
	Q_OBJECT
public slots :
	virtual void setData(IData<float>*) = 0;
	virtual void setColor(const QColor&) = 0;
	virtual QColor getColor() = 0;
	virtual QString getType() = 0;
};

#endif /* QGRAPHIC_H_ */
