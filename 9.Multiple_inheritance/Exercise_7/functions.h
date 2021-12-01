#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream>

// In this exercise this way also working
// because our template classes also inherited
// from Animal or SuperHero
//void animalSound(Animal* a)
//{
//	if(a){
//		a->makeNoise();
//		a->move();
//	}
//}
//
//void saveFromFire(SuperHero* s)
//{
//	if(s)
//	{
//		s->savePersonFromFire();
//		s->move(); 
//	}
//}



// Here we have concept of AnimalBehaviourPtr
// which has some requirements for passed types
// 1. Type should has method with name move
// (has not input parametrs and return void)
// 2. Type should has method with name makeNoise
// (has not input parametrs and return void)
template<typename AnimalBehaviour>
void animalSoundPtr(AnimalBehaviour a)
{
	std::cout << "Called animalSound wtih ptr" << std::endl;
	a->makeNoise();
	a->move();
}

template<typename AnimalBehaviour>
void animalSoundRef(AnimalBehaviour && a) // here using link compression: passed type lvalue - we have reference & , if passed type rvalue - we have rvalue ref
{
	std::cout << "Called animalSound with ref" << std::endl;
	a.makeNoise();
	a.move();
}


// Here we have concept SuperHeroBehaviour
// which has some requirements for passed types
// 1. Type should has method with name move
// (has not input parametrs and return void)
// 2. Type should has method with name savePersonFromFire()
// (has not input parametrs and return void)
template<typename SuperHeroBehaviour>
void saveFromFirePtr(SuperHeroBehaviour h)
{
	std::cout << "Called saveFromFire with ptr" << std::endl;
	h->savePersonFromFire();
	h->move();
}

template<typename SuperHeroBehaviour>
void saveFromFireRef(SuperHeroBehaviour&& h)
{
	std::cout << "Called saveFromFire with ref" << std::endl;
	h.savePersonFromFire();
	h.move();
}

#endif
