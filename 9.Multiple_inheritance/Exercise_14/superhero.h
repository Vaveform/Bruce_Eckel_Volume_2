#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "PersonLib/person.h"

// If we have pre-compile library class
// without virtual destructor - we can
// change it by using multiple inheritance
class SetterVirtualBaseDestructor
{
	public:
		virtual ~SetterVirtualBaseDestructor(){};
};


class SuperHero : public SetterVirtualBaseDestructor, public Person
{
	private:
		int strengthFactor;
	public:
		SuperHero(const std::string&, short, int);
		virtual void work();
		// SuperHero destructor virtual, because we inherited from SetterVirtualBaseDestructor
		// it's action add virtual word for all destructors in hierarchy. But if we know
		// that pre-compiled Person class has virtual destructor adding additional
		// interface for virtual behaviour of destructor not neccessary
		~SuperHero();
};



#endif
