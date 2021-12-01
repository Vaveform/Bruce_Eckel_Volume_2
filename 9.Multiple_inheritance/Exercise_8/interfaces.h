#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>


class SuperHero
{
	public:
		virtual void savePersonFromFire() = 0;
		virtual void move() = 0;
		virtual ~SuperHero() {std::cout << "SuperHero part destroyed" << std::endl;};
};


class VirtualDestroyer
{
	public:
		virtual ~VirtualDestroyer() { std::cout << "VirtualDestroyer destroyed" << std::endl;};
};

#endif
