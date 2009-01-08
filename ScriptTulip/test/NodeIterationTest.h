#ifndef NodeIterationTest_H_
#define NodeIterationTest_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "TulipScriptEngine.h"

class NodeIterationTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(NodeIterationTest);
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
    void testGetNodes();
	void testGetInNodes();
	void testGetOutNodes();
	void testGetInOutNodes();
};

#endif /* NodeIterationTest_H_ */
