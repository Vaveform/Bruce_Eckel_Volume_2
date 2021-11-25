#include "food.h"

Food::Food() {}

Food::~Food() {}

Beef::Beef() {}

void Beef::Eat()
{
	std::cout << "Beef is eaten" << std::endl;
}

Fish::Fish() {}

void Fish::Eat()
{
	std::cout << "Fish is eaten" << std::endl;
}

Oats::Oats() {}

void Oats::Eat()
{
	std::cout << "Oats is eaten" << std::endl;
}

Food* GetFromFridge(Foods type)
{
	Food* created_obj = nullptr;
	switch(type)
	{
		case Foods::Beef:
			created_obj = new Beef;
			break;
		case Foods::Fish:
			created_obj = new Fish;
			break;
		case Foods::Oats:
			created_obj = new Oats;
			break;
	}
	return created_obj;
}
