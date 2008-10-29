#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <set>
#include <list>

class Observer;

class Observable
{
public:
	Observable();
	virtual ~Observable();
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notifyObservers();
private:
	std::set<Observer*> _observers;
};

#include "Observer.h"

#endif /*OBSERVABLE_H_*/
