#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include <QGraphicsItemGroup>

#include "Observer.h"
#include "IData.h"

template <typename T>
class Graphic : public QGraphicsItemGroup
{
	public :
		virtual void setData(IData<T>*) = 0;
		virtual void setColor(const QColor&) = 0;
		virtual void setColor(int r, int g, int b, int alpha = 255) = 0;
		virtual QColor getColor() = 0;
		virtual QString getType() = 0;
};

#endif /* GRAPHIC_H_ */
