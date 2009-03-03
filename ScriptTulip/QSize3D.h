/*
 * QSize3D.h
 *
 *  Created on: 20 févr. 2009
 *      Author: chuet
 */

#ifndef QSIZE3D_H_
#define QSIZE3D_H_

#include <QtCore/QObject>

#include <tulip/Size.h>
#include <tulip/Coord.h>

class QSize3D : public QObject {
	Q_OBJECT
public:
	QSize3D(const tlp::Size& s): _width(s.getW()), _height(s.getH()), _depth(s.getD()) {}
	QSize3D(const tlp::Coord& c): _width(c.getX()), _height(c.getY()), _depth(c.getZ()) {}
//	QSize3D(float w, float h, float d): _width(w), _height(h), _depth(d) {}
	QSize3D(const QSize3D& s): QObject(), _width(s.getW()), _height(s.getH()), _depth(s.getD()) {}

public slots:
	void set(float w, float h, float d) { _width = w; _height = h; _depth = d; }

	void setW(float w) { _width = w; }
	void setH(float h) { _height = h; }
	void setD(float d) { _depth = d; }

	float getW() const { return _width; }
	float getH() const { return _height; }
	float getD() const { return _depth; }

	void setX(float w) { _width = w; }
	void setY(float h) { _height = h; }
	void setZ(float d) { _depth = d; }

	float getX() const { return _width; }
	float getY() const { return _height; }
	float getZ() const { return _depth; }

	tlp::Size asSize3D() const { return tlp::Size(_width, _height, _depth); }
	tlp::Size asCoord() const { return tlp::Coord(_width, _height, _depth); }

private:
	float _width;
	float _height;
	float _depth;
};

#endif /* QSIZE3D_H_ */
