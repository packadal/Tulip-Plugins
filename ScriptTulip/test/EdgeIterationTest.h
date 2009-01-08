#ifndef EdgeIterationTest_H_
#define EdgeIterationTest_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "TulipScriptEngine.h"

class EdgeIterationTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(EdgeIterationTest);
      CPPUNIT_TEST(invokeTest);
  CPPUNIT_TEST_SUITE_END();
private:
	TulipScriptEngine* _engine;
	std::string filenameReference, filename;
public:
    void setUp();
    void tearDown();
protected:
    void invokeTest(); // Entry point
    void testGetEdges();
	void testGetInEdges();
	void testGetOutEdges();
	void testGetInOutEdges();
};

#endif /* EdgeIterationTest_H_ */
