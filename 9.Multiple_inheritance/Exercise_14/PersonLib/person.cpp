#include "person.h"


Person::Person(const std::string& n, short a) : name(n), age(a)
{
	std::cout << "Person object created with name = " << name << " and age = " << age << std::endl;
}

void Person::work()
{
	std::cout << "Person " << name << " made work" << std::endl;
}

Person::~Person()
{
	std::cout << "Person with name = " << name << " and age = " << age << " destroyed" << std::endl;
}
