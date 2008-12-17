#ifndef TESTGRAPHCREATE_H_
#define TESTGRAPHCREATE_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <tulip/Graph.h>

#include <QScriptEngine>
#include <QObject>

#include "QGraph.h"
#include "QEdge.h"
#include "QNode.h"

#include "utilsTest.h"

class TestGraphCreate : public QObject, public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(TestGraphCreate);
      CPPUNIT_TEST(invokeTest);
  CPPUNIT_TEST_SUITE_END();
private:
	/* attributes here */
public:
    void setUp();
    void tearDown();
protected:
    void invokeTest(); // Entry point
	QScriptEngine *_engine;
	std::string _savedFile;
};

#endif /* TESTGRAPHCREATE_H_ */
