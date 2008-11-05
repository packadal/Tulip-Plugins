#include "CurveWidgetTest.h"
#include "../Viewer.h"
#include "../CurveGroup.h"
#include "../IData.h"
#include "../Data.h"

CurveWidgetTest::CurveWidgetTest()
{
     IData<float>* d = new Data();
     d->add(10, 3);
     d->add(30, 4);
     d->add(40, -10);
     d->add(50, 6);
     d->add(60, 12);

     CurveGroup* cg = new CurveGroup(d);

     new Viewer(d, cg);



}
