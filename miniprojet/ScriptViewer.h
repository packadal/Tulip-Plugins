/*
 * ScriptViewer.h
 *
 *  Created on: 29 oct. 2008
 *      Author: chuet
 */

#ifndef SCRIPTVIEWER_H_
#define SCRIPTVIEWER_H_

#include <QtScript>

#include "Viewer.h"
#include "QData.h"
#include "ui_tulip_plugins.h"

class ScriptViewer: public Viewer
{
	Q_OBJECT
public:
	ScriptViewer(QData*, Graphic<float>*);
	virtual ~ScriptViewer();

	void show() { QWidget::show(); }

public slots:
    void evaluate();
    void check();
    QScriptValue addGraphic();
//    QScriptValue getGraphics(QData*);

private:
	QScriptEngine* _engine;
	Ui::tulip_pluginsClass ui;
};

#endif /* SCRIPTVIEWER_H_ */
