#include <iostream>
#include "singleton.h"

int main()
{
	using namespace std;
	//Singleton& instance = Singleton::instance();
	//int returned =  instance.getValue();
	//Singleton& instance2 = Singleton::instance();
	//instance2.setValue(1555);
	//returned = instance.getValue();
	//returned = instance2.getValue();
	
	// All methods of manipulation static
	int returned = Singleton::getValue();
	Singleton::setValue(1555);
	returned = Singleton::getValue();
	returned = Singleton::getValue();
	// You can see - we no need to apeal to
	// concrete reference or object to geting or setting data
	// static methods encapsulate this
	return 0;
}
