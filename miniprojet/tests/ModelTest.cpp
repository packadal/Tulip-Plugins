/*
 * ModelTestCase.cpp
 *
 *  Created on: 16 oct. 2008
 *      Author: dmothes
 */

#include "ModelTest.h"
#include "../Model.h"
#include "../Data.h"
#include <cstdlib>
#include <ctime>


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
	Data<float> courbe;
}



