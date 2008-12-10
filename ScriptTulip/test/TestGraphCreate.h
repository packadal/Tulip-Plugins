#ifndef TESTGRAPHCREATE_H_
#define TESTGRAPHCREATE_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <tulip/Graph.h>

class TestGraphCreate : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(TestGraphCreate);
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

#endif /* TESTGRAPHCREATE_H_ */
