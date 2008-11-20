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
	Q_OBJECT
public:
	HistogramGroup();
	HistogramGroup(IData<float>*);

	void setData(IData<float>*);
	inline void setColor(const QColor& color) { _color = color; }
	inline void setColor(int r, int g, int b, int alpha = 255) { _color = QColor(r, g, b, alpha); }
	inline QColor getColor() { return _color; }
	inline QString getType() { return "Histogram"; }
private:
	QColor _color;
	uint _rectWidth;
};

#endif /* HISTOGRAMVIEWER_H_ */
