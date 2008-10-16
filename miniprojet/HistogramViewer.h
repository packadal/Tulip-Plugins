/*
 * HistogramViewer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#ifndef HISTOGRAMVIEWER_H_
#define HISTOGRAMVIEWER_H_

#include <qwidget.h>

#include "IGraphicContainer.h"

class HistogramViewer : public QWidget, public IGraphicContainer<float>
{
public:
	HistogramViewer();
};

#endif /* HISTOGRAMVIEWER_H_ */
