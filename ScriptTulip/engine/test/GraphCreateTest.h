#ifndef GraphCreateTest_H_
#define GraphCreateTest_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <tulip/Graph.h>

#include <QObject>

class QEdge;
class Qgraph;
class QNode;
class TulipScriptEngine;

#include "utilsTest.h"

class GraphCreateTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(GraphCreateTest);
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
	std::string _savedFile;
};

#endif /* GraphCreateTest_H_ */
