#ifndef SETPROPERTY_H_
#define SETPROPERTY_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "TulipScriptEngine.h"

class SetPropertyTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(SetPropertyTest);
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
