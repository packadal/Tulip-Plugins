#ifndef GRAPHICSWIDGETTEST_H
#define GRAPHICSWIDGETTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Data.h"
#include "HistogramGroup.h"
#include "Viewer.h"

class HistogramWidgetTest : public CppUnit::TestCase, public Viewer
{
  CPPUNIT_TEST_SUITE(HistogramWidgetTest);
      CPPUNIT_TEST(runTest);
  CPPUNIT_TEST_SUITE_END();
private:
	IData<float> *_data;
	Graphic<float> *_graphic;
public:
    void setUp();
    void tearDown();

protected:
    void runTest();

};

#endif
