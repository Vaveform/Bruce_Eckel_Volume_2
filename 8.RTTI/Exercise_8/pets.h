#ifndef PETS_H
#define PETS_H

#include <string>
#include <iostream>
#include "food.h"



class Pet
{
	private:
		std::string name;
		unsigned short age;
	protected:
		const std::string& Name() const;
		unsigned short Age() const;
	public:
		Pet();
		Pet(const char* _name, unsigned short _age);
		Pet(const std::string& _name, unsigned short _age);
		virtual void PetInfo() const = 0;
		virtual ~Pet() = 0;
};


class Dog : public Pet
{
	public:
		Dog();
		Dog(const char* _name, unsigned short _age);
		Dog(const std::string& _name, unsigned short _age);
		virtual void PetInfo() const override;
	       	void Bark() const;
		void Eat(Beef*);
};

class Cat : public Pet
{
	public:
		Cat();
		Cat(const char* _name, unsigned short _age);
		Cat(const std::string& _name, unsigned short _age);
		virtual void PetInfo() const override;
		void Meow() const;
		void Eat(Fish*);
};

class Horse : public Pet
{
	public:
		Horse();
		Horse(const char* _name, unsigned short _age);
		Horse(const std::string& _name, unsigned short _age);
		virtual void PetInfo() const override;
		void Igogo() const;
		void Eat(Oats*);
};


#endif
