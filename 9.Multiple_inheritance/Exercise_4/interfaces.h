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


// We can write additional interfaces to change move behaviour for 
// Animal and SuperHero
// It is a good pattern - we have interfaces with methods which have
// the same name - so we can define only one method if we inherite from this 
// interfaces. We write two other interfaces in which we send responsible
// from move() method to other virtual method with other name by defining
// move which calling this pure virtual method 
class Animal_Moving : public Animal
{
	public:
		virtual void Animal_move() = 0;
		void move() final
		{
			Animal_move(); // we can override move by calling pure virtual method!!!
		}

};

class SuperHero_Moving : public SuperHero
{
	public:
		virtual void SuperHero_move() = 0;
		void move() final
		{
			SuperHero_move();
		}
};
// Now calling move - for Animal and SuperHero can have different behaviour
// But calling move for obj or pointers to type TarantulaWoman or Amoeba (inherited from both
// interfaces) cause ambigious!!!. With templates it is not good solution.


class VirtualDestroyer
{
	public:
		virtual ~VirtualDestroyer() { std::cout << "VirtualDestroyer destroyed" << std::endl;};
};

#endif
