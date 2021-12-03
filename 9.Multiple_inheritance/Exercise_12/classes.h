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
		void workout(int calories_nums) override;
		// Interface SuperHero definition
		void savePersonFromFire() override;
		void move() override;
		void eatFood(int calories);
		~SuperlativeMan();
};


// In the code below we will get compile error
// when we will try call member workout of Amoeba - 
// we should write final overrider - because we have two overrided methods:
// in SuperlativeMan and Other classes (see also exercise 10) - two methods 
// with the same names on the same level of hierarchy
// - it is overview in exercise 10 - it works for classes on the same
// level hierarchy.
//class Other : public virtual SuperHero
//{
//	public:
//		void savePersonFromFire() {}
//		void move() {}
//		void workout(int a) {}
//};
//
//
//
//// Animal interface removed for this task
//// but methods makeNoise() still here and have definition in .cpp
//// it also can be called (but now this method non virtual)
//class Amoeba : public Other, public SuperlativeMan
//{
//	protected:
//		// For multiple inheritence
//		void copyAssignAmoebaPart(const Amoeba&);
//		std::ostream& printObject(std::ostream&) const override;
//		// if SuperlativeMan has fields - we should writing methods
//		// to get access for inherited classes to print all information
//	public:
//
//		Amoeba& operator=(const Amoeba&);
//		Amoeba(int strength = 0);
//		void makeNoise();
//		void savePersonFromFire() override;
//		void move() override;
//		void eatFood(const std::string& product, double calories);
//                void eatFood(double calories);
//		~Amoeba();
//};


// But when we have classes on different levels of hierarchy
// wins class method on last level: SuperHero has definition of virtual method
// and SuperlativeMan which inherited from SuperHero override his version - so
// with Amoeba will call SuperlativeMan version of workout() method (also for novirtual
// the same behaviour) 

// Animal interface removed for this task
// but methods makeNoise() still here and have definition in .cpp
// it also can be called (but now this method non virtual)
class Amoeba : public virtual SuperHero, public SuperlativeMan
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
