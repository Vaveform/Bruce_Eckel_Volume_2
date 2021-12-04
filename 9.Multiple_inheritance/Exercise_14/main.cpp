#include <iostream>


#include "superhero.h"

int main()
{
	// If Person class has not virtual destructor -
	// do not use this pointer which refer to inherited class.
	// Try to cast to type in hierarchy wich have virtual destructor
	// Person* p = new SuperHero("Iron man", 34, 12);
	// delete p // bad, cause problems
	SuperHero* p = new SuperHero("Iron man", 34, 12);
	p->work();
	dynamic_cast<Person*>(p)->work();
	delete p;
	return 0;
}
