#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

class AnimalsOrSuperHeroes
{
	public:
	virtual ~AnimalsOrSuperHeroes() {}
};


class SuperlativeMan : public AnimalsOrSuperHeroes
{
	public:
		// Interface SuperHero definition
		void savePersonFromFire();
		void move();
		~SuperlativeMan();
};

class Amoeba : public AnimalsOrSuperHeroes
{
	public:
		void makeNoise();
		void savePersonFromFire();
		void move();
		~Amoeba();
};


class TarantulaWoman : public AnimalsOrSuperHeroes
{
	public:
		void makeNoise();
		void savePersonFromFire();
		void move();
		~TarantulaWoman();
};



#endif
