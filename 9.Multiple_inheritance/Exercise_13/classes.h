#ifndef CLASSES_H
#define CLASSES_H

#include "interfaces.h"
#include <iostream>



// We no need to use virtual keyword
// because we use composition and multiple inheritence
// not use in this exercise - we use composition
class SuperlativeMan : public SuperHero
{
	protected:
		// For multiple inheritence
		std::ostream& printObject(std::ostream&) const override;
		// if SuperlativeMan has fields - we should writing methods
		// to get access for inherited classes to print all information
	public:
		void copyAssignSuperlativeManPart(const SuperlativeMan&);
		using SuperHero::getStrengthFactor;
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
class Amoeba : public SuperHero
{
	protected:
		// For multiple inheritence
		std::ostream& printObject(std::ostream&) const override;
		// if SuperlativeMan has fields - we should writing methods
		// to get access for inherited classes to print all information
	public:
		void copyAssignAmoebaPart(const Amoeba&);
		using SuperHero::getStrengthFactor;
		Amoeba& operator=(const Amoeba&);
		Amoeba(int strength = 0);
		void makeNoise();
		void savePersonFromFire() override;
		void move() override;
		void eatFood(const std::string& product, double calories);
                void eatFood(double calories);
		~Amoeba();
};


// Composition has two parts of SuperHero class, but not ambigious
// because every part has implicit name. In composition we no need to use virtual
// keyword in inheritence syntax (every subobjects has their base class and no need to save
// offset to base class). Every time we call constructor of base for every part of compoisition.
// In composition we should pay attention to casting composition to base parts.
// For refs and values it can be make, but if we have some function which signature has pointers
// to base, we cannot cast composition pointer to base (because here not provided polymorphism)
// But we can overload behaviour for casting references and values - so it works.
// So, when we want to use composition we should change function/methods uses pointers
// to base interface/class to use references or make their template functions
class SuperlativeAmoeba
{
	private:
		SuperlativeMan superlative_man;
		Amoeba amoeba;
	public:
		friend std::ostream& operator<<(std::ostream& os, const SuperlativeAmoeba& obj);
		SuperlativeAmoeba& operator=(const SuperlativeAmoeba&);
		SuperlativeAmoeba(int strength = 0);
		~SuperlativeAmoeba();
		void eatFood(const std::string& product, double calories)
		{
			amoeba.eatFood(product, calories);
		}

		void eatFood(double calories)
		{
			amoeba.eatFood(calories);
		}

		void eatFood(int calories)
		{
			superlative_man.eatFood(calories);
		}

		void savePersonFromFire() { 
			// Here we can call SuperHero::savePersonFromFire()
			// or Amoeba version or Superlative version or
			// both version or write new version of virtual method
			amoeba.savePersonFromFire();
			superlative_man.savePersonFromFire();
		}
		void move() { 
			amoeba.move(); // I can not to call move default version(SuperHero version)
		}

		operator SuperlativeMan&(){
			return superlative_man;
		}
		operator Amoeba&()
		{
			return amoeba;
		}
		operator SuperHero&()
		{
			return amoeba;
		}

		operator const SuperlativeMan&() const{
			return superlative_man;
		}
		operator const Amoeba&() const
		{
			return amoeba;
		}
		operator const SuperHero&() const
		{
			return amoeba;
		}
		
		// We can not to write using
		//using SuperHero::move;
		//using SuperHero::savePersonFromFire;
};


// We cannot use global operator type conversion - we can't define
// behaviour of casting pointers of type
// operator SuperHero*(SuperlativeAmoeba*);


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
