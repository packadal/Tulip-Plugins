/*
 * testRunner.cpp
 *
 *  Created on: 28 sept. 2008
 *      Author: packadal
 */

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>

#include <qapplication.h>

//#include <KApplication>
//#include <KAboutData>
//#include <KCmdLineArgs>

int main (int argc, char* argv[])
{
	CppUnit::TextUi::TestRunner runner;

	QApplication app(argc, argv);

	CppUnit::TestFactoryRegistry& registry = CppUnit::TestFactoryRegistry::getRegistry();

	CppUnit::Test *test = registry.makeTest();
	if (argc > 1)
		test = test->findTest(argv[1]);
	runner.addTest(test);
	bool failed = runner.run("", false);
	return !failed;
}
