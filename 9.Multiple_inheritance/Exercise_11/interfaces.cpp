#include "interfaces.h"

// If we give definition like this in interfaces.h
// file for pure-virtual methods (= 0) like savePersonFromFire
// or move - compiler give a error - odr error
// For pure virtual methods we can give definition in unit translation (.cpp)
void SuperHero::savePersonFromFire()
{
	std::cout << "SuperHero saved person from fire" << std::endl;
}
void SuperHero::move()
{
	std::cout << "SuperHero moved" << std::endl;
}


int& SuperHero::getStrengthFactor()
{
	return strengthFactor;
}

const int& SuperHero::getStrengthFactor() const
{
	return strengthFactor;
}

std::ostream& SuperHero::printObject(std::ostream& os) const 
{
	return os << "SuperHero object has strengthFactor = " << getStrengthFactor() << std::endl; 
}

std::ostream& operator<<(std::ostream& os, const SuperHero& sup_h)
{
	return sup_h.printObject(os);
}

SuperHero& SuperHero::operator=(const SuperHero& sup_hero)
{
	std::cout << "Calling assignment operator for SuperHero" << std::endl;
	if(this == &sup_hero)
		return *this;
	strengthFactor = sup_hero.strengthFactor;
	return *this;
}


SuperHero::SuperHero(int strength) : strengthFactor(strength) {
	std::cout << "SuperHero part build with strength factor: " << strength << std::endl;
}
