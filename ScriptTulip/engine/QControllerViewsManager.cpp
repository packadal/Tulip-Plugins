#include "QControllerViewsManager.h"
#include "TulipScriptEngine.h"

QControllerViewsManager::QControllerViewsManager(tlp::ControllerViewsManager* controller) : QObject(controller), _controllerViewsManager(controller) {
  
}

void QControllerViewsManager::changeGraphOfViews(QGraph* oldGraph, QGraph* newGraph)
{
  this->_controllerViewsManager->changeGraphOfViews(oldGraph->asGraph(), newGraph->asGraph());
}

void QControllerViewsManager::checkViewsGraphsHierarchy()
{
  this->_controllerViewsManager->checkViewsGraphsHierarchy();
}

void QControllerViewsManager::closeAllViews()
{
  this->_controllerViewsManager->closeAllViews();
}

void QControllerViewsManager::closeView(QView* view)
{
  this->_controllerViewsManager->closeView(view->asView());
}

void QControllerViewsManager::closeViewsRelatedToGraph(QGraph* graph)
{
  this->_controllerViewsManager->closeViewsRelatedToGraph(graph->asGraph());
}

QView* QControllerViewsManager::createView(const QString& name, QGraph* graph, const QScriptValue& data)
{
  return new QView(this->_controllerViewsManager->createView(name.toStdString(), graph->asGraph(), TulipScriptEngine::DataSetFromQScriptValue(data), false, QRect(0, 0, 0, 0), true));
}

void QControllerViewsManager::drawViews(bool init)
{
  this->_controllerViewsManager->drawViews(init);
}

QGraph* QControllerViewsManager::getCurrentGraph()
{
  new QGraph(this->_controllerViewsManager->getCurrentGraph());
}

QView* QControllerViewsManager::getCurrentView()
{
  return new QView(this->_controllerViewsManager->getCurrentView());
}

// void QControllerViewsManager::getData(QGraph** graph, DataSet* data)
// {
// }

QGraph* QControllerViewsManager::getGraph()
{
  return new QGraph(this->_controllerViewsManager->getGraph());
}

QGraph* QControllerViewsManager::getGraphOfView(QView* view)
{
  return view->getQGraph();
}

QString QControllerViewsManager::getNameOfView(QView* view)
{
  return QString::fromStdString(_controllerViewsManager->getNameOfView(view->asView()));
}

QView* QControllerViewsManager::getViewOfWidget(QWidget* widget)
{
  return new QView(this->_controllerViewsManager->getViewOfWidget(widget));
}

unsigned int QControllerViewsManager::getViewsNumber()
{
  return this->_controllerViewsManager->getViewsNumber();
}

QVector<QView*> QControllerViewsManager::getViewsOfGraph(QGraph* graph)
{
  QVector<QView*> result;
  //TODO implement
  return result;
}

QWidget* QControllerViewsManager::getWidgetOfView(QView* view)
{
  return view->getWidget();
}

void QControllerViewsManager::installInteractors(QView* view)
{
  this->_controllerViewsManager->installInteractors(view->asView());
}

void QControllerViewsManager::saveViewsGraphsHierarchies()
{
  this->_controllerViewsManager->saveViewsGraphsHierarchies();
}

void QControllerViewsManager::setCurrentGraph(QGraph* graph)
{
  this->_controllerViewsManager->setCurrentGraph(graph->asGraph());
}

void QControllerViewsManager::setData(QGraph* graph, const QScriptValue& value)
{
  this->_controllerViewsManager->setData(graph->asGraph(), TulipScriptEngine::DataSetFromQScriptValue(value));
}

void QControllerViewsManager::setGraphOfView(QView* view, QGraph* graph)
{
  this->_controllerViewsManager->setGraphOfView(view->asView(), graph->asGraph());
}

void QControllerViewsManager::setNameOfView(QView* view, const QString& name)
{
  this->_controllerViewsManager->setNameOfView(view->asView(), name.toStdString());
}

void QControllerViewsManager::setViewOfWidget(QWidget* widget, QView* view)
{
  this->_controllerViewsManager->setViewOfWidget(widget, view->asView());
}

void QControllerViewsManager::updateViewsOfGraph(QGraph* graph)
{
  this->_controllerViewsManager->updateViewsOfGraph(graph->asGraph());
}

void QControllerViewsManager::updateViewsOfSubGraphs(QGraph* graph)
{
  this->_controllerViewsManager->updateViewsOfSubGraphs(graph->asGraph());
}

