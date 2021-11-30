#ifndef CLASSES_H
#define CLASSES_H

#include "interfaces.h"
#include <iostream>

// First version of solution - using smart pointer
class SuperlativeMan : public SuperHero
{
	public:
		// Interface SuperHero definition
		void savePersonFromFire();
		void move();
		~SuperlativeMan();
};

class Amoeba : public Animal, public SuperHero
{
	public:
		void makeNoise();
		void savePersonFromFire();
		void move();
		~Amoeba();
};


class TarantulaWoman : public Animal, public SuperHero
{
	public:
		void makeNoise();
		void savePersonFromFire();
		void move();
		~TarantulaWoman();
};


// Second version of solution - Animal and SuperHero using default (non-virtual)
// destructors, but we can not to call delete for pointer of this types (Animal* and SuperHero*)
// - inherited object do not call their destructors (error: invalid pointer). So we can add interface which has 
// virtual destructor and inherite from him. This action added virtual destructor
// to hierarchy and allow descendants to call their destructors by chain

//class SuperlativeMan : public VirtualDestroyer, public SuperHero/*, public VirtualDestroyer*/
//{
//	public:
//		// Interface SuperHero definition
//		void savePersonFromFire();
//		void move();
//		~SuperlativeMan();
//};
//
//class Amoeba : public VirtualDestroyer, public Animal, public SuperHero/*, public VirtualDestroyer*/
//{
//	public:
//		void makeNoise();
//		void savePersonFromFire();
//		void move();
//		~Amoeba();
//};
//
//class TarantulaWoman : public VirtualDestroyer, public Animal, public SuperHero/*, public VirtualDestroyer*/
//{
//	public:
//		void makeNoise();
//		void savePersonFromFire();
//		void move();
//		~TarantulaWoman();
//};

#endif
