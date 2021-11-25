#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "shapes.h"

void drawQuad(Shape& sh)
{
	const std::type_info& input_type = typeid(sh);
	if(input_type == typeid(Square) || input_type == typeid(Rectangle))
	{
		sh.draw(std::cout);
	}
	else
	{
		std::cerr << "Warning! In function drawQuad passed" 
			" non Square or non Rectangle ref" << std::endl;
	}
}


int main()
{
	using namespace std;
	const size_t num_of_obj = 10;
	vector<Shape*> shapes(num_of_obj);
	// Filling
	srand(time(0));
	generate(shapes.begin(), shapes.end(), [](){
				Shape* inserted = nullptr;
				switch(rand() % 4)
				{
					case 0:
						inserted = new Triangle(double(rand()) / rand(), 
								double(rand()) / rand(),
								double(rand()) / rand());
						break;
					case 1:
						inserted = new Circle(double(rand()) / rand());
						break;
					case 2:
						inserted = new Square(double(rand()) / rand());
						break;
					case 3:
						inserted = new Rectangle(double(rand()) / rand(), 
								double(rand()) / rand());
						break;
				}
				return inserted;
			});
	//For output
	//copy(shapes.begin(), shapes.end(), ostream_iterator<Shape*, char>(cout));

	cout << "Shape objects in vector: " << endl;
	copy(shapes.begin(), shapes.end(), ostream_iterator<Shape*, char>(cout));
	cout << "Using drawQuad() function for every derefrence pointer:" << endl;
	for_each(shapes.begin(), shapes.end(), [](Shape* sh_p) { drawQuad(*sh_p);} );
	for_each(shapes.begin(), shapes.end(), [](Shape* to_free) { delete to_free; });
	return 0;
}
