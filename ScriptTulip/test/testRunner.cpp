#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>

#include <QApplication>
#include <iostream>

int main (int argc, char* argv[])
{
	QApplication app(argc, argv);

	CppUnit::TextUi::TestRunner runner;

	CppUnit::TestFactoryRegistry& registry = CppUnit::TestFactoryRegistry::getRegistry();

	CppUnit::Test *test = registry.makeTest();
	if (argc > 1)
		test = test->findTest(argv[1]);
	runner.addTest(test);
	bool failed = runner.run("", false);
	return !failed;
}
