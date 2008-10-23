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
	HistogramGroup(IData<float>* graphic = new Data);
	virtual ~HistogramGroup();

	inline void setGraphic(IData<float>* graphic) { _graphic = graphic;}
	inline IData<float>* getGraphic() { return _graphic; }
	inline void setScale(float f) { _scale = f; scale(f, f);}
	inline float getScale() {return _scale;}
	void updateGroup();
private:
	IData<float>* _graphic;
	float _scale;
};

#endif /* HISTOGRAMVIEWER_H_ */
