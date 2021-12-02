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


SuperHero::SuperHero(int strength) : strengthFactor(strength) {
	std::cout << "SuperHero part build with strength factor: " << strength << std::endl;
}
