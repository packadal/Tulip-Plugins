#include "ColorGraphicTest.h"

void ColorGraphicTest::setUp()
{
	_data = new Data();
	_data->add(10, 3);
	_data->add(30, 4);
	_data->add(40, -10);
	_data->add(50, 6);
	_data->add(60, 12);

	_data2->add(10, 5);
	_data2->add(20, 12);

	_graphic = new CurveGroup(_data);
	_graphic2 = new HistogramGroup(_data2);

	QColor color(255, 0, 0);
	QColor color2(0, 0, 255);
	_graphic->setColor(color); // RED
	_graphic2->setColor(color2); // BLUE

	addGraphic(_data, _graphic);
	addGraphic(_data2, _graphic2);

	CPPUNIT_ASSERT_EQUAL(color, _graphic->getColor());
	CPPUNIT_ASSERT_EQUAL(color2, _graphic2->getColor());

	QList<QGraphicsItem *> children = _graphic->childItems();

	for (QList<QGraphicsItem *>::const_iterator it = children.begin(); it != children.end(); it++)
		(*it)->co
}

void ColorGraphicTest::tearDown()
{
}

void ColorGraphicTest::runTest()
{
	CPPUNIT_ASSERT(true);
}

CPPUNIT_TEST_SUITE_REGISTRATION(ColorGraphicTest);
