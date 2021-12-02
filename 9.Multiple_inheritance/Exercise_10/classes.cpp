#include "classes.h"

SuperlativeMan::~SuperlativeMan()
{
	std::cout << "SuperlativeMan destroyed" << std::endl;
}


// Passing parametr strength to SuperHero subobject using
// for right constructing SuperlativeMan object, but if we use
// SuperlativeMan for inheritance, inherited class should explicitly
// call constructor of base class and in SuperlativeMan ctr strength param not passing
// to SuperHero (or not if virtual base has default ctr)
SuperlativeMan::SuperlativeMan(int strength) : SuperHero(strength)
{
	std::cout << "SuperlativeMan part built" << std::endl; 
}


void SuperlativeMan::savePersonFromFire() {
	std::cout << "SuperlativeMan saved a person from fire" << std::endl;
}

void SuperlativeMan::move()
{
	std::cout << "SuperlativeMan moved" << std::endl;
}

void SuperlativeMan::eatFood(int calories)
{
	std::cout << "Eaten product with int number of calories: " << calories << std::endl;
}


void Amoeba::makeNoise()
{
	std::cout << "Amoeba made noise: aaaaa" << std::endl;
}

void Amoeba::eatFood(const std::string& product, double calories)
{
	std::cout << "Eaten product " << product 
		<< " with num of calories(in double): "
		<< calories << std::endl;
}


void Amoeba::savePersonFromFire()
{
	std::cout << "Amoeba saved a person from fire" << std::endl;
}


void Amoeba::eatFood(double calories)
{
	std::cout  << "Eaten default product with calories(in double): " 
		<< calories << std::endl;
}



Amoeba::~Amoeba()
{
	std::cout << "Amoeba destroyed" << std::endl;
}

// Passing parametr strength to SuperHero subobject using
// for right constructing Amoeba object, but if we use
// Amoeba for inheritance, inherited class should explicitly
// call constructor of base class and in Amoeba ctr strength param not passing
// to SuperHero (or not if virtual base has default ctr)
Amoeba::Amoeba(int strength) : SuperHero(strength){
	std::cout << "Amoeba part built" << std::endl;
}


void Amoeba::move()
{
	std::cout << "Amoeba moved" << std::endl;
}


void TarantulaWoman::makeNoise()
{
	std::cout << "TarantulaWoman made noise: shshsh" << std::endl;
}

void TarantulaWoman::savePersonFromFire()
{
	std::cout << "TarantulaWoman saved a person from fire" << std::endl;
}

void TarantulaWoman::move()
{
	std::cout << "TarantulaWoman moved" << std::endl;
}
TarantulaWoman::~TarantulaWoman()
{
	std::cout << "TarantulaWoman destroyed" << std::endl;
}

TarantulaWoman::TarantulaWoman(int strength) : SuperHero(strength)
{
	std::cout << "TarantulaWoman part built" << std::endl;
}


// For class with base classes which has virtual base class, to pass parametr
// of constructor to base we should call explicitly constructor for base virtual class
// Attention: parametr passed to base classes (Amoeba and SuperlativeMan) not pass
// to their virtual base class!!! To pass param we use explicit call of constructor
// SuperHero in SuperlativeAmoeba ctr!!!
SuperlativeAmoeba::SuperlativeAmoeba(int strength) : SuperHero(strength), SuperlativeMan(0), Amoeba(0){
	std::cout << "SuperlativeAmoeba part built" << std::endl;
}
SuperlativeAmoeba::~SuperlativeAmoeba() { std::cout << "SuperlativeAmoeba destroyed" << std::endl;}
