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
	protected:
		// For multiple inheritence
		void copyAssignSuperlativeManPart(const SuperlativeMan&);
		std::ostream& printObject(std::ostream&) const override;
		// if SuperlativeMan has fields - we should writing methods
		// to get access for inherited classes to print all information
	public:
		SuperlativeMan& operator=(const SuperlativeMan&);
		SuperlativeMan(int strength = 0);
		// Interface SuperHero definition
		void savePersonFromFire() override;
		void move() override;
		void eatFood(int calories);
		~SuperlativeMan();
};


// Animal interface removed for this task
// but methods makeNoise() still here and have definition in .cpp
// it also can be called (but now this method non virtual)
class Amoeba : public virtual SuperHero
{
	protected:
		// For multiple inheritence
		void copyAssignAmoebaPart(const Amoeba&);
		std::ostream& printObject(std::ostream&) const override;
		// if SuperlativeMan has fields - we should writing methods
		// to get access for inherited classes to print all information
	public:
		Amoeba& operator=(const Amoeba&);
		Amoeba(int strength = 0);
		void makeNoise();
		void savePersonFromFire() override;
		void move() override;
		void eatFood(const std::string& product, double calories);
                void eatFood(double calories);
		~Amoeba();
};

class SuperlativeAmoeba : public SuperlativeMan, public Amoeba
{
	protected: 
		std::ostream& printObject(std::ostream&) const override;
	public:
		SuperlativeAmoeba& operator=(const SuperlativeAmoeba&);
		SuperlativeAmoeba(int strength = 0);
		~SuperlativeAmoeba();
		// For opportunity calling all parents versions eatFood from SuperlativeAmeba 
		// we should write using declaration for all parents name with name method:
		// Amoeba::eatFood or SuperlativeMan::eatFood - it is simple way
		// Second way - write eatFood versions in current nested 
		// namespace (SuperlativeAmoeba) and inside this methods call concrete versions of
		// parent classes (external namespaces : SuperlativeMan and Amoeba)
		// These two ways works, if we have parent classes with the same name of method
		// but with different signatures. For methods, which have same names 
		// and same signatures working first way only (for example Base class with virtual
		// method inherited by Amoeba and SuperlativeMan in which overriden this method and
		// ABC class inherited from these two classes - in ABC we should write final 
		// overrider which hide all old version and give one version). 
		// It is very important, because when we call methods for obj SuperlativeAmoeba
		// compiler not switch on mechanism of overloading, because all methods in
		// parent classes located in different namespaces. So,compiler 
		// see that SuperlativeAmoeba has two or more members with the same names - it is 
		// ambigious. So, two ways give move names from parent namespaces to current - child
		// namespace

		//void eatFood(const std::string& product, double calories)
		//{
		//	Amoeba::eatFood(product, calories);
		//}

		//void eatFood(double calories)
		//{
		//	Amoeba::eatFood(calories);
		//}

		//void eatFood(int calories)
		//{
		//	SuperlativeMan::eatFood(calories);
		//}

		// First way of exercise 10:
		using Amoeba::eatFood;
		using SuperlativeMan::eatFood;
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
		// We can not to write using
		//using SuperHero::move;
		//using SuperHero::savePersonFromFire;
};

class TarantulaWoman : public SuperHero
{
	public:
		TarantulaWoman(int strength = 0);
		void makeNoise();
		void savePersonFromFire() override;
		void move() override;
		~TarantulaWoman();
};





#endif
