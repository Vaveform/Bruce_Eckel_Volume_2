#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include "shapes.h"

int main()
{
	using namespace std;

	const size_t number_of_objects = 10;
	srand(time(0));
	vector<Shape*> shapes(number_of_objects);

	generate(shapes.begin(), shapes.end(), [](){
				Shape* inserted = nullptr;
				switch(rand() % 2)
				{
					case 0: 
						inserted = new Circle(double(rand())/rand());
						break;
					case 1:
						inserted = new Square(double(rand())/rand());
						break;
				}
				return inserted;
			});


	cout << "Square typeid: " << typeid(Square).name() << endl;
	cout << "Circle typeid: " << typeid(Circle).name() << endl;

	//copy(shapes.begin(), shapes.end() ,ostream_iterator<Shape*, char>(cout));
	// Free of the vector pointers, because destructor of vector cannot to free template pointers
	vector<Shape*>::iterator  = partition(shapes.begin(), shapes.end(), 
			[](Shape* l){ 
				return typeid(*l).before(typeid(Square));
			});
	sort(second_it, shapes.end(), [](Shape* l, Shape* r){
				Square* sq_ptr_l = dynamic_cast<Square*>(l);
				Square* sq_ptr_r = dynamic_cast<Square*>(r);
				if(!sq_ptr_l || !sq_ptr_r) return true; // for safety
				return 4 * sq_ptr_l->getSide() < 4 * sq_ptr_r->getSide();
			});

	sort(shapes.begin(), second_it, [](Shape* l, Shape* r){
				Circle* cir_ptr_l = dynamic_cast<Circle*>(l);
				Circle* cir_ptr_r = dynamic_cast<Circle*>(r);
				if(!cir_ptr_l || !cir_ptr_r) return true; // for safety
				return cir_ptr_l->getR() < cir_ptr_r->getR();
			});


	copy(shapes.rbegin(), shapes.rend() ,ostream_iterator<Shape*, char>(cout));

	// Free of the vector pointers, because destructor of vector cannot to free template pointers
	for_each(shapes.begin(), shapes.end(),[](Shape* to_free) { delete to_free; });
	return 0;
}
