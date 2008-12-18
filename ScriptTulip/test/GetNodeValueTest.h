#ifndef GETNODEVALUE_H_
#define GETNODEVALUE_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "TulipScriptEngine.h"

class GetNodeValueTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(GetNodeValueTest);
      CPPUNIT_TEST(invokeTest);
  CPPUNIT_TEST_SUITE_END();
private:
	TulipScriptEngine* _engine;
public:
    void setUp();
    void tearDown();
protected:
    void invokeTest(); // Entry point
};

#endif
