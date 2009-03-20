#ifndef QLAYOUTPROPERTY_H_
#define QLAYOUTPROPERTY_H_

#include "QProperty.h"
#include "QSize3D.h"
#include "QStdSet.h"

#include <QObject>

#include <tulip/LayoutProperty.h>

QSTDVECTOR(Size3D, tlp::Coord);

class QLayoutProperty: public QProperty
{

Q_OBJECT

public:

	QLayoutProperty(const QGraph *);
	QLayoutProperty(tlp::LayoutProperty*);
	virtual ~QLayoutProperty();
	tlp::LayoutProperty* asProperty();

public slots:

	// Bindings from AbstractProperty
	QSize3D* getNodeDefaultValue();
	QSize3DVector* getEdgeDefaultValue();
	QSize3D* getNodeValue(const QNode* n);
	QSize3DVector* getEdgeValue(const QEdge* e);
	void setNodeValue(const QNode* n, const QSize3D* v);
	void setEdgeValue(const QEdge* e, const QSize3DVector* v);
	void setAllNodeValue(const QSize3D* v);
	void setAllEdgeValue(const QSize3DVector* v);

	//TODO
	// Specific methods
	/*QSize3D* getMax(Graph *graph = 0);
	QSize3D* getMin(Graph *graph = 0);
	void translate(const tlp::Vector<float, 3>& v, Graph *graph = 0);
	void translate(const tlp::Vector<float, 3>& v, Iterator<node> *, Iterator<edge> *);
	void scale(const tlp::Vector<float, 3>& v, Graph *graph = 0);
	void scale(const tlp::Vector<float, 3>& v, Iterator<node> *, Iterator<edge> *);
	void rotateZ(const double& alpha, Graph *graph = 0);
	void rotateX(const double& alpha, Iterator<node> *, Iterator<edge> *);
	void rotateY(const double& alpha, Iterator<node> *, Iterator<edge> *);
	void rotateZ(const double& alpha, Iterator<node> *, Iterator<edge> *);
	void center(Graph *graph = 0);
	void normalize(Graph *graph = 0);
	void perfectAspectRatio();
	void resetBoundingBox();
	double edgeLength(edge e);
	double averageAngularResolution(Graph *graph = 0);
	double averageAngularResolution(const node n, Graph *graph = 0);
	std::vector<double> angularResolutions(const node n, Graph *graph = 0);
	unsigned int crossingNumber();*/

};

#endif /* QLAYOUTPROPERTY_H_ */

