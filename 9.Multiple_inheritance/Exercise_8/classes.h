#ifndef CLASSES_H
#define CLASSES_H

#include "interfaces.h"
#include <iostream>


// virtual key word in inheritance
// add to inherited class 8 bytes to save offset to base class if base class has field or fields.
// For example we have SuperlativeAmoeba, which inherited from
// SuperlativeMan and Amoeba - and every subobject of SuperlativeAmoeba
// SuperlativeMan and Amoeba has 8 bytes to save offset to one base - SuperHero (but for our case
// we have only pointer to vtable - type SuperHero, SuperlativeMan and Amoeba - 8 bytes, SuperlativeAmoeba - 16 bytes).
// For comprahison, pointer to virtual table added one time for last part of type.
class SuperlativeMan : public virtual SuperHero
{
	public:
		// Interface SuperHero definition
		void savePersonFromFire() override;
		void move() override;
		~SuperlativeMan();
};


// Animal interface removed for this task
// but methods makeNoise() still here and have definition in .cpp
// it also can be called (but now this method non virtual)
class Amoeba : public virtual SuperHero
{
	public:
		void makeNoise();
		void savePersonFromFire();
		void move();
		~Amoeba();
};

class SuperlativeAmoeba : public SuperlativeMan, public Amoeba
{
	public:
		~SuperlativeAmoeba();
		// If we not redefine savePersonFromFire and move we will give a compile error
		// , because int is ambigious - compiler do not know what version virtual method call
		// Amoeba::savePersonFromFire() or SuperlativeMan::savePersonFromFire()
		void savePersonFromFire() { 
			// Here we can call SuperHero::savePersonFromFire()
			// or Amoeba version or Superlative version or
			// both version or write new version of virtual method
			Amoeba::savePersonFromFire();
			SuperlativeMan::savePersonFromFire();
		}
		void move() { 
			// Here we can call SuperHero::move()
			// or Amoeba version or Superlative version or
			// both version or write new version of virtual method
			SuperHero::move(); 
		}
};

class TarantulaWoman : public SuperHero
{
	public:
		void makeNoise();
		void savePersonFromFire();
		void move();
		~TarantulaWoman();
};





#endif
