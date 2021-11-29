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
	virtual ~X() { std::cout << "X part destroyed" << std::endl; }

};

class Y : virtual public X
{
	public:
	Y(int arg = 0) : X(arg)
	{
		std::cout << "Called Y constructor with argument "
			<< arg << " at address " << (void*)this << std::endl;
	}
	~Y(){ std::cout << "Y part destroyed" << std::endl; }
};

class Z : virtual public X
{
	public:
	Z(int arg = 0) : X(arg)
	{
		std::cout << "Called Z costructor with argument "
			<< arg  << " at address " << (void*)this << std::endl;
	} 
	~Z() { std::cout << "Z part destroyed" << std::endl; }
};

class A : public Y, public Z
{
	public:
	A(int arg = 0) : Y(arg), Z(arg) // arg not pass to X constructor by Y and Z constructors. If we didnot call X(arg) - calls default constructor (if X has default constructor)
	{
		std::cout << "Called A constructor with argument "
			<< arg << " at address " << (void*)this << std::endl;
	}
	~A(){ std::cout << "A part destroyed" << std::endl;}
};


int main()
{
	using namespace std;
	// Part of exercise 1
	//A A_obj(15);
	//cout << "Calling Z::f() of A_obj" << endl;
	//A_obj.Z::f();
	//cout << "Calling Y::f() of A_obj" << endl;
	//A_obj.Y::f();
	// if X non virtual class we can not to do like this
	X* px = new A(15);
	px->f();
	px->f();
	delete px;
	return 0;
}
