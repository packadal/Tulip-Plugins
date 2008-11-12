/*
 * HistogramViewer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#ifndef HISTOGRAMVIEWER_H_
#define HISTOGRAMVIEWER_H_

#include "QGraphic.h"
#include "Data.h"

class HistogramGroup : public QGraphic
{
public:
	HistogramGroup(IData<float>*);

	void setData(IData<float>*);
	inline void setColor(const QColor& color) { _color = color; }
	inline QColor getColor() { return _color; }
	inline QString getType() { return "Histogram"; }
private:
	QColor _color;
	uint _rectWidth;
};

#endif /* HISTOGRAMVIEWER_H_ */
