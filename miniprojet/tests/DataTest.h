#ifndef IDATA_TESTCASE_H
#define IDATA_TESTCASE_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Data.h"

class DataTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(DataTest);
      CPPUNIT_TEST(loadTest);
  CPPUNIT_TEST_SUITE_END();
private:
	IData<float> *_data;
public:
    void setUp();
    void tearDown();

protected:
    void loadTest();

};

#endif

