#ifndef FETCHPROPERTYTEST_H_
#define FETCHPROPERTYTEST_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <QScriptEngine>
#include <QObject>

#include "QGraph.h"
#include "QEdge.h"
#include "QNode.h"

class FetchPropertyTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(FetchPropertyTest);
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
};

QProperty *_prop;

QScriptValue storeProperty(QScriptContext *context, QScriptEngine *engine);

#endif
