/*
 * editor.h
 *
 *  Created on: 7 janv. 2009
 *      Author: chuet
 */

#ifndef EDITOR_H_
#define EDITOR_H_

#include <QApplication>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

#include "scriptedit.h"
#include "TulipScriptEngine.h"

class Editor : public QWidget {
	Q_OBJECT
public:
	Editor();
	virtual ~Editor();
public slots:
	void evaluate();
private:
	TulipScriptEngine* _engine;
	QLabel* _label;
	ScriptEdit* _editor;
};

#endif /* EDITOR_H_ */
