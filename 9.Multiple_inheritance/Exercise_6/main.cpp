#include <iostream>
#include <memory>
#include "functions.h"
#include "classes.h"



int main()
{
	using namespace std;
	
	shared_ptr<SuperHero> arr[3] = { make_shared<SuperlativeMan>(), 
		make_shared<Amoeba>(), make_shared<TarantulaWoman>()};
	saveFromFire(arr[0].get());
	saveFromFire(arr[1].get());
	saveFromFire(arr[2].get());
	// second and third elements have Animal Interface (we can use RTTI)
	animalSound(dynamic_cast<Animal*>(arr[1].get()));
	animalSound(dynamic_cast<Animal*>(arr[2].get()));

	SuperlativeMan* man = new SuperlativeMan();
	

	cout << "Calling method of SuperlativeMan* man stopTrain(): ";
	man->stopTrain();
	
	cout << "Calling method of arr[0] using RTTI stopTrain(): ";
	// Using RTTI
	dynamic_cast<SuperlativeMan*>(arr[0].get())->stopTrain();
	

	cout << "Calling method of SuperlativeMan* man bendSteel(120): ";
	man->bendSteel(120);

	Amoeba* am = new Amoeba();
	cout << "Calling method of Amoeba* am climbBuilding(12): ";
	am->climbBuilding(12);

	TarantulaWoman* tw = new TarantulaWoman();
	
	cout << "Calling method of TarantulaWoman* tw climbBuilding(23): ";
	tw->climbBuilding(23);

	cout << "Calling method of TarantulaWoman* tw stopTrain(): ";
	tw->stopTrain();

	delete tw;
	delete am;
	delete man;
	return 0;
}
