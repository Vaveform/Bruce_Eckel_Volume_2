#include "pets.h"


// Pet Abstract Base Class
Pet::Pet() : name("Unnamed"), age(5) {}

Pet::Pet(const char* _name, unsigned short _age) : name(_name), age(_age) {}

Pet::Pet(const std::string& _name, unsigned short _age) : name(_name), age(_age) {}

Pet::~Pet() {}

const std::string& Pet::Name() const
{
	return name;
}

unsigned short Pet::Age() const
{
	return age;
}

// Dog class

Dog::Dog() {}

Dog::Dog(const char* _name, unsigned short _age) : Pet(_name, _age) {}

Dog::Dog(const std::string& _name, unsigned short _age) : Pet(_name, _age) {}

void Dog::PetInfo() const 
{
	std::cout << "Dog with name " << Name() << " " << Age() << " years old" << std::endl;
}

void Dog::Bark() const
{
	std::cout << "Dog " << Name() << " barked" << std::endl;
}

void Dog::Eat(Beef* b){
	b->Eat();
	std::cout << "Dog " << Name() << " ate beef" << std::endl; 
	delete b;
}

// Cat class

Cat::Cat() {}

Cat::Cat(const char* _name, unsigned short _age) : Pet(_name, _age) {}

Cat::Cat(const std::string& _name, unsigned short _age) : Pet(_name, _age) {}

void Cat::PetInfo() const 
{
	std::cout << "Cat with name " << Name() << " " << Age() << " years old" << std::endl;
}

void Cat::Meow() const
{
	std::cout << "Cat " << Name() << " meowed" << std::endl;
}

void Cat::Eat(Fish* f){
	f->Eat();
	std::cout << "Cat "<< Name() << " ate fish" << std::endl; 
	delete f;
}

// Horse class 


Horse::Horse() {}

Horse::Horse(const char* _name, unsigned short _age) : Pet(_name, _age) {}

Horse::Horse(const std::string& _name, unsigned short _age) : Pet(_name, _age) {}

void Horse::PetInfo() const 
{
	std::cout << "Horse with name " << Name() << " " << Age() << " years old" << std::endl;
}

void Horse::Igogo() const
{
	std::cout << "Horse " << Name() << " igogoed" << std::endl;
}

void Horse::Eat(Oats* o){
	o->Eat();
	std::cout << "Horse "<< Name() << " ate oats" << std::endl; 
	delete o;
}



