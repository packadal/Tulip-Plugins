#include "GraphicsWidgetTest.h"
#include "../Viewer.h"
#include "../CurveGroup.h"
#include "../HistogramGroup.h"
#include "../IData.h"
#include "../Data.h"

void GraphicsWidgetTest::setUp()
{
	_data = new Data();
	_data->add(10, 3);
	_data->add(30, 4);
	_data->add(40, -10);
	_data->add(50, 6);
	_data->add(60, 12);

	_graphic = new CurveGroup(_data);
	_graphic2 = new HistogramGroup(_data);
	_graphic->setColor(QColor(255, 0, 0));
	_graphic2->setColor(QColor(0, 0, 255));

	_viewer = new Viewer(_data, _graphic);
	_viewer2 = new Viewer(_data, _graphic2);

	_data->add(70, -40);

	_viewer->addGraphic(_data, _graphic2);
	_viewer->removeGraphic(_data, _graphic2);
	_viewer->scale(3);
	_viewer2->scale(2);
}

void GraphicsWidgetTest::tearDown()
{
}

void GraphicsWidgetTest::runTest()
{
	CPPUNIT_ASSERT(true);
}

CPPUNIT_TEST_SUITE_REGISTRATION(GraphicsWidgetTest);
