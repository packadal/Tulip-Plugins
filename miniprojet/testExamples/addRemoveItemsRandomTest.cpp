/*
 * addItems.cpp
 *
 *  Created on: 28 sept. 2008
 *      Author: packadal
 */

#include <cppunit/extensions/HelperMacros.h>

#include "kglengine2d.h"

class addRemoveItemsRandomTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(addRemoveItemsRandomTest);
	CPPUNIT_TEST(testIt);
	CPPUNIT_TEST_SUITE_END();

public:
	KGLEngine2d *engine;

	void setUp()
	{
		engine = KGLEngine2d::getInstance(640, 480, 20);
	}

	void tearDown()
	{
		engine->kill();
	}

	void testIt()
	{
		qsrand(QTime::currentTime().msec());

		bool lastOperationWasAdd = true;

		uint nbOperations = (qrand() % 1000);

		CPPUNIT_ASSERT(engine->itemsCount() == 0);
		std::set<KGLItem*> itemsSet;

		for(uint i = 0; i < nbOperations; ++i)
		{
			if(qrand() * (lastOperationWasAdd ? 3/2 : 3) > RAND_MAX)
			{
				itemsSet.insert(new KGLItem(""));
				engine->addGLItem(*itemsSet.end());
				lastOperationWasAdd = true;
			}
			else
			{
				if(itemsSet.size() > 0)
				{
					engine->eraseItem(*itemsSet.end());
					lastOperationWasAdd = false;
				}
				else
					lastOperationWasAdd = true;
			}
		}

		CPPUNIT_ASSERT(engine->itemsCount() == 0);
}
};

CPPUNIT_TEST_SUITE_REGISTRATION(addRemoveItemsRandomTest);
