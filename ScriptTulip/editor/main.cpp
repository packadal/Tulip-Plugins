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
	Editor* editor = new Editor();
	editor->show();

	app.exec();
	return 0;
}
