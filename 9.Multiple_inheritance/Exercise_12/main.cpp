#include <iostream>
#include <memory>
#include "functions.h"
#include "classes.h"



int main()
{
	using namespace std;

	Amoeba* amoeba1 = new Amoeba(123);
	Amoeba* amoeba2 = new Amoeba(34);
	// Will call SuperlativeMan version of workout
	amoeba1->workout(15);

	cout << "*amoeba1: "; 
	cout << *amoeba1;
	cout << "*amoeba2: ";
	cout << *amoeba2;
	cout << "Assign *amoeba1 to *amoeba2: " << endl;
	*amoeba2 = *amoeba1;
	cout << "*amoeba1: "; 
	cout << *amoeba1;
	cout << "*amoeba2: ";
	cout << *amoeba2;
	delete amoeba1;
	delete amoeba2;
	return 0;
}
