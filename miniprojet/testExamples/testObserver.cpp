#include "../Observer.h"
#include <iostream>
#include "../Data.h"
/*
class TestObserve : public Observable
{
private:
	int _valeur;
public:
	inline void setValeur(int valeur)
	{
		_valeur = valeur;
		notifyObservers();
	}
	inline int getValeur() { return _valeur; }
};
*/

class TestObservateur : public Observer
{
public:
	TestObservateur(Observable * obs):
		Observer()
	{
		obs->addObserver(this);
	}
	virtual void update(Observable * subject)
	{
		std::cout << "L'objet observé a changé ! Il est désormais de taille " << ((Data<int> *)(subject))->size() << "." << std::endl;
	}
};

int main()
{
	Data<int> * donneeObservee = new Data<int>;
	TestObservateur * objetObservateur = new TestObservateur(donneeObservee);
	donneeObservee->add(5, 2);
	donneeObservee->add(8, 5);
	delete donneeObservee;
	delete objetObservateur;
}
