#ifndef SETNODEVALUE_H_
#define SETNODEVALUE_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "TulipScriptEngine.h"

class SetNodeValueTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(SetNodeValueTest);
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
