#include "GraphicLegendTest.h"
#include <QList>
#include <iostream>

void GraphicLegendTest::setUp()
{
	color = QColor(255, 0, 0);
	color2 = QColor(0, 0, 255);

	_data = new Data();
	_data2 = new Data();
	_data->add(10, 3);
	_data->add(30, 4);
	_data->add(40, -10);
	_data->add(50, 6);
	_data->add(60, 12);

	_data2->add(10, 5);
	_data2->add(20, 12);

	_graphic = new CurveGroup(_data);
	_graphic2 = new HistogramGroup(_data2);

	_graphic->setColor(color); // RED
	_graphic2->setColor(color2); // BLUE

	addGraphic(_data, _graphic);
	addGraphic(_data2, _graphic2);
}

void GraphicLegendTest::tearDown()
{
}

void GraphicLegendTest::runTest()
{
	_graphics = _graphicLegend->getGraphics();
	CPPUNIT_ASSERT((size_t)2 == _graphics.size());

	CPPUNIT_ASSERT(color == _graphics.front()->getColor());
	CPPUNIT_ASSERT(color2 == _graphics.back()->getColor());
}

CPPUNIT_TEST_SUITE_REGISTRATION(GraphicLegendTest);
