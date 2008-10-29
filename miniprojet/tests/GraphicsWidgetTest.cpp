#include "GraphicsWidgetTest.h"
#include "../Viewer.h"
#include "../CurveGroup.h"
#include "../HistogramGroup.h"
#include "../IData.h"
#include "../Data.h"

GraphicsWidgetTest::GraphicsWidgetTest()
{
     IData<float>* d = new Data();
     d->add(10, 3);
     d->add(30, 4);
     d->add(40, -10);
     d->add(50, 6);
     d->add(60, 12);

     CurveGroup* cg = new CurveGroup(d);
     HistogramGroup* hg = new HistogramGroup(d);
//     cg->setScale(10);
//     hg->setScale(10);
     new Viewer(d, cg);
     new Viewer(d, hg);
     d->add(70, -40);
}
