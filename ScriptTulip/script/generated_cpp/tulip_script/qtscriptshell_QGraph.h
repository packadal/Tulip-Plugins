#ifndef QTSCRIPTSHELL_QGRAPH_H
#define QTSCRIPTSHELL_QGRAPH_H

#include <QGraph.h>

#include <QtScript/qscriptvalue.h>

class QtScriptShell_QGraph : public QGraph
{
public:
    QtScriptShell_QGraph();
    ~QtScriptShell_QGraph();

    bool  canPop();
    bool  canUnpop();
    unsigned int  deg(const QNode*  arg__1) const;
    QEdge*  existEdge(const QNode*  arg__1, const QNode*  arg__2) const;
    QIterator*  getEdges() const;
    QIterator*  getInEdges(const QNode*  arg__1) const;
    QNode*  getInNode(const QNode*  arg__1, unsigned int  arg__2) const;
    QIterator*  getInNodes(const QNode*  arg__1) const;
    QIterator*  getInOutEdges(const QNode*  arg__1) const;
    QIterator*  getInOutNodes(const QNode*  arg__1) const;
    QIterator*  getNodes() const;
    QEdge*  getOneEdge() const;
    QNode*  getOneNode() const;
    QIterator*  getOutEdges(const QNode*  arg__1) const;
    QNode*  getOutNode(const QNode*  arg__1, unsigned int  arg__2) const;
    QIterator*  getOutNodes(const QNode*  arg__1) const;
    unsigned int  indeg(const QNode*  arg__1) const;
    bool  isElement(const QEdge*  arg__1) const;
    bool  isElement(const QNode*  arg__1) const;
    bool  isMetaEdge(const QEdge*  arg__1) const;
    bool  isMetaNode(const QNode*  arg__1) const;
    unsigned int  numberOfEdges() const;
    unsigned int  numberOfNodes() const;
    QNode*  opposite(const QEdge*  arg__1, const QNode*  arg__2) const;
    unsigned int  outdeg(const QNode*  arg__1) const;
    void pop();
    void push();
    QNode*  source(const QEdge*  arg__1) const;
    QNode*  target(const QEdge*  arg__1) const;
    void unpop();

    QScriptValue __qtscript_self;
};

#endif // QTSCRIPTSHELL_QGRAPH_H
