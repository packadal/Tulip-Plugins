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
#include "Data.h"
#include "ui_ScriptViewer.h"

class ScriptViewer: public Viewer
{
	Q_OBJECT
public:
	ScriptViewer();
	virtual ~ScriptViewer();

	void show() { QWidget::show(); }
	inline QScriptEngine* getEngine() { return _engine; }
	void addGraphic(IData<float>*, Graphic<float>*);

public slots:
	void addCurve(Data*);
	void addHistogram(Data*);
    void evaluate();
    void check();

protected:
	QScriptEngine* _engine;
	Ui::tulip_pluginsClass ui;
};

QScriptValue dataFactory(QScriptContext *context, QScriptEngine *engine);

#endif /* SCRIPTVIEWER_H_ */
