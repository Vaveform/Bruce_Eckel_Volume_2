#include <iostream>
#include <memory>
#include "functions.h"
#include "classes.h"



int main()
{
	using namespace std;
	SuperlativeAmoeba* super_amoeba = new SuperlativeAmoeba;
	cout << "Sizeof SuperlativeAmoeba: " << sizeof(SuperlativeAmoeba) << endl;
	cout << "Sizeof Amoeba: " << sizeof(Amoeba) << endl;
	cout << "Sizeof SuperlativeMan: " << sizeof(SuperlativeMan) << endl;
	cout << "Sizeof SuperHero: " << sizeof(SuperHero) << endl;
	saveFromFire(super_amoeba);
	super_amoeba->savePersonFromFire();
	super_amoeba->move();
	SuperHero* sup_ptr = new SuperlativeAmoeba();
	delete sup_ptr;
	delete super_amoeba;
	return 0;
}
