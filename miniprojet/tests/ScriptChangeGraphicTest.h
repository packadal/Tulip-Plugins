#ifndef IDATA_TESTCASE_H
#define IDATA_TESTCASE_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "ScriptViewer.h"
#include "QGraphic.h"

class ScriptChangeGraphicTest : public CppUnit::TestCase, public ScriptViewer
{
  CPPUNIT_TEST_SUITE(ScriptChangeGraphicTest);
      CPPUNIT_TEST(loadTest);
  CPPUNIT_TEST_SUITE_END();
private:
	IData<float> *_data;
	QGraphic *_graphic;
public:
    void setUp();
    void tearDown();

protected:
    void loadTest();

};

#endif

