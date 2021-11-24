#include <iostream>

#include "require.h"
#include "AutoCounter.h"


// Non virtual destructor
class Base{
		AutoCounter<Base>* c = AutoCounter<Base>::create();
	public:
		//virtual AutoCounter<Base>* GetAutoCounter() { return c; }
		~Base(){
			std::cout << "Deleting " << c << std::endl;
		       	delete c;
		}
};

class Derived : public Base {
		AutoCounter<Derived>* c = AutoCounter<Derived>::create();
	public:
		//virtual AutoCounter<Derived>* GetAutoCounter() { return Derived::c; }
		~Derived() 
		{
			std::cout << "Deleting " << c << std::endl;
			delete c;
		}
};


class TrivialClass{
	AutoCounter<TrivialClass>* ac = AutoCounter<TrivialClass>::create();
	public:
	~TrivialClass() { delete ac; }
};

TrivialClass* CreateTrivial(){
	return new TrivialClass();
}

TrivialClass& RefCreateTrivial(){
	return *(new TrivialClass());
}

TrivialClass ValCreateTrivial()
{
	TrivialClass te;
	return te;
}


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	// Non virtual destructor with pointers to down class
	Base* b = new Derived;
	// If delete calling destructor for derived not calling
	delete b;
	
	// Delete not calling
	TrivialClass* tr = new TrivialClass;
	TrivialClass* p_tr = CreateTrivial();
	TrivialClass& r_tr = RefCreateTrivial();
	TrivialClass v_tr = ValCreateTrivial();

	cout << typeid(*tr).before(typeid(Derived)) << endl;
	return 0;
}
