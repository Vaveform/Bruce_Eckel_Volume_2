#ifndef INTERFACE_H
#define INTERFACE_H

class Animal
{
	public:
		virtual void makeNoise() = 0;
		virtual void move() = 0;
};

class SuperHero
{
	public:
		virtual void savePersonFromFire() = 0;
		virtual void move() = 0;
};


#endif
