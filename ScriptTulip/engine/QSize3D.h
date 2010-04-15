#ifndef QSIZE3D_H_
#define QSIZE3D_H_

#include <QtCore/QObject>

#include <tulip/Size.h>
#include <tulip/Coord.h>

class QSize3D : public QObject {
	Q_OBJECT
public:
	QSize3D();
	QSize3D(const tlp::Size& s);
	QSize3D(const tlp::Coord& c);
	QSize3D(float w, float h, float d);
//	QSize3D(const QSize3D& s);

public slots:
	void set(float w, float h, float d);

	void setW(float w);
	void setH(float h);
	void setD(float d);

	float getW() const;
	float getH() const;
	float getD() const;

	void setX(float w);
	void setY(float h);
	void setZ(float d);

	float getX() const;
	float getY() const;
	float getZ() const;

	tlp::Size asSize3D() const;
	//tlp::Size asCoord() const;

private:
	float _width;
	float _height;
	float _depth;
};

#endif /* QSIZE3D_H_ */
