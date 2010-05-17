#ifndef QCONTROLLER_H
#define QCONTROLLER_H

#include <QObject>

#include <tulip/Controller.h>
#include <tulip/ControllerViewsManager.h>

#include "QGraph.h"
#include "QView.h"

using namespace tlp;

class QControllerViewsManager : public QObject {
  Q_OBJECT
public:
    QControllerViewsManager(tlp::ControllerViewsManager* controller);
public slots:

    //============== Controller
//   virtual void attachMainWindow(MainWindowFacade facade);
    void setData(QGraph *graph, const QScriptValue& value);;
//   virtual void getData(QGraph **graph,DataSet *data);
    QGraph *getGraph();

//     MainWindowFacade* getMainWindowFacade(){
//       return &mainWindowFacade;
//     }

//   void attachMainWindow(MainWindowFacade facade);

    QGraph *getCurrentGraph();
    void setCurrentGraph(QGraph *graph);
    QView *getCurrentView();
    unsigned int getViewsNumber();
    QGraph *getGraphOfView(QView *view);
    QVector<QView*> getViewsOfGraph(QGraph *graph);
    void setGraphOfView(QView *view,QGraph *graph);
    QView *getViewOfWidget(QWidget *widget);
    void setViewOfWidget(QWidget *widget,QView *view);
    QWidget *getWidgetOfView(QView *view);
    QString getNameOfView(QView *view);
    void setNameOfView(QView *view,const QString &name);
    void closeAllViews();
    void closeView(QView *view);
    void closeViewsRelatedToGraph(QGraph* graph);

    //*************************************************************************
    QView* createView(const QString& name, QGraph* graph, const QScriptValue& data = QScriptValue());
    void installInteractors(QView *view);
    void updateViewsOfGraph(QGraph *graph);
    void updateViewsOfSubGraphs(QGraph *graph);
    void changeGraphOfViews(QGraph *oldGraph,QGraph *newGraph);
    void drawViews(bool init=false);
    void saveViewsGraphsHierarchies();
    void checkViewsGraphsHierarchy();

private:
    tlp::ControllerViewsManager* _controllerViewsManager;

};

#endif // QCONTROLLER_H
