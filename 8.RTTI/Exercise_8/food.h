#ifndef FOOD_H
#define FOOD_H

#include <iostream>

enum class Foods{
	Beef = 1,
	Fish = 2,
	Oats = 3
};

class Food{
	protected:
		Food();
	public:
		virtual ~Food() = 0;
		virtual void Eat() = 0;
};

class Beef : public Food
{
		friend Food* GetFromFridge(Foods type);
	protected:
		Beef();
	public:
		virtual void Eat() override;
};

class Fish : public Food
{
		friend Food* GetFromFridge(Foods type);
	protected:
		Fish();
	public:
		virtual void Eat() override;
};

class Oats : public Food
{
		friend Food* GetFromFridge(Foods type);
	protected:
		Oats();
	public:
		virtual void Eat() override;
};


Food* GetFromFridge(Foods type);



#endif
