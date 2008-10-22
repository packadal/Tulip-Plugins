/*
 * HistogramViewer.h
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#ifndef HISTOGRAMVIEWER_H_
#define HISTOGRAMVIEWER_H_

#include "Graphic.h"
#include "Data.h"

class HistogramGroup : public Graphic<float>
{
public:
	HistogramGroup(IData<float>* graphic = new Data);
	virtual ~HistogramGroup();

	inline void setGraphic(IData<float>* graphic) { _graphic = graphic; updateGroup(); }
	inline IData<float>* getGraphic() { return _graphic; }
	inline void setScale(float f) { _scale = f; scale(f, f); }
	inline float getScale() {return _scale; }
private:
	void updateGroup();
	IData<float>* _graphic;
	float _scale;
};

#endif /* HISTOGRAMVIEWER_H_ */
