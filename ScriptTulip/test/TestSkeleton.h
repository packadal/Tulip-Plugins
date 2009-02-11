/*
   +----------------------------------------------------------------+
   |                                                                |
   |  _____  ___  ____   _  ___  ______                             |
   |  | __/ / __/ |   \ | | |  \ |_  _|                             |
   |  |__ | | |_  | ° / | | |° /   ||                               |
   |  /___| \__ \ |_|_\ |_| |_|    ||   TULIP                       |
   |                                                                |
   +----------------------------------------------------------------+
   |                                                                |
   +----------------------------------------------------------------+




 */


#ifndef TESTSKELETON_H_
#define TESTSKELETON_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class TestSkeleton : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(TestSkeleton);
      CPPUNIT_TEST(invokeTest);
  CPPUNIT_TEST_SUITE_END();
private:
	/* attributes here */
public:
    void setUp();
    void tearDown();
protected:
    void invokeTest(); // Entry point
};

#endif /* TESTSKELETON_H_ */
