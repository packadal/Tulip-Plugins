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
#include "Data.h"

class HistogramViewer : public QGraphicsItemGroup, public IGraphic<float>
{
public:
	HistogramViewer(IData<float>* graphic = new Data);
	inline void setGraphic(IData<float>* graphic) { _graphic = graphic; updateGroup(); }
	inline IData<float>* getGraphic() { return _graphic; }
	inline void setScale(float scale) { _scale = scale; }
	inline float getScale() {return _scale; }
private:
	void updateGroup();
	IData<float>* _graphic;
	float _scale;
};

#endif /* HISTOGRAMVIEWER_H_ */
