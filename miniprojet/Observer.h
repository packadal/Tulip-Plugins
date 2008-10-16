#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>

class Observable;

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update(Observable * subject) = 0;
};

#include "Observable.h"

#endif /*OBSERVER_H_*/
