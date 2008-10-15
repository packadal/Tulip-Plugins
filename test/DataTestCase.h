#ifndef IDATA_TESTCASE_H
#define IDATA_TESTCASE_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../miniprojet/IData.h"
#include "../miniprojet/Data.h"

class DataTestCase : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(IDataTestCase);
      CPPUNIT_TEST(loadTest);
  CPPUNIT_TEST_SUITE_END();
private:
	IData *_data;
public:
    void setUp();
    void tearDown();

protected:
    void loadTest();

};

#endif

