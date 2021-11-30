#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>

// Plug-in classes for SuperHero
class StopTrain
{
	protected:
		StopTrain() = default;
	public:
		void stopTrain()
		{
			std::cout << "Train stoped" << std::endl;
		}
		virtual ~StopTrain() { std::cout << "StopTrain part destroyed" << std::endl;}
};

class BendSteel
{
	protected:
		BendSteel() = default;
	public:
		void bendSteel(int power_newton)
		{
			std::cout << "Steel was destroyed with power " << power_newton << " H" << std::endl;
		}
		virtual ~BendSteel() { std::cout << "BendSteel part destroyed" << std::endl;}
};

class ClimbBuilding
{
	protected:
		ClimbBuilding() = default;
	public:
		void climbBuilding(int meters)
		{
			std::cout << "Up on " << meters << " meters on building" << std::endl;
		}
		virtual ~ClimbBuilding() { std::cout << "ClimbBuilding part destroyed" << std::endl;}
};


class Animal
{
	public:
		virtual void makeNoise() = 0;
		virtual void move() = 0;
		virtual ~Animal() { std::cout << "Animal part destroyed" << std::endl;};
};

class SuperHero
{
	public:
		virtual void savePersonFromFire() = 0;
		virtual void move() = 0;
		virtual ~SuperHero() {std::cout << "SuperHero part destroyed" << std::endl;};
};



#endif
