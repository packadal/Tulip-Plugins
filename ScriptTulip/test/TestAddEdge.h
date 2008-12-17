#ifndef TESTADDEDGE_H_
#define TESTADDEDGE_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <tulip/Graph.h>

#include <QObject>

#include "QGraph.h"
#include "QEdge.h"
#include "QNode.h"
#include "TulipScriptEngine.h"

#include "utilsTest.h"

class TestAddEdge: public QObject, public CppUnit::TestCase {
	CPPUNIT_TEST_SUITE( TestAddEdge);
	CPPUNIT_TEST(invokeTest);
	CPPUNIT_TEST_SUITE_END();
	private:
		/* attributes here */
	public:
		void setUp();
		void tearDown();
	protected:
		void invokeTest(); // Entry point
		TulipScriptEngine *_engine;
};

#endif /* TESTADDEDGE_H_ */
