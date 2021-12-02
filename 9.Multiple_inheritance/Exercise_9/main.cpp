#include <iostream>
#include <memory>
#include "functions.h"
#include "classes.h"



int main()
{
	using namespace std;
	SuperlativeAmoeba* super_amoeba = new SuperlativeAmoeba(12);
	cout << "Sizeof SuperlativeAmoeba: " << sizeof(SuperlativeAmoeba) << endl;
	cout << "Sizeof Amoeba: " << sizeof(Amoeba) << endl;
	cout << "Sizeof SuperlativeMan: " << sizeof(SuperlativeMan) << endl;
	cout << "Sizeof SuperHero: " << sizeof(SuperHero) << endl;
	saveFromFire(super_amoeba);
	super_amoeba->savePersonFromFire();
	super_amoeba->move();
	SuperHero* sup_ptr = new SuperlativeAmoeba(25);

	// Also with virtual inheritance passing arguement worked!!!
	SuperHero* amoeba_p = new Amoeba(67);
	SuperHero* superlative_man_p = new SuperlativeMan(125);
	
	saveFromFire(amoeba_p);
	saveFromFire(superlative_man_p);


	delete amoeba_p;
	delete superlative_man_p;
	delete sup_ptr;
	delete super_amoeba;
	return 0;
}
