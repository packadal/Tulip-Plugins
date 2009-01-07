#ifndef ITERATIONTEST_H_
#define ITERATIONTEST_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "TulipScriptEngine.h"

class IterationTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(IterationTest);
      CPPUNIT_TEST(invokeTest);
  CPPUNIT_TEST_SUITE_END();
private:
	TulipScriptEngine* _engine;
	std::string filenameReference, filename;
public:
    void setUp();
    void tearDown();
protected:
    void invokeTest(); // Entry point
};

#endif /* ITERATIONTEST_H_ */
