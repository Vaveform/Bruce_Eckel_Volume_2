#include "functions.h"

void animalSound(Animal* a)
{
	if(a){
		a->makeNoise();
		a->move();
	}
}

void saveFromFire(SuperHero* s)
{
	if(s)
	{
		s->savePersonFromFire();
		s->move(); 
	}
}
