#include <iostream>
#include <memory>
#include "functions.h"
#include "classes.h"
#include "interfaces.h"


// User define Concepts - not from interfaces.h
class StopTrain2
{
	protected:
		StopTrain2() = default;
	public:
		void stopTrain(){
			std::cout << "Train stoped by user code" << std::endl;
		}
		virtual ~StopTrain2() {
			std::cout << "StopTrain2 part destroyed" << std::endl;
		}
};

class BendSteel2
{
	protected:
		BendSteel2() = default;
	public:
		void bendSteel(int newtons)
		{
			std::cout << "Steel was banded with " << newtons << " newtons" << std::endl;
		}
		// Additional methods can be called
		void destroySteel(){
			std::cout << "Destroyed steel finally" << std::endl;
		}
		virtual ~BendSteel2()
		{
			std::cout << "BendSteel2 part destroyed" << std::endl;
		}
};

class ClimbBuilding2
{
	protected:
		ClimbBuilding2() = default;
	public:
		void climbBuildingUp(int meters)
		{
			std::cout << "Up on " << meters << " meters on building" << std::endl;	
		}
		// Additional methods can be called
		void climbBuildingDown(int meters)
		{
			std::cout << "Down on " << meters << " meters on building" << std::endl;
		}
		virtual ~ClimbBuilding2()
		{
			std::cout << "ClimbBuilding2 part destroyed" << std::endl;
		}
};


int main()
{
	using namespace std;
	// No flexible variant
	shared_ptr<SuperHero> arr[3] = { make_shared<SuperlativeMan<StopTrain2, BendSteel2>>(), 
		make_shared<Amoeba<ClimbBuilding2>>(), make_shared<TarantulaWoman<StopTrain2, ClimbBuilding2>>()};
	saveFromFirePtr(arr[0].get());
	saveFromFirePtr(arr[1].get());
	saveFromFirePtr(arr[2].get());
	// second and third elements have Animal Interface (we can use RTTI)
	animalSoundPtr(dynamic_cast<Animal*>(arr[1].get()));
	animalSoundPtr(dynamic_cast<Animal*>(arr[2].get()));

	SuperlativeMan<>* man = new SuperlativeMan<>();
	

	cout << "Calling method of SuperlativeMan* man stopTrain(): ";
	man->stopTrain();
	
	cout << "Calling method of arr[0] using RTTI stopTrain(): ";
	// Using RTTI
	dynamic_cast<SuperlativeMan<StopTrain2, BendSteel2>*>(arr[0].get())->stopTrain();
	

	cout << "Calling method of SuperlativeMan* man bendSteel(120): ";
	man->bendSteel(120);

	Amoeba<>* am = new Amoeba<>();
	cout << "Calling method of Amoeba* am climbBuildingUp(12): ";
	am->climbBuildingUp(12);

	TarantulaWoman<>* tw = new TarantulaWoman<>();
	
	cout << "Calling method of TarantulaWoman* tw climbBuildingUp(23): ";
	tw->climbBuildingUp(23);

	cout << "Calling method of TarantulaWoman* tw stopTrain(): ";
	tw->stopTrain();

	delete tw;
	delete am;
	delete man;
	// Example of flexible variant
	// Passing to template StopTrain2 and StopTrain can cause problems: call stopTrain() will be ambigious
	using Flexible_SuperlativeMan = FlexibleVariant::SuperlativeMan<StopTrain2, BendSteel, ClimbBuilding2>;
	Flexible_SuperlativeMan* fl_man = new Flexible_SuperlativeMan();
	fl_man->stopTrain();
	fl_man->bendSteel(123);
	fl_man->climbBuildingUp(15);
	fl_man->climbBuildingDown(12);
	// We can pass this pointer to functions, beacause Superlative inherited from interface (abstract base class)
	// SuperHero. And also we can use dynamic_cast!!!!
	saveFromFirePtr(fl_man);

	using Flexible_TarantulaWoman = FlexibleVariant::TarantulaWoman<StopTrain, BendSteel2, ClimbBuilding>;
	Flexible_TarantulaWoman* fl_ta_wo = new Flexible_TarantulaWoman();
	fl_ta_wo->stopTrain();
	fl_ta_wo->bendSteel(13);
	fl_ta_wo->destroySteel();
	fl_ta_wo->climbBuildingUp(12);

	saveFromFirePtr(fl_ta_wo);
	animalSoundPtr(fl_ta_wo);
	
	delete fl_ta_wo;
	delete fl_man;


	return 0;
}
