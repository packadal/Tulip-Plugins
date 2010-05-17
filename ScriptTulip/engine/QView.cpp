/*
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "QView.h"
#include "TulipScriptEngine.h"

QView::QView(View* view): QObject(view), _view(view)
{
}

QWidget *QView::construct(QWidget *parent)
{
  this->_view->construct(parent);
}

QWidget *QView::getWidget() {
  return this->_view->getWidget();
}

void QView::setData(QGraph *graph, const QScriptValue& value) {
 this->_view->setData(graph->asGraph(), TulipScriptEngine::DataSetFromQScriptValue(value)); 
} 

// void QView::getData(QGraph **graph,DataSet *dataSet) {
//  this->_view->getData((*graph)->asGraph(), dataSet); 
// } 

QGraph *QView::getGraph() {
 return _graph;
} 

// void QView::setInteractors(const std::list<Interactor *> &interactors) {
//  this->_view->; 
// } 
// 
// std::list<Interactor *> QView::getInteractors() {
//  this->_view->; 
// } 
// 
// void QView::setActiveInteractor(Interactor *interactor) {
//  this->_view->; 
// } 

void QView::createPicture(const QString &pictureName, int width, int height) {
 this->_view->createPicture(pictureName.toStdString(), width, height); 
} 

void QView::draw() {
  this->_view->draw();
}

void QView::refresh() {
  this->_view->refresh();
}

void QView::init() {
  this->_view->init();
}

void QView::setGraph(QGraph* graph)
{
  _graph = graph;
  this->_view->setGraph(graph->asGraph());
}
