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
#include <QListWidgetItem>

template<typename T>
class GraphicLegend: public QListWidget
{
protected:
	QList<Graphic<T>*> _graphics;
public:

	GraphicLegend()
	{
		setEnabled(false);
	}

	void addGraphic(Graphic<T>* graphic)
	{
		_graphics.push_back(graphic);
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(graphic->getType());
		QColor color = graphic->getColor();
		color.setAlpha(255);
		item->setForeground(QBrush(color));
		addItem(item);
	}

	void removeGraphic(Graphic<T>* graphic)
	{
		_graphics.removeOne(graphic);
		clear();
		for (int i = 0; i < _graphics.size(); i++)
		{
			QListWidgetItem *item = new QListWidgetItem();
			item->setText(_graphics.at(i)->getType());
			QColor color = _graphics.at(i)->getColor();
			color.setAlpha(255);
			item->setForeground(QBrush(color));
			addItem(item);
		}

	}

	QList<Graphic<T>*> getGraphics()
	{
		return _graphics;
	}
};

#endif /* GRAPHICLEGEND_H_ */
