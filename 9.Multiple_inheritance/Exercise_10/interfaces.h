#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>


class SuperHero
{
	private:
		int strengthFactor;
	protected:
		SuperHero(int stregnth = 0);
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
