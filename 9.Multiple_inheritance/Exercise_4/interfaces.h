#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>

// First version of solution - using smart pointers like shared_ptr


// Second version of solution - Animal and SuperHero using default (non-virtual)
// destructors, but we can not to call delete for pointer of this types (Animal* and SuperHero*)
// - inherited object do not call their destructors (error: invalid pointer). So we can add interface which has 
// virtual destructor and inherite from him. This action added virtual destructor
// to hierarchy and allow descendants to call their destructors by chain
class Animal
{
	public:
		virtual void makeNoise() = 0;
		virtual void move() = 0;
		~Animal() { std::cout << "Animal part destroyed" << std::endl;};
};

class SuperHero
{
	public:
		virtual void savePersonFromFire() = 0;
		virtual void move() = 0;
		~SuperHero() {std::cout << "SuperHero part destroyed" << std::endl;};
};


class VirtualDestroyer
{
	public:
		virtual ~VirtualDestroyer() { std::cout << "VirtualDestroyer destroyed" << std::endl;};
};

#endif
