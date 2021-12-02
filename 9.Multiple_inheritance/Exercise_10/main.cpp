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

	super_amoeba->eatFood(5);
	super_amoeba->eatFood("Meat", 13);
	super_amoeba->eatFood("Meat", 13.54);
	super_amoeba->eatFood(12.3);

	delete super_amoeba;
	return 0;
}
