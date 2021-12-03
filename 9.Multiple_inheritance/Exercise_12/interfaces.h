#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>


class SuperHero
{
	private:
		int strengthFactor;
	protected:
		SuperHero(int stregnth = 0);
		int& getStrengthFactor();
		const int& getStrengthFactor() const;
		virtual std::ostream& printObject(std::ostream&) const; 
		SuperHero& operator=(const SuperHero&);
	public:
		virtual void workout(int calories_nums);
		friend std::ostream& operator<<(std::ostream&, const SuperHero&);
		virtual void savePersonFromFire() = 0;
		virtual void move() = 0;
		virtual ~SuperHero() {std::cout << "SuperHero part destroyed" << std::endl;};
};


class VirtualDestroyer
{
	public:
		virtual ~VirtualDestroyer() { std::cout << "VirtualDestroyer destroyed" << std::endl;};
};

#endif
