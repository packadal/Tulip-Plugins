#include "CurveWidgetTest.h"
#include "../Viewer.h"
#include "../CurveGroup.h"
#include "../HistogramGroup.h"
#include "../IData.h"
#include "../Data.h"

#include <QObject>

const int X[5] = {10, 30, 40, 50, 60};
const int Y[5] = {3, 4, -10, 6, 12};

const int X1 = 10;
const int X2 = 30;
const int X3 = 40;
const int X4 = 50;
const int X5 = 60;

const int Y1 = 3;
const int Y2 = 4;
const int Y3 = -10;
const int Y4 = 6;
const int Y5 = 12;

void CurveWidgetTest::setUp()
{
	_data = new Data();
	_data->add(X1, Y1);
	_data->add(X2, Y2);
	_data->add(X3, Y3);
	_data->add(X4, Y4);
	_data->add(X5, Y5);

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

	for(int i = 0; i < items.size(); i++)
	{
		QGraphicsItem* g = items.value(i);
		QGraphicsLineItem* h = (QGraphicsLineItem*) g;
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

CPPUNIT_TEST_SUITE_REGISTRATION(CurveWidgetTest);
