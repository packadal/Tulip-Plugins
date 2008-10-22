/*
 * HistogramViewer.cpp
 *
 *  Created on: 16 oct. 2008
 *      Author: chuet
 */

#include "HistogramViewer.h"

HistogramViewer::HistogramViewer(IData<float>* graphic)
:QGraphicsItemGroup(), _graphic(graphic)
{
	updateGroup();
}

void HistogramViewer::setScale(IData<float>*, float)
{

}

void HistogramViewer::updateGroup()
{

}
