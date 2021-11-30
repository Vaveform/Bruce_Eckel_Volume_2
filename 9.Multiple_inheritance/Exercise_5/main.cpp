#include <iostream>
#include <memory>
#include "functions.h"
#include "classes.h"



int main()
{
	using namespace std;
	
	AnimalsOrSuperHeroes* arr[3] = { new SuperlativeMan, 
		new Amoeba, new TarantulaWoman};
	saveFromFirePtr(dynamic_cast<SuperlativeMan*>(arr[0]));
	saveFromFirePtr(dynamic_cast<Amoeba*>(arr[1]));
	saveFromFirePtr(dynamic_cast<TarantulaWoman*>(arr[2]));
	animalSoundPtr(dynamic_cast<Amoeba*>(arr[1]));
	animalSoundPtr(dynamic_cast<TarantulaWoman*>(arr[2]));

	saveFromFireRef(*dynamic_cast<SuperlativeMan*>(arr[0]));
	saveFromFireRef(*dynamic_cast<Amoeba*>(arr[1]));
	saveFromFireRef(*dynamic_cast<TarantulaWoman*>(arr[2]));
	animalSoundRef(*dynamic_cast<Amoeba*>(arr[1]));
	animalSoundRef(*dynamic_cast<TarantulaWoman*>(arr[2]));
	// No problems with delete
	delete arr[0];
	delete arr[1];
	delete arr[2];

	return 0;
}
