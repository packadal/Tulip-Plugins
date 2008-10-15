#include "Observable.h"

Observable::Observable()
{
}

Observable::~Observable()
{
}

void Observable::addObserver(Observer * observer)
{
	_observers.insert(observer);
}

void Observable::removeObserver(Observer * observer) 
{
	_observers.erase(observer);
}

void Observable::notifyObservers()
{
	for (std::set<Observer *>::const_iterator i = _observers.begin();
		i != _observers.end();
		i++)
		(*i)->update(this);
}
