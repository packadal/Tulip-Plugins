#ifndef GRAPHICLEGENDTEST_H_
#define GRAPHICLEGENDTEST_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <QColor>
#include "../Data.h"
#include "../CurveGroup.h"
#include "../HistogramGroup.h"
#include "../Viewer.h"

class GraphicLegendTest : public CppUnit::TestCase, public Viewer
{
	CPPUNIT_TEST_SUITE(GraphicLegendTest);
	CPPUNIT_TEST(runTest);
	CPPUNIT_TEST_SUITE_END();
private:
	IData<float>* _data, *_data2;
	Graphic<float>* _graphic, *_graphic2;
	QColor color;
	QColor color2;
	QList<Graphic<float>* > _graphics;
public:
    void setUp();
    void tearDown();

protected:
    void runTest();

};

#endif /* GRAPHICLEGENDTEST_H_ */
