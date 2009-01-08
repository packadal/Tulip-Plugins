/*
 * QGraphTest.h
 *
 *  Created on: 7-jan-09
 *      Author: dmothes
 */

#ifndef QGRAPHTEST
#define QGRAPHTEST

#include <tulip/Graph.h>
#include <tulip/TlpTools.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestSuite.h>
#include "QGraph.h"

class QGraphTest : public CppUnit::TestCase {

  CPPUNIT_TEST_SUITE( QGraphTest );
  CPPUNIT_TEST( testAddDel );
  CPPUNIT_TEST( testClear );
  CPPUNIT_TEST( testOrderEdgeAndSwap );
  //CPPUNIT_TEST( testSubgraph);
  CPPUNIT_TEST( testDeleteSubgraph);
  //CPPUNIT_TEST( testInheritance);
  //CPPUNIT_TEST( testPropertiesIteration);
  CPPUNIT_TEST( testDegree);
  CPPUNIT_TEST_SUITE_END();

private:
  QGraph *graph;

public:
  void setUp();
  void tearDown();

  void testAddDel();
  void testClear();
  void testOrderEdgeAndSwap();
  //void testSubgraph();
  //void testSubgraphId();
  void testDeleteSubgraph();
  //void testInheritance();
  void testIterators();
  //void testPropertiesIteration();
  void testDegree();

 private:
  void build(unsigned int, unsigned int);
};

#endif
