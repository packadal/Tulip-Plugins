/*
 * main.cpp
 *
 *  Created on: 7 janv. 2009
 *      Author: chuet
 */

#include "editor.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	ScriptEdit* editor = new ScriptEdit();
	editor->show();

	app.exec();
	return 0;
}
