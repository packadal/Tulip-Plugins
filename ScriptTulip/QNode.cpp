/*
 * QNode.cpp
 *
 *  Created on: 10-déc-08
 *      Author: dmothes
 */

#include "QNode.h"

QNode::QNode() {
}

QNode::QNode(const tlp::node& n)
:QObject(new QObject()), _node(&n)
{
}

QNode::~QNode() {
}
