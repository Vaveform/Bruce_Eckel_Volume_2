#include "classes.h"

SuperlativeMan::~SuperlativeMan()
{
	std::cout << "SuperlativeMan destroyed" << std::endl;
}

SuperlativeMan& SuperlativeMan::operator=(const SuperlativeMan& other)
{
	std::cout << "Calling assignment operator for SuperlativeMan" << std::endl;
	if(this == &other)
		return *this;
	// Here we can assign fields of SuperlativeMan
	// Then we call copy assignment operator for SuperHero subobject
	// and passing other by chain of the inheritance
	SuperHero::operator=(other);
	// static_cast<SuperHero&>(*this) = other;
	// dynamic_cast<SuperHero&>(*this) = other;
	// or using pointers
	return *this; 
}


void SuperlativeMan::copyAssignSuperlativeManPart(const SuperlativeMan& other)
{
	std::cout << "Copying SuperlativeMan part from other object" << std::endl; 
}

std::ostream& SuperlativeMan::printObject(std::ostream& os) const
{
	return os << "SuperlativeMan has strengthFactor = " << getStrengthFactor() << std::endl;
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


void Amoeba::copyAssignAmoebaPart(const Amoeba& other)
{
	std::cout << "Copying Amoeba part from other object" << std::endl;
}

std::ostream& Amoeba::printObject(std::ostream& os) const
{
	return os << "Amoeba has strengthFactor = " << getStrengthFactor() << std::endl;
}

Amoeba& Amoeba::operator=(const Amoeba& other)
{
	std::cout << "Calling assignment operator for Amoeba" << std::endl;
	if(this == &other)
		return *this;
	// Here we can assign fields of SuperlativeMan
	// Then we call copy assignment operator for SuperHero subobject
	// and passing other by chain of the inheritance
	SuperHero::operator=(other);
	// static_cast<SuperHero&>(*this) = other;
	// dynamic_cast<SuperHero&>(*this) = other;
	return *this; 
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




SuperlativeAmoeba::SuperlativeAmoeba(int strength) : superlative_man(strength), amoeba(strength){
	std::cout << "SuperlativeAmoeba part built" << std::endl;
}
SuperlativeAmoeba::~SuperlativeAmoeba() { std::cout << "SuperlativeAmoeba destroyed" << std::endl;}

std::ostream& operator<<(std::ostream& os, const SuperlativeAmoeba& sup_amoeba)
{
	return os << "SuperlativeAmoeba has strengthFactor = " << sup_amoeba.amoeba.getStrengthFactor() << std::endl;
}




SuperlativeAmoeba& SuperlativeAmoeba::operator=(const SuperlativeAmoeba& other)
{
	std::cout << "Calling assignment operator for SuperlativeAmoeba" << std::endl;
	if(this == &other)
		return *this;
	amoeba = other.amoeba;
	superlative_man = other.superlative_man;
	//superlative_man.copyAssignAmoebaPart(other.amoeba);
	return *this;
}
