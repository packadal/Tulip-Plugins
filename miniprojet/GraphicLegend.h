/*
 * GraphicLegend.h
 *
 *  Created on: 5 nov. 2008
 *      Author: rpatau
 */

#ifndef GRAPHICLEGEND_H_
#define GRAPHICLEGEND_H_

#include <QList>
#include "Graphic.h"
#include <QWidget>

template <typename T>
class GraphicLegend : public QWidget
{
	protected :
		QList<Graphic<T>* > _graphics;
	public :


		void addGraphic(Graphic<T>* graphic)
		{
			_graphics.push_back(graphic);
		}

		void removeGraphic(Graphic<T>* graphic)
		{
			_graphics.removeOne(graphic);

		}

		QList<Graphic<T>* > getGraphics()
		{
			return _graphics;
		}
};

#endif /* GRAPHICLEGEND_H_ */
