/**
 *     +-------------------------------------------+
 *     |  _____  ___  ____   _  ___  ______        |
 *     |  | __/ / __/ |   \ | | |  \ |_  _|        |
 *     |  |__ | | |_  | ° / | | |° /   ||          |
 *     |  /___| \__ \ |_|_\ |_| |_|    || ULIP  |
 *     |                                           |
 *     |         A XP Project by...                |
 * 	   +-------------------------------------------+
 *	   | Red Ranger ----------------- Romain Patau |
 *	   | Blue Ranger ----------------- Rudy Nappée |
 *	   | Pink Ranger <3 ------------- Charles Huet |
 *	   | Pink Ranger bis ------------ Loïc Burelou |
 *	   | Black Ranger -------------- Quentin Enard |
 *	   | Green Ranger -------------- Damien Mothes |
 *	   | Spermix Zero -------------- Maxxx Orbison |
 *     +-------------------------------------------+
 *     |   Copyright © XP Ranger Team 2008-2009    |
 *     |      May the soucoupe be with you !       |
 *	   +-------------------------------------------+
 */



#ifndef TESTSKELETON_H_
#define TESTSKELETON_H_

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class TestSkeleton : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(TestSkeleton);
      CPPUNIT_TEST(invokeTest);
  CPPUNIT_TEST_SUITE_END();
private:
	/* attributes here */
public:
    void setUp();
    void tearDown();
protected:
    void invokeTest(); // Entry point
};

#endif /* TESTSKELETON_H_ */
