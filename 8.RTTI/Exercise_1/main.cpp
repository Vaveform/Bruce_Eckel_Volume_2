#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
using std::cout;
using std::cin;
using std::cerr;
using std::vector;
using std::rand;
using std::time;
using std::srand;
using std::exit;
using std::clock;
using std::endl;
class Base{
	protected:

		static size_t allocated_objects;
	public:
		static size_t UndeletedObjects(){ return allocated_objects; } 
		Base() { allocated_objects++; }
		virtual ~Base() {
			allocated_objects--;
			//cout << "Calling destructor of base class" << endl;
		}
};

class Derived : public Base
{
	public:
		Derived() {allocated_objects++; }
		// Redefined virtual destructor
		~Derived(){
			allocated_objects--;
			//cout << "Calling destructor of derived class" << endl;
		}
};

size_t Base::allocated_objects = 0;


int main()	
{
	size_t number_of_objects;
	cout << "Enter number of objects: ";
	cin >> number_of_objects;
	if(!cin) {
		cerr << "Reading number of objects failed" << endl;
		exit(EXIT_FAILURE);
	}
	while(cin && cin.get() != '\n') continue;

	vector<Base*> objects(number_of_objects);
	
	srand(time(0));

	//std::generate(objects.begin(), objects.end(), [](){
	//			switch(rand() % 2)
	//			{
	//				case 0:
	//					return new Base(); // new Base; - syntax available
	//				case 1:
	//					return new Derived(); // new Derived; - syntax available
	//			}
	//		});


	using Base_It = vector<Base*>::iterator;
	for(Base_It it = objects.begin(); it != objects.end(); ++it)
	{
		switch(rand() % 2)
		{
			case 0:
				*it = new Base(); // new Base; - syntax available
				break;
			case 1:
				*it = new Derived(); // new Derived; - syntax available
				//breek; - i can not write break here because it is last statement
		}
	}
	

	vector<Base*> derived_objects_1;
	vector<Base*> derived_objects_2;
	// using typeid function which returned lvalue of type_info structure
	clock_t start = clock();
	std::copy_if(objects.begin(), objects.end(), std::back_inserter(derived_objects_1), [](Base* b_ptr) {
				return typeid(*b_ptr) == typeid(Derived);
			});


	cout << "Number pointers to Derived: " << derived_objects_1.size() << endl;
	cout << "Using typeid operator: " << 1000.0 * (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;

	derived_objects_1.clear();
	
	start = clock();

	std::copy_if(objects.begin(), objects.end(), std::back_inserter(derived_objects_2), [](Base* b_ptr){
				return dynamic_cast<Derived*>(b_ptr) != nullptr;
			});

	cout << "Number pointers to Derived: " << derived_objects_2.size() << endl;
	cout << "Using dynamic_cast operator: " << 1000.0 * (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;

	derived_objects_2.clear();
	
	cout << "Before free memory number of undeleted objects: " << Base::UndeletedObjects() << endl;

	// Clearing pointers
	std::for_each(objects.begin(), objects.end(), [](Base* bptr) { delete bptr; });


	cout << "Before end of programm number of undeleted objects: " << Base::UndeletedObjects() << endl;
	return 0;
}
