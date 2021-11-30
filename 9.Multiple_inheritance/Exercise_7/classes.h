#ifndef CLASSES_H
#define CLASSES_H

#include "interfaces.h"
#include <iostream>

// We can use variadic template two get opportuinities
// to users to generate class with variadic number of plugin classes


namespace FlexibleVariant{
	template<typename... Concepts>
	class SuperlativeMan : public SuperHero, public Concepts...
	{
		public:
			void savePersonFromFire()
			{
				std::cout << "SuperlativeMan saved a person from fire" << std::endl;
			}
			void move()
			{
				std::cout << "SuperlativeMan moved" << std::endl;
			}
			~SuperlativeMan()
			{
				std::cout << "SuperlativeMan destroyed" << std::endl;
			}
	};


	template<typename... Concepts>
	class Amoeba : public Animal, public SuperHero, public Concepts...
	{
		public:
			void makeNoise()
			{
				std::cout << "Amoeba made noise: aaaaa" << std::endl;
			}
			void savePersonFromFire()
			{
				std::cout << "Amoeba saved a person from fire" << std::endl;
			}
			void move()
			{
				std::cout << "Amoeba moved" << std::endl;
			}
			~Amoeba()
			{
				std::cout << "Amoeba destroyed" << std::endl;
			}
	};

	template<typename... Concepts>
	class TarantulaWoman : public Animal, public SuperHero, public Concepts...
	{
		public:
			void makeNoise()
			{
				std::cout << "TarantulaWoman made noise: shshsh" << std::endl;
			}
			void savePersonFromFire()
			{
				std::cout << "TarantulaWoman saved a person from fire" << std::endl;
			}
			void move()
			{
				std::cout << "TarantulaWoman moved" << std::endl;
			}
			~TarantulaWoman()
			{
				std::cout << "TarantulaWoman destroyed" << std::endl;
			}
	};
}



// Not flexible for users solution
template<typename StopTrainConcept = StopTrain, typename BendSteelConcept = BendSteel>
class SuperlativeMan : public SuperHero, public StopTrainConcept, public BendSteelConcept
{
	public:
		void savePersonFromFire()
		{
			std::cout << "SuperlativeMan saved a person from fire" << std::endl;
		}
		void move()
		{
			std::cout << "SuperlativeMan moved" << std::endl;
		}
		~SuperlativeMan()
		{
			std::cout << "SuperlativeMan destroyed" << std::endl;
		}
};


template<typename ClimbBuildingConcept = ClimbBuilding>
class Amoeba : public Animal, public SuperHero, public ClimbBuildingConcept
{
	public:
		void makeNoise()
		{
			std::cout << "Amoeba made noise: aaaaa" << std::endl;
		}
		void savePersonFromFire()
		{
			std::cout << "Amoeba saved a person from fire" << std::endl;
		}
		void move()
		{
			std::cout << "Amoeba moved" << std::endl;
		}
		~Amoeba()
		{
			std::cout << "Amoeba destroyed" << std::endl;
		}
};

template<typename StopTrainConcept = StopTrain, typename ClimbBuildingConcept = ClimbBuilding>
class TarantulaWoman : public Animal, public SuperHero, public StopTrainConcept, public ClimbBuildingConcept
{
	public:
		void makeNoise()
		{
			std::cout << "TarantulaWoman made noise: shshsh" << std::endl;
		}
		void savePersonFromFire()
		{
			std::cout << "TarantulaWoman saved a person from fire" << std::endl;
		}
		void move()
		{
			std::cout << "TarantulaWoman moved" << std::endl;
		}
		~TarantulaWoman()
		{
			std::cout << "TarantulaWoman destroyed" << std::endl;
		}
};



#endif
