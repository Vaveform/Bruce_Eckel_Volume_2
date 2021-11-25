#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include "shapes.h"
#include <fstream>

std::vector<Polymorphic::Shape*> GeneratePolymorphic(size_t number_of_objects)
{
	using namespace Polymorphic;
	using namespace std;
	srand(time(0));
	vector<Shape*> poly_shapes(number_of_objects);

	generate(poly_shapes.begin(), poly_shapes.end(), [](){
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
	return poly_shapes;
}


std::vector<RTTI::Shape*> GenerateRTTI(size_t number_of_objects)
{
	using namespace RTTI;
	using namespace std;
	srand(time(0));
	vector<Shape*> no_poly_shapes(number_of_objects);
	generate(no_poly_shapes.begin(), no_poly_shapes.end(), [](){
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
	return no_poly_shapes;
}

void SortingPolymorphicObj(std::vector<Polymorphic::Shape*>& container)
{
	using namespace Polymorphic;
	using namespace std;
	vector<Shape*>::iterator it = partition(container.begin(), container.end(), 
			[](Shape* l){ 
				return typeid(*l).before(typeid(Square));
			});
	sort(it, container.end(), [](Shape* l, Shape* r){
				Square* sq_ptr_l = dynamic_cast<Square*>(l);
				Square* sq_ptr_r = dynamic_cast<Square*>(r);
				if(!sq_ptr_l || !sq_ptr_r) return true; // for safety
				return 4 * sq_ptr_l->getSide() < 4 * sq_ptr_r->getSide();
			});

	sort(container.begin(), it, [](Shape* l, Shape* r){
				Circle* cir_ptr_l = dynamic_cast<Circle*>(l);
				Circle* cir_ptr_r = dynamic_cast<Circle*>(r);
				if(!cir_ptr_l || !cir_ptr_r) return true; // for safety
				return cir_ptr_l->getR() < cir_ptr_r->getR();
			});

}

void SortingRTTIObj(std::vector<RTTI::Shape*>& container)
{
	using namespace RTTI;
	using namespace std;
	vector<Shape*>::iterator it = partition(container.begin(), container.end(), 
			[](Shape* l){ 
				return typeid(*l).before(typeid(Square));
			});
	sort(it, container.end(), [](Shape* l, Shape* r){
				Square* sq_ptr_l = dynamic_cast<Square*>(l);
				Square* sq_ptr_r = dynamic_cast<Square*>(r);
				if(!sq_ptr_l || !sq_ptr_r) return true; // for safety
				return 4 * sq_ptr_l->getSide() < 4 * sq_ptr_r->getSide();
			});

	sort(container.begin(), it, [](Shape* l, Shape* r){
				Circle* cir_ptr_l = dynamic_cast<Circle*>(l);
				Circle* cir_ptr_r = dynamic_cast<Circle*>(r);
				if(!cir_ptr_l || !cir_ptr_r) return true; // for safety
				return cir_ptr_l->getR() < cir_ptr_r->getR();
			});

}


void OutPolymorphicObj(std::vector<Polymorphic::Shape*>& container, std::ostream& os)
{
	using namespace Polymorphic;
	using namespace std;
	copy(container.rbegin(), container.rend(), ostream_iterator<Shape*, char>(os));
}

void OutRTTIObj(std::vector<RTTI::Shape*>& container, std::ostream& os)
{
	using namespace RTTI;
	using namespace std;
	copy(container.rbegin(), container.rend(), ostream_iterator<Shape*, char>(os));
}


int main(int argc, char* argv[])
{

	using namespace std;
	
	ofstream file_output;
	if(argc > 1) {
		file_output.open(argv[1]);
	}
	else cout << "File not selected, using standard cout" << endl;
	ostream& out = (argc > 1 && file_output.is_open() ? file_output : cout);



	size_t number_of_objects = 0;
	cout << "Enter number of objects: ";
	cin >> number_of_objects;
	while(cin && cin.get() != '\n') continue;



	cout << "Polymorphic::Square typeid: " << typeid(Polymorphic::Square).name() << endl;
	cout << "Polymorphic::Circle typeid: " << typeid(Polymorphic::Circle).name() << endl;

	cout << "RTTI::Square typeid: " << typeid(RTTI::Square).name() << endl;
	cout << "RTTI::Circle typeid: " << typeid(RTTI::Circle).name() << endl;



	//Print();
	// Filling vectors
	clock_t start = clock();
	vector<Polymorphic::Shape*> p_vec = GeneratePolymorphic(number_of_objects);
	cout << "Filling vector of polymorphic objects: " << 1000.0 * (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;

	start = clock();
	vector<RTTI::Shape*> rtti_vec = GenerateRTTI(number_of_objects);
	cout << "Filling vector of non-polymorphic objects: " << 1000.0 * (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
	
	

	
	// Sorting Polymorphic Objects
	start = clock();
	SortingPolymorphicObj(p_vec);
	cout << "Sorting vector of polymorphic objects: " << 1000.0 * (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
	
	// Sorting RTTI objects
	start = clock();
	SortingRTTIObj(rtti_vec);
	cout << "Sorting vector of RTTI objects: " << 1000.0 * (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
	
	// output polymorphic objects
	start = clock();
	OutPolymorphicObj(p_vec, out);
	out << "Polymorphic end" << endl;
	cout << "Output vector of polymorphic objects: " << 1000.0 * (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
	

	// output objects
	start = clock();
	OutRTTIObj(rtti_vec, out);
	out << "RTTI end" << endl;
	cout << "Output vector of RTTI objects: " << 1000.0 * (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;

	// Free of every pointer
	for_each(p_vec.begin(), p_vec.end(),[](Polymorphic::Shape* to_free) { delete to_free; });
	for_each(rtti_vec.begin(), rtti_vec.end(),[](RTTI::Shape* to_free) { delete to_free; });
	return 0;
}
