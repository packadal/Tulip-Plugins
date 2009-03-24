#include "QColorProperty.h"
#include "QGraph.h"

QColorProperty::QColorProperty(const QGraph* g) :
	QProperty(new tlp::ColorProperty(g->asGraph())) {
}

QColorProperty::QColorProperty(tlp::ColorProperty* p) :
	QProperty(p) {
}

QColorProperty::~QColorProperty() {
	delete dynamic_cast<tlp::ColorProperty*> (_property);
}

tlp::ColorProperty* QColorProperty::asProperty() {
	return dynamic_cast<tlp::ColorProperty*> (_property);
}

QColor* QColorProperty::getNodeDefaultValue() {
	tlp::Color
			c =
					dynamic_cast<tlp::ColorProperty*> (_property)->getNodeDefaultValue();
	return new QColor(c.getR(), c.getG(), c.getB(), c.getA());
}

QColor* QColorProperty::getEdgeDefaultValue() {
	tlp::Color
			c =
					dynamic_cast<tlp::ColorProperty*> (_property)->getEdgeDefaultValue();
	return new QColor(c.getR(), c.getG(), c.getB(), c.getA());
}

QColor* QColorProperty::getNodeValue(QNode* n) {
	tlp::Color c = dynamic_cast<tlp::ColorProperty*> (_property)->getNodeValue(
			n->asNode());
	return new QColor(c.getR(), c.getG(), c.getB(), c.getA());
}

QColor* QColorProperty::getEdgeValue(QEdge* e) {
	tlp::Color c = dynamic_cast<tlp::ColorProperty*> (_property)->getEdgeValue(
			e->asEdge());
	return new QColor(c.getR(), c.getG(), c.getB(), c.getA());
}

void QColorProperty::setNodeValue(QNode* n, QColor* v) {
	tlp::Color* c = new tlp::Color((unsigned char) v->red(),
			(unsigned char) v->green(), (unsigned char) v->blue(),
			(unsigned char) v->alpha());
	dynamic_cast<tlp::ColorProperty*> (_property)->setNodeValue(n->asNode(), *c);
}

void QColorProperty::setEdgeValue(QEdge* e, QColor* v) {
	tlp::Color* c = new tlp::Color((unsigned char) v->red(),
			(unsigned char) v->green(), (unsigned char) v->blue(),
			(unsigned char) v->alpha());
	dynamic_cast<tlp::ColorProperty*> (_property)->setEdgeValue(e->asEdge(), *c);
}

void QColorProperty::setAllNodeValue(QColor* v) {
	tlp::Color* c = new tlp::Color((unsigned char) v->red(),
			(unsigned char) v->green(), (unsigned char) v->blue(),
			(unsigned char) v->alpha());
	dynamic_cast<tlp::ColorProperty*> (_property)->setAllNodeValue(*c);
}

void QColorProperty::setAllEdgeValue(QColor* v) {
	tlp::Color* c = new tlp::Color((unsigned char) v->red(),
			(unsigned char) v->green(), (unsigned char) v->blue(),
			(unsigned char) v->alpha());
	dynamic_cast<tlp::ColorProperty*> (_property)->setAllEdgeValue(*c);
}
