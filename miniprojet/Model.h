/*
 * Model.h
 *
 *  Created on: 15 oct. 2008
 *      Author: chuet
 */

#ifndef MODEL_H_
#define MODEL_H_

#include "IModel.h"
#include "Data.h"

/**
 * Implementation of the IModel interface.
 * Quite straightforward implementation using std::vector.
 */
class Model : public IModel<float>
{
public:
	~Model();

	inline size_t nbFunctions() { return _array.size(); }
//	IData operator[](int);
	inline IData<float>* get(int index) { return _array.at(index); }
	inline void add(IData<float> * d) { _array.push_back(d); }
	void erase(const IData<float>*);
private:
	std::vector<IData<float>*> _array;
};

#endif /* MODEL_H_ */
