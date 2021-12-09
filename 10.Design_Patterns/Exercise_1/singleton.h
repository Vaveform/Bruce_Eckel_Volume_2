#ifndef SIGNLETON_H_
#define SINGLETON_H_

#include <iostream>


class Singleton
{
	int i;
	static Singleton s;
	Singleton(int x);
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	public:
	//// Non static methods of manipulation on 
	//// static Singleton s object
	//static Singleton& instance();
	//int getValue() const;
	//void setValue(int);
	
	// If we have only static methods we no need
	// to returning ref to singleton object
	static int getValue() /*const*/ ; // static function member cannot have cv-qualifiers
	static void setValue(int);
};


#endif
