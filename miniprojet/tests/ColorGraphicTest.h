#ifndef GRAPHICSWIDGETTEST_H
#define GRAPHICSWIDGETTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../Data.h"
#include "../CurveGroup.h"
#include "../HistogramGroup.h"
#include "../Viewer.h"

class ColorGraphicTest : public CppUnit::TestCase, public Viewer
{
	CPPUNIT_TEST_SUITE(ColorGraphicTest);
    CPPUNIT_TEST(runTest);
    CPPUNIT_TEST_SUITE_END();
private:
	IData<float> *_data, *_data2;
	Graphic<float> *_graphic, *_graphic2;
public:
    void setUp();
    void tearDown();

protected:
    void runTest();

};

#endif
