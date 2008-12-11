/*
 * QEdge.cpp
 *
 *  Created on: 10-déc-08
 *      Author: dmothes
 */

#include "QEdge.h"

QEdge::QEdge() {
}

QEdge::QEdge(const tlp::edge& e)
:QObject(new QObject()), _edge(&e)
{
}

QEdge::~QEdge() {
}
