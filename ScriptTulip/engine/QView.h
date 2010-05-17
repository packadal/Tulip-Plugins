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

#ifndef QVIEW_H
#define QVIEW_H

#include <QObject>
#include <tulip/Graph.h>
#include <tulip/Interactor.h>
#include <tulip/View.h>

#include "QGraph.h"

using namespace tlp;

class QView : public QObject
{
  Q_OBJECT
  public:
    QView(View* view);
  public slots:
    virtual QWidget *construct(QWidget *parent);
    virtual QWidget *getWidget();
    virtual void setData(QGraph *graph, const QScriptValue& value);
//     virtual void getData(Graph **graph, const QScriptValue& value);
    virtual QGraph *getGraph();
//     virtual void setInteractors(const std::list<Interactor *> &interactors);
//     virtual std::list<Interactor *> getInteractors();
//     virtual void setActiveInteractor(Interactor *interactor);
    virtual void createPicture(const QString &pictureName, int width=0, int height=0);

    virtual std::list<std::pair<QWidget *,std::string> > getConfigurationWidget() {return std::list<std::pair<QWidget *,std::string> >();}
    virtual std::string getRealViewName() {return "";}

    View* asView() {
      return this->_view;
    }
    QGraph* getQGraph() {
      return this->_graph;
    }

  public slots:

    virtual void setGraph(QGraph *graph);

    virtual void draw();
    virtual void refresh();
    virtual void init();

  signals:
    void elementSelected(unsigned int eltId, bool isNode);

//     void requestChangeGraph(View *,Graph *);
  private:
    View* _view;
    QGraph* _graph;
};

#endif // QVIEW_H
