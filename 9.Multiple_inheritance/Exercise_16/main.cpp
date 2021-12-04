#include <iostream>

class Top
{
	public:
		virtual ~Top() {}
};

class Left : virtual public Top
{
	public:
		void f() {
			std::cout << "Left::f()" << std::endl;
		}
};

class Right : virtual public Top
{
	public:
		void f() {
			std::cout << "Right::f()" << std::endl;
		}
};

class Bottom : public Left, public Right
{
	public:
		using Left::f;
};

class VeryBottom : public Bottom
{
	public:
		using Right::f;
};



int main()
{
	using namespace std;
	Bottom b;
	cout << "Calling f() for Bottom: ";
	b.f(); // Calling Left::f()
	VeryBottom vb;
	cout << "Calling f() for VeryBottom: ";
	vb.f(); // Calling Right::f();
	return 0;
}
