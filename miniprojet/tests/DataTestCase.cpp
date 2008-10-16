#include "DataTestCase.h"
#include <cstdlib>
#include <ctime>


CPPUNIT_TEST_SUITE_REGISTRATION(DataTestCase);


void DataTestCase::setUp()
{
	_data = new Data<float>();
}

void DataTestCase::tearDown()
{
	delete _data;
	_data = NULL;
}


void DataTestCase::loadTest()
{

	srand(time(NULL));

	float x;
	float y;

	for(int i = 0; i< 100000; i++)
	{
		x =   (float) (1000.0 * (rand() / (RAND_MAX + 1.0))) - 500.0;
		y =   (float) (1000.0 * (rand() / (RAND_MAX + 1.0))) - 500.0;

		_data->add(x, y);
		CPPUNIT_ASSERT_EQUAL( x, _data->getX( i ) );
		CPPUNIT_ASSERT_EQUAL( y, _data->getY( i ) );

		CPPUNIT_ASSERT_ASSERTION_FAIL( CPPUNIT_ASSERT_EQUAL( x, _data->getX( i ) + 1) );
		CPPUNIT_ASSERT_ASSERTION_FAIL( CPPUNIT_ASSERT_EQUAL( y, _data->getY( i ) + 1) );

		x =   (float) (1000.0 * (rand() / (RAND_MAX + 1.0))) - 500.0;
		y =   (float) (1000.0 * (rand() / (RAND_MAX + 1.0))) - 500.0;

		_data->setX(i, x);
		_data->setY(i, y);

		CPPUNIT_ASSERT_EQUAL( x, _data->getX( i ) );
		CPPUNIT_ASSERT_EQUAL( y, _data->getY( i ) );

		CPPUNIT_ASSERT_ASSERTION_FAIL( CPPUNIT_ASSERT_EQUAL( x, _data->getX( i ) + 1) );
		CPPUNIT_ASSERT_ASSERTION_FAIL( CPPUNIT_ASSERT_EQUAL( y, _data->getY( i ) + 1) );
	}
	CPPUNIT_ASSERT_EQUAL((size_t)100000, _data->size());
}



