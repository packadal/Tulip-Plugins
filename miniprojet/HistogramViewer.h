/*
 * HistogramViewer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#ifndef HISTOGRAMVIEWER_H_
#define HISTOGRAMVIEWER_H_

#include <QGraphicsItemGroup>

#include "IGraphic.h"

class HistogramViewer : public QGraphicsItemGroup, public IGraphic<float>
{
public:
	HistogramViewer(IData<float>* graphic = 0);
	inline void setGraphic(IData<float>* graphic) { _graphic = graphic; updateGroup(); }
	inline IData<float>* getGraphic() { return _graphic; }
	void setScale(IData<float>*, float);
private:
	void updateGroup();
	IData<float>* _graphic;
};

#endif /* HISTOGRAMVIEWER_H_ */
