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
	void setColor(QColor);
private:
	QColor _color;
};

#endif /* HISTOGRAMVIEWER_H_ */
