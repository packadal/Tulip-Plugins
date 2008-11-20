#ifndef SCRIPTTESTCASE_H_
#define SCRIPTTESTCASE_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include <QtScript>

#include "QData.h"

class ScriptTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(ScriptTest);
      CPPUNIT_TEST(invokeTest);
      CPPUNIT_TEST(newTest);
      CPPUNIT_TEST(argTest);
  CPPUNIT_TEST_SUITE_END();
private:
	QScriptEngine* _engine;
	QData* _data;
	float _testint;
public:
    void setUp();
    void tearDown();
protected:
    void invokeTest();
    void newTest();
    void argTest();
};

QScriptValue test(QScriptContext *context, QScriptEngine *engine);

#endif /* SCRIPTTESTCASE_H_ */
