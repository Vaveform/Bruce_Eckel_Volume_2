#include <iostream>
#include <memory>
#include "functions.h"
#include "classes.h"



int main()
{
	using namespace std;
	
	SuperlativeMan* first_hero = new SuperlativeMan();
	Amoeba* second_hero = new Amoeba();
	TarantulaWoman* third_hero = new TarantulaWoman();

	saveFromFirePtr(first_hero);
	saveFromFirePtr(second_hero);
	saveFromFirePtr(third_hero);
	animalSoundPtr(second_hero);
	animalSoundPtr(third_hero);

	saveFromFireRef(*first_hero);
	saveFromFireRef(*second_hero);
	saveFromFireRef(*third_hero);
	animalSoundRef(*second_hero);
	animalSoundRef(*third_hero);
	// No problems with delete
	delete first_hero;
	delete second_hero;
	delete third_hero;

	return 0;
}
