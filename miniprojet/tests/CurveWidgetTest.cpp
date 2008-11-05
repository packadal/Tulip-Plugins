#include "CurveWidgetTest.h"

const int X[5] = {10, 30, 40, 50, 60};
const int Y[5] = {3, 4, -10, 6, 12};

void CurveWidgetTest::setUp()
{
	_data = new Data();
	_data->add(X[0], Y[0]);
	_data->add(X[1], Y[1]);
	_data->add(X[2], Y[2]);
	_data->add(X[3], Y[3]);
	_data->add(X[4], Y[4]);

	_graphic = new CurveGroup(_data);
	addGraphic(_data, _graphic);
}

void CurveWidgetTest::tearDown()
{
}

void CurveWidgetTest::runTest()
{
	QList<QGraphicsItem*> itemList = _scene->items();
	QList<QGraphicsItem*> items;
	for(int i = 0; i < itemList.size(); i++)
	{
		if(itemList.value(i) == _graphic)
			items = itemList.value(i)->childItems();
	}

	try
	{
		for(int i = 0; i < items.size(); i++)
		{
			QGraphicsItem* g = items.value(i);
			QGraphicsLineItem* h = dynamic_cast<QGraphicsLineItem*> (g);
			if(h != 0)
			{
				//the coordinates system in Qt have the origin in the upper left corner
				//the conventional cartesian system have the origin in the lower left corner
				//so we invert the Y coordinates
				CPPUNIT_ASSERT(h->line().x1() == X[i]);
				CPPUNIT_ASSERT(h->line().y1() == -Y[i]);
				CPPUNIT_ASSERT(h->line().x2() == X[i+1]);
				CPPUNIT_ASSERT(h->line().y2() == -Y[i+1]);
			}
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_ASSERT(false);
	}
}

CPPUNIT_TEST_SUITE_REGISTRATION(CurveWidgetTest);
