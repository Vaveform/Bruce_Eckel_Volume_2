#include <iostream>
#include <memory>
#include "functions.h"
#include "classes.h"



int main()
{
	using namespace std;
	// First version of solution - we no need to delete - shared_ptr make it
	
	shared_ptr<SuperHero> arr[3] = { make_shared<SuperlativeMan>(), 
		make_shared<Amoeba>(), make_shared<TarantulaWoman>()};
	saveFromFire(arr[0].get());
	saveFromFire(arr[1].get());
	saveFromFire(arr[2].get());
	// second and third elements have Animal Interface (we can use RTTI)
	cout << "Addresses before dynamic_cast:" << endl;
	cout << "arr[0]: " << (void*)arr[0].get() << endl;
	cout << "arr[1]: " << (void*)arr[1].get() << endl;
	cout << "arr[2]: " << (void*)arr[2].get() << endl;
	animalSound(dynamic_cast<Animal*>(arr[1].get()));
	animalSound(dynamic_cast<Animal*>(arr[2].get()));
	cout << "Addresses after dynamic_cast:" << endl;
	cout << "arr[0]: " << (void*)arr[0].get() << endl;
	cout << "arr[1]: " << (void*)arr[1].get() << endl;
	cout << "arr[2]: " << (void*)arr[2].get() << endl;


	// Second version of solution

	//SuperHero* arr[3] = { new SuperlativeMan, new Amoeba, new TarantulaWoman};
	//saveFromFire(arr[0]);
	//saveFromFire(arr[1]);
	//saveFromFire(arr[2]);
	//// second and third elements have Animal Interface (we can use RTTI)
	//cout << "Addresses before dynamic_cast:" << endl;
	//cout << "arr[0]: " << (void*)arr[0] << endl;
	//cout << "arr[1]: " << (void*)arr[1] << endl;
	//cout << "arr[2]: " << (void*)arr[2] << endl;
	//animalSound(dynamic_cast<Animal*>(arr[1]));
	//animalSound(dynamic_cast<Animal*>(arr[2]));
	//cout << "Addresses after dynamic_cast:" << endl;
	//cout << "arr[0]: " << (void*)arr[0] << endl;
	//cout << "arr[1]: " << (void*)arr[1] << endl;
	//cout << "arr[2]: " << (void*)arr[2] << endl;
	//// static_cast cannot to make sidecast in hierarchy 
	////animalSound(static_cast<Animal*>(arr[1]));
	////animalSound(static_cast<Animal*>(arr[2]));
	//
	//// Second version of solution - casting to base interface which has virtual destructor
	//// for right deletion of dynamic allocated objects if we have pointers of SuperHero* or Animal*
	//delete dynamic_cast<VirtualDestroyer*>(arr[0]);
	//delete dynamic_cast<VirtualDestroyer*>(arr[1]);
	//delete dynamic_cast<VirtualDestroyer*>(arr[2]);
	return 0;
}
