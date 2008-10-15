/*
 * Data.h
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#ifndef DATA_H_
#define DATA_H_

#include <vector>
#include <map>

#include "IData.h"

class Data : public IData<float>
{
public:
	inline int size() const { return _array.size(); }
	inline void add(float x, float y) { _array.push_back(std::pair<float, float>(x, y)); }
	float getX(int) const;
	float getY(int) const;
	void setX(int, float);
	void setY(int, float);
private:
	std::vector<std::pair<float, float> > _array;
};

#endif /* DATA_H_ */
