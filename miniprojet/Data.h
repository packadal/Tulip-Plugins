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
	inline size_t size() const { return _array.size(); }
	inline void add(float x, float y) { _array.push_back(std::pair<float, float>(x, y)); }
	inline float getX(int i) const { return _array.at(i).first; }
	inline float getY(int i) const { return _array.at(i).second; }
	void setX(size_t, float);
	void setY(size_t, float);
private:
	std::vector<std::pair<float, float> > _array;
};

#endif /* DATA_H_ */
