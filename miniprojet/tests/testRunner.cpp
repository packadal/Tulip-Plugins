/*
 * testRunner.cpp
 *
 *  Created on: 15 oct. 2008
 *      Author: dmothes
 */


#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>

#include <QApplication>
#include "GraphicsWidgetTest.h"
#include "ScriptWidgetTest.h"
#include <iostream>

int main (int argc, char* argv[])
{

	// Tests de recette graphiques
	QApplication app(argc, argv);

//    new GraphicsWidgetTest();

    new ScriptWidgetTest();

    app.exec();

    // Tests de recette "unitaires"
	CppUnit::TextUi::TestRunner runner;

	CppUnit::TestFactoryRegistry& registry = CppUnit::TestFactoryRegistry::getRegistry();

	CppUnit::Test *test = registry.makeTest();
	if (argc > 1)
		test = test->findTest(argv[1]);
	runner.addTest(test);
	bool failed = runner.run("", false);
	return !failed;
}
