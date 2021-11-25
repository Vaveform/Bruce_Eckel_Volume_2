#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "pets.h"
#include "food.h"

int main()
{
	using namespace std;
	const size_t num_obj = 10;
	srand(time(0));
	vector<Pet*> my_zoo(num_obj);
	generate(my_zoo.begin(), my_zoo.end(), [](){
				Pet* inserted = nullptr;
				switch(rand() % 3){
					case 0:
						inserted = new Dog;
						break;
					case 1:
						inserted = new Cat;
						break;
					case 2:
						inserted = new Horse;
						break;
				}
				return inserted;
			});

	for_each(my_zoo.begin(), my_zoo.end(), [](Pet* for_eat){
				if(typeid(*for_eat) == typeid(Dog))
				{
					dynamic_cast<Dog*>(for_eat)->Eat(dynamic_cast<Beef*>(GetFromFridge(Foods::Beef)));
				}
				if(typeid(*for_eat) == typeid(Cat))
				{
					dynamic_cast<Cat*>(for_eat)->Eat(dynamic_cast<Fish*>(GetFromFridge(Foods::Fish)));
				}
				if(typeid(*for_eat) == typeid(Horse)){
					dynamic_cast<Horse*>(for_eat)->Eat(dynamic_cast<Oats*>(GetFromFridge(Foods::Oats)));
				}
			});


	for_each(my_zoo.begin(), my_zoo.end(), [](Pet* to_free) { delete to_free;});
	return 0;
}
