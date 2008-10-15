#include "IDataTestCase.h"
#include "Data.h"

CPPUNIT_TEST_SUITE_REGISTRATION(IDataTestCase);


void IDataTestCase::setUp()
{
	_data = new Data();
}

void IDataTestCase::tearDown()
{
	delete _data;
	_data = NULL;
}


void IDataTestCase::loadTest()
{
	double x1 = 1, x2 = -2.2, x3 = 3.003;
	double y1 = 4, y2 = 4.2, y3 = -4.003;

	_data->add( x1, y1 );
	_data->add( x2, y2 );
	_data->add( x3, y3 );

	CPPUNIT_ASSERT_EQUAL( x1, _data->getX( 0 ) );
	CPPUNIT_ASSERT_EQUAL( x3, _data->getX( 2 ) );
	CPPUNIT_ASSERT_EQUAL( y2, _data->getY( 1 ) );
	CPPUNIT_ASSERT_EQUAL( y3, _data->getY( 2 ) );

	CPPUNIT_ASSERT_ASSERTION_FAIL( CPPUNIT_ASSERT_EQUAL( x1, _data->getX( 1 ) ) );
	CPPUNIT_ASSERT_ASSERTION_FAIL( CPPUNIT_ASSERT_EQUAL( y2, _data->getY( 0 ) ) );

	_data->setX( 0, x3 );
	_data->setY( 1, y1 );
	
	CPPUNIT_ASSERT_EQUAL( x3, _data->getX( 0 ) );
	CPPUNIT_ASSERT_EQUAL( y1, _data->getY( 1 ) );

	CPPUNIT_ASSERT_ASSERTION_FAIL( CPPUNIT_ASSERT_EQUAL( x3, _data->getX( 1 ) ) );
	CPPUNIT_ASSERT_ASSERTION_FAIL( CPPUNIT_ASSERT_EQUAL( y1, _data->getY( 0 ) ) );

}



