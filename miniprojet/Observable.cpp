#include "Observable.h"
#include <iostream>
Observable::Observable()
{
}

Observable::~Observable()
{
}

void Observable::addObserver(Observer* observer)
{
	_observers.insert(observer);
}

void Observable::removeObserver(Observer* observer)
{
	_observers.erase(observer);
}

void Observable::notifyObservers()
{
	for (std::set<Observer*>::const_iterator it = _observers.begin();
		it != _observers.end();
		it++)
		(*it)->update(this);
}
