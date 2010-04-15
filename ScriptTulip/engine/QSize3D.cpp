#include "QSize3D.h"

QSize3D::QSize3D() :
	_width(0), _height(0), _depth(0) {
}
QSize3D::QSize3D(const tlp::Size& s) :
	_width(s.getW()), _height(s.getH()), _depth(s.getD()) {
}
QSize3D::QSize3D(const tlp::Coord& c) :
	_width(c.getX()), _height(c.getY()), _depth(c.getZ()) {
}
QSize3D::QSize3D(float w, float h, float d) :
	_width(w), _height(h), _depth(d) {
}
//QSize3D::QSize3D(const QSize3D& s) :
//	_width(s.getW()), _height(s.getH()), _depth(s.getD()) {
//}

void QSize3D::set(float w, float h, float d) {
	_width = w;
	_height = h;
	_depth = d;
}

void QSize3D::setW(float w) {
	_width = w;
}
void QSize3D::setH(float h) {
	_height = h;
}
void QSize3D::setD(float d) {
	_depth = d;
}

float QSize3D::getW() const {
	return _width;
}
float QSize3D::getH() const {
	return _height;
}
float QSize3D::getD() const {
	return _depth;
}

void QSize3D::setX(float w) {
	_width = w;
}
void QSize3D::setY(float h) {
	_height = h;
}
void QSize3D::setZ(float d) {
	_depth = d;
}

float QSize3D::getX() const {
	return _width;
}
float QSize3D::getY() const {
	return _height;
}
float QSize3D::getZ() const {
	return _depth;
}

tlp::Size QSize3D::asSize3D() const {
	return tlp::Size(_width, _height, _depth);
}

/*
tlp::Size QSize3D::asCoord() const {
	return tlp::Coord(_width, _height, _depth);
}*/
