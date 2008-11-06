#include "AddDeleteTest.h"


void AddDeleteTest::setUp()
{
	_data = new Data();
	_data->add(10, 3);
	_data->add(30, 4);
	_data->add(40, -10);
	_data->add(50, 6);
	_data->add(60, 12);

	_data2 = new Data();
	_data2->add(10, 5);
	_data2->add(20, 12);

	_graphic = new CurveGroup(_data);
	_graphic2 = new HistogramGroup(_data2);
	_graphic3 = new CurveGroup(_data2);
	_graphic4 = new HistogramGroup(_data);


}

void AddDeleteTest::tearDown()
{
}

QList<QGraphicsItemGroup *> AddDeleteTest::fetchGroups(QList<QGraphicsItem *> items) {
	QList<QGraphicsItemGroup *> groups;

	for (QList<QGraphicsItem *>::const_iterator it = items.begin(); it != items.end(); it++) {
		QGraphicsItemGroup * group = (*it)->group();
		if (!groups.contains(group) && group != 0)
			groups.append((*it)->group());
	}
	return groups;
}

void AddDeleteTest::runTest()
{
	CPPUNIT_ASSERT(fetchGroups(_scene->items()).size() == 0);

	addGraphic(_data, _graphic);
	// Axis added at the first call of addGraphic() as a node

	CPPUNIT_ASSERT(fetchGroups(_scene->items()).size() == 2);

	addGraphic(_data2, _graphic2);
	CPPUNIT_ASSERT(fetchGroups(_scene->items()).size() == 3);

	addGraphic(_data2, _graphic3);
	CPPUNIT_ASSERT(fetchGroups(_scene->items()).size() == 4);

	addGraphic(_data, _graphic4);
	CPPUNIT_ASSERT(fetchGroups(_scene->items()).size() == 5);

	removeGraphic(_data, _graphic);
	CPPUNIT_ASSERT(fetchGroups(_scene->items()).size() == 4);

	removeGraphic(_data2, _graphic2);
	CPPUNIT_ASSERT(fetchGroups(_scene->items()).size() == 3);

	removeGraphic(_data2, _graphic3);
	CPPUNIT_ASSERT(fetchGroups(_scene->items()).size() == 2);

	removeGraphic(_data, _graphic4);
	// Axis removed at the last call of removeGraphic()
	CPPUNIT_ASSERT(fetchGroups(_scene->items()).size() == 0);
}

CPPUNIT_TEST_SUITE_REGISTRATION(AddDeleteTest);
