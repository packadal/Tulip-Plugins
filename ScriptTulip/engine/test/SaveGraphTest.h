#ifndef SAVELOAD_TESTCASE_H
#define SAVELOAD_TESTCASE_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <tulip/Graph.h>

class TulipScriptEngine;

class SaveGraphTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(SaveGraphTest);
      CPPUNIT_TEST(saveTest);
  CPPUNIT_TEST_SUITE_END();
private:
	TulipScriptEngine* _engine;
	std::string filenameReference, filename;
public:
    void setUp();
    void tearDown();

protected:
    void saveTest();

};

#endif

