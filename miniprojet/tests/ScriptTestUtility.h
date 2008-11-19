/*
 * ScriptTestUtility.h
 *
 *  Created on: 19 nov. 2008
 *      Author: chuet
 */

#ifndef SCRIPTTESTUTILITY_H_
#define SCRIPTTESTUTILITY_H_

#include <QObject>

#include "QData.h"

const float RESVALUE = 22.;

class ScriptTestUtility : public QObject
{
	Q_OBJECT
public slots:
	void passArg(QData* data)
	{
		data->setY(0, RESVALUE);
	}
};

#endif /* SCRIPTTESTUTILITY_H_ */
