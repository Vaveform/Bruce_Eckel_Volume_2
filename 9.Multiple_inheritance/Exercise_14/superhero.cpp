#include "superhero.h"

SuperHero::SuperHero(const std::string& n, short a, int strength) : Person(n, a), strengthFactor(strength)
{
	std::cout << "Superhero object created with strengthFactor = " << strengthFactor << std::endl;
}

void SuperHero::work()
{
	std::cout << "Superhero object with strengthFactor " << strengthFactor << " call Person::work(): ";
	Person::work();
}

SuperHero::~SuperHero()
{
	std::cout << "SuperHero with strengthFactor = " << strengthFactor << " destroyed"<< std::endl;
}

