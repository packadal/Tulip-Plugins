#include <stdexcept>
#include <cstdlib>
#include <ctime>

#include "ModelTest.h"
#include "Model.h"
#include "Data.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ModelTest);


void ModelTest::setUp()
{
	_model = new Model();
}

void ModelTest::tearDown()
{
	delete _model;
	_model = NULL;
}


void ModelTest::loadTest()
{
	IData<float> * courbe = new Data();
	_model->add(courbe);
	CPPUNIT_ASSERT_EQUAL(courbe, _model->get(0));
	CPPUNIT_ASSERT_EQUAL((size_t)1, _model->nbFunctions());
	_model->erase(courbe);
	try
	{
		_model->get(0);
		CPPUNIT_FAIL("Exception not thrown");
	}
	catch(std::out_of_range e){ ; }

	IData<float> * courbe2 = new Data();
	_model->add(courbe);
	_model->add(courbe2);
	CPPUNIT_ASSERT_EQUAL(courbe2, _model->get(1));
	CPPUNIT_ASSERT_EQUAL((size_t)2, _model->nbFunctions());
	_model->erase(courbe2);
	try
		{
			_model->get(1);
			CPPUNIT_FAIL("Exception not thrown");
		}
		catch(std::out_of_range e){ ; }
}



