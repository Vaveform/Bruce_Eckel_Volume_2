#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "interfaces.h"

// In composition difficult to make casting pointers 
// from SuperlativeAmoeba (composite class) to based classes
// But with reference it works
//void saveFromFire(SuperHero*);

// I can solve task only by using template saveFromFire version
// or we can use refernce function
//template<typename SuperHeroConcept>
//void saveFromFire(SuperHeroConcept s)
//{
//	if(s)
//	{
//		s->savePersonFromFire();
//		s->move();
//	}
//}

void saveFromFire(SuperHero& s);


#endif
