#ifndef IDATA_TESTCASE_H
#define IDATA_TESTCASE_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <tulip/Graph.h>
class QScriptEngine;

class saveGraphTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(saveGraphTest);
      CPPUNIT_TEST(saveTest);
  CPPUNIT_TEST_SUITE_END();
private:
	tlp::Graph* _graph;
	QScriptEngine* _engine;
	std::string _savedFile;
	std::string filename;
public:
    void setUp();
    void tearDown();

protected:
    void saveTest();

};

#endif

