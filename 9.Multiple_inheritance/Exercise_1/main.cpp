#include <iostream>

class X
{
	public:
	X(int arg = 0) { 
		std::cout << "Called X constructor with arguement "  
			<< arg << " at address " << (void*)this <<std::endl;
	}
	void f() {
		std::cout << "f() function of X object allocated on address: " << (void*)this << std::endl; 
	}

};

class Y : public X
{
	public:
	Y(int arg = 0) : X(arg)
	{
		std::cout << "Called Y constructor with argument "
			<< arg << " at address " << (void*)this << std::endl;
	}
};

class Z : public X
{
	public:
	Z(int arg = 0) : X(arg)
	{
		std::cout << "Called Z costructor with argument "
			<< arg  << " at address " << (void*)this << std::endl;
	} 
};

class A : public Y, public Z
{
	public:
	A(int arg = 0) : Y(arg), Z(arg)
	{
		std::cout << "Called A constructor with argument "
			<< arg << " at address " << (void*)this << std::endl;
	}
};


int main()
{
	using namespace std;
	A A_obj(15);
	cout << "Calling Z::f() of A_obj" << endl;
	A_obj.Z::f();
	cout << "Calling Y::f() of A_obj" << endl;
	A_obj.Y::f();
	return 0;
}
