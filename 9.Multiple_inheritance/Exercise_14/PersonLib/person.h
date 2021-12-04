#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
	private:
		std::string name;
		short age;
	public:
		Person(const std::string&, short);
		void work();
		// For right working.
		// virtual ~Person();
		// Bad class if non-virtual
		~Person();
};

#endif
