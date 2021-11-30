#ifndef CLASSES_H
#define CLASSES_H

#include "interfaces.h"
#include <iostream>

class SuperlativeMan : public SuperHero, public StopTrain, public BendSteel
{
	public:
		// Interface SuperHero definition
		void savePersonFromFire();
		void move();
		~SuperlativeMan();
};

class Amoeba : public Animal, public SuperHero, public ClimbBuilding
{
	public:
		void makeNoise();
		void savePersonFromFire();
		void move();
		~Amoeba();
};


class TarantulaWoman : public Animal, public SuperHero, public StopTrain, public ClimbBuilding
{
	public:
		void makeNoise();
		void savePersonFromFire();
		void move();
		~TarantulaWoman();
};



#endif
