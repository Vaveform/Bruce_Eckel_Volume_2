#include "singleton.h"


//Non static version of operations on static Singleton s
//Singleton::Singleton(int x) : i(x)
//{
//	std::cout << "Calling Singleton ctr with parametr: " 
//		<< x
//	       	<< ", address of object: " 
//		<< (void*)this << std::endl;
//}
//
//
//int Singleton::getValue() const
//{
//	std::cout << "Getting i value = " 
//		<< i 
//		<< " from getValue() in object: "
//		<< (void*)this << std::endl;
//	return i;
//}
//
//void Singleton::setValue(int val)
//{
//	std::cout << "Setting value = "
//		<< val << " in object: "
//		<< (void*)this << std::endl;
//	i = val;
//}
//
//Singleton& Singleton::instance()
//{
//	std::cout << "Getting singleton object: "
//		<< &s << std::endl;
//	return s;
//}


Singleton::Singleton(int x) : i(x)
{
	std::cout << "Calling Singleton ctr with parametr: " 
		<< x
	       	<< ", address of object: " 
		<< (void*)this << std::endl;
}


int Singleton::getValue() /*const*/ // static mamber cannot have cv-qualifier
{
	// we have access to member i of Singleton
	// because here we in Singleton namespace
	std::cout << "Getting i value = " 
		<< s.i 
		<< " from getValue() in object: "
		<< &s << std::endl;
	return s.i;
}

void Singleton::setValue(int val)
{
	// we have access to member i of Singleton
	// because here we in Singleton namespace
	std::cout << "Setting value = "
		<< val << " in object: "
		<< &s << std::endl;
	s.i = val;
}

// Now we no need instance() method because all operations on s static
// and no need to getting incapsulated object to calling on this object
// methods (operations)

// Initialization of static non-const variable (using private ctr)
Singleton Singleton::s(42);
