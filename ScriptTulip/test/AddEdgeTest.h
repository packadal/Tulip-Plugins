#ifndef AddEdgeTest_H_
#define AddEdgeTest_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <tulip/Graph.h>

#include <QObject>

class QScriptValue;
class QScriptContext;
class QScriptEngine;

class QEdge;
class TulipScriptEngine;

class AddEdgeTest: public QObject, public CppUnit::TestCase {
	CPPUNIT_TEST_SUITE( AddEdgeTest);
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

static QEdge* _edge;
QScriptValue testEdge(QScriptContext*, QScriptEngine*);

#endif /* AddEdgeTest_H_ */
