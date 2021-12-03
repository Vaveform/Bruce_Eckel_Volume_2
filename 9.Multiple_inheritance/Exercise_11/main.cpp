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

	Amoeba amoe(123);
	Amoeba amoeb(453);
	SuperlativeMan man(43);
	SuperlativeAmoeba ser(345);

	cout << "SuperlativeAmoeba object ser assign to Amoeba object amoe:" << endl;
	amoe = ser;
	cout << "SuperlativeAmoeba ser:" << endl;
	cout << ser;
	cout << "Amoeba amoe:" << endl;
	cout << amoe;
	
	// We can not assign Amoeba object to SuperlativeAmoeba without explicit casting
	cout << "Assignment Amoeba object amoeb to Amoeba object amoe:" << endl;
	amoe = amoeb;
	cout << "Amoeba amoe:" << endl;
	cout << amoe;
	cout << "Amoeba amoeb:" << endl;
	cout << amoeb;

	cout << "SuperlativAmoeba object *super_amoeba assign to SuperlativeMan object man:" << endl;
	man = *super_amoeba;
	cout << "SuperlativeMan man:" << endl;
	cout << man;
	cout << "SuperlativeAmoeba *super_amoeba:" << endl;
	cout << *super_amoeba;

	cout << "SuperlativeAmoeba object *super_amoeba assign to SuperlativeAmoeba object ser:" <<endl;
	ser = *super_amoeba;
	cout << "SuperlativeAmoeba ser:" << endl;
	cout << ser;
	cout << "SuperlativeAmoeba *super_amoeba:" << endl;
	cout << *super_amoeba;

	delete super_amoeba;
	return 0;
}
