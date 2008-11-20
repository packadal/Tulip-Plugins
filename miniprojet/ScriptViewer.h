#ifndef SCRIPTVIEWER_H_
#define SCRIPTVIEWER_H_

#include <QtScript>

#include "Viewer.h"
#include "Data.h"
#include "ui_ScriptViewer.h"

#include "CurveGroup.h"
#include "HistogramGroup.h"

class ScriptViewer: public Viewer
{
	Q_OBJECT
public:
	ScriptViewer();
	virtual ~ScriptViewer();

	void show() { QWidget::show(); }
	inline QScriptEngine* getEngine() { return _engine; }

public slots:
	QScriptValue addCurve(Data*);
	QScriptValue addHistogram(Data*);
    void evaluate();
    void check();
    void refresh();

protected:
	QScriptEngine* _engine;
	Ui::tulip_pluginsClass ui;
};

QScriptValue dataFactory(QScriptContext *context, QScriptEngine *engine);

#endif /* SCRIPTVIEWER_H_ */
