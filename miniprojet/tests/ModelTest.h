/*
 * ModelTestCase.h
 *
 *  Created on: 16 oct. 2008
 *      Author: dmothes
 */

#ifndef MODELTESTCASE_H_
#define MODELTESTCASE_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "IModel.h"


class ModelTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(ModelTest);
      CPPUNIT_TEST(loadTest);
  CPPUNIT_TEST_SUITE_END();
private:
	IModel<float> *_model;
public:
    void setUp();
    void tearDown();

protected:
    void loadTest();

};

#endif /* MODELTESTCASE_H_ */
