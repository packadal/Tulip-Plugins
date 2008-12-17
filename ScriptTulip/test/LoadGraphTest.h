#ifndef LOAD_TESTCASE_H
#define LOAD_TESTCASE_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <tulip/Graph.h>

#include "TulipScriptEngine.h"

class LoadGraphTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(LoadGraphTest);
      CPPUNIT_TEST(loadTest);
  CPPUNIT_TEST_SUITE_END();
private:
	TulipScriptEngine* _engine;
	std::string filenameReference, filename;
public:
    void setUp();
    void tearDown();

protected:
    void loadTest();

};

#endif

