#include "functions.h"

//void saveFromFire(SuperHero* s)
//{
//	if(s)
//	{
//		s->savePersonFromFire();
//		s->move(); 
//	}
//}

void saveFromFire(SuperHero& s)
{
	s.savePersonFromFire();
	s.move();
}
