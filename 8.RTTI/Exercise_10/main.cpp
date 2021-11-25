#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <memory>

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

std::ostream& operator<< (std::ostream& os, std::shared_ptr<Shape> obj)
{
	return os << *obj;
}

int main()
{
	using namespace std;
	const size_t num_of_obj = 10;
	vector<shared_ptr<Shape>> shapes(num_of_obj);
	// Filling
	srand(time(0));
	generate(shapes.begin(), shapes.end(), [](){
				shared_ptr<Shape> inserted = nullptr;
				switch(rand() % 4)
				{
					case 0:
						inserted = make_shared<Triangle>(double(rand()) / rand(), 
								double(rand()) / rand(),
								double(rand()) / rand());
						break;
					case 1:
						inserted = make_shared<Circle>(double(rand()) / rand());
						break;
					case 2:
						inserted = make_shared<Square>(double(rand()) / rand());
						break;
					case 3:
						inserted = make_shared<Rectangle>(double(rand()) / rand(), 
								double(rand()) / rand());
						break;
				}
				return inserted;
			});
	//For output
	//copy(shapes.begin(), shapes.end(), ostream_iterator<Shape*, char>(cout));

	cout << "Shape objects in vector: " << endl;
	copy(shapes.begin(), shapes.end(), ostream_iterator<shared_ptr<Shape>, char>(cout));
	sort(shapes.begin(), shapes.end(), [](shared_ptr<Shape> left_ptr, shared_ptr<Shape> right_ptr){
				return typeid(*left_ptr).before(typeid(*right_ptr));
			});
	cout << "Shape objects after sorting: " << endl;
	copy(shapes.begin(), shapes.end(), ostream_iterator<shared_ptr<Shape>, char>(cout));
	return 0;
}
