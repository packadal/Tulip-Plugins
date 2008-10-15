#ifndef IDATA_TESTCASE_H
#define IDATA_TESTCASE_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "IData.h"
#include "IDataImpl.h"

class IDataTestCase : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(IDataTestCase);
      CPPUNIT_TEST(loadTest);
      CPPUNIT_TEST(storeTest);
  CPPUNIT_TEST_SUITE_END();
private:

public:
    void setUp();
    void tearDown();

protected:
    void loadTest();
    void storeTest();

};

#endif

