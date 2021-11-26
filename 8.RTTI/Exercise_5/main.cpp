#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "instruments.h"


int main()
{
	using namespace std;
	const size_t number_of_instruments = 10;
	srand(time(0));
	vector<shared_ptr<Instrument>> instruments(number_of_instruments);

	generate(instruments.begin(), instruments.end(), []()
			{
				shared_ptr<Instrument> to_insert = nullptr;
				switch(rand() % 4)
				{
					case 0:
						to_insert = make_shared<Guitar>();
						break;
					case 1:
						to_insert = make_shared<Tuba>();
						break;
					case 2:
						to_insert = make_shared<Violin>();
						break;
					case 3:
						to_insert = make_shared<Flute>();
				}
				return to_insert;
			});
	cout << "Objects in instruments: " << endl;
	for_each(instruments.begin(), instruments.end(), [](shared_ptr<Instrument> ptr)
			{
				cout << typeid(*ptr).name() << endl;
			});
	cout << "Calling clearSpitValve() for every ptr: " << endl;
	for_each(instruments.begin(), instruments.end(), [](shared_ptr<Instrument> ptr)
			{
				Wind* wptr = dynamic_cast<Wind*>(ptr.get());
				if(wptr)
					wptr->clearSpitValve();
				else
					cout << "Pointer not Wind*" << endl;
			});
	cout << "Preparing all instruments: " << endl;
	for_each(instruments.begin(), instruments.end(), [](shared_ptr<Instrument> ptr)
			{
				ptr->prepareInstrument();
			});
	return 0;
}
