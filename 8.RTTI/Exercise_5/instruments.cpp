#include "instruments.h"


void Instrument::play(note to_played) const
{
	switch(to_played)
	{
		case note::middleC:
			std::cout << "middleC!" << std::endl;
			break;
		case note::Csharp:
			std::cout << "Csharp!" << std::endl;
			break;
		case note::Cflat:
			std::cout << "Cflat!" << std::endl;
			break;
	}
}

Instrument::~Instrument() {}


void Stringed::changeString(){
	std::cout << "Stringed Instrument was" 
		" changed strings and ready to song!" << std::endl;
}

void Guitar::changeString()
{
	std::cout << "Guitar was" 
		" changed strings and ready to song!" << std::endl;
}

void Guitar::prepareInstrument() {
	changeString();
}

void Violin::changeString()
{
	std::cout << "Violin was" 
		" changed strings and ready to song!" << std::endl;
}

void Violin::prepareInstrument()
{
	changeString();
}

void Wind::clearSpitValve()
{
	std::cout << "Wind Instrument spit valve was" 
		" was cleared and ready to song!" << std::endl;
}

void Tuba::clearSpitValve()
{
	std::cout << "Tuba spit valve was" 
		" was cleared and ready to song!" << std::endl;
}

void Tuba::prepareInstrument()
{
	clearSpitValve();
}


void Flute::clearSpitValve()
{
	std::cout << "Flute spit valve was" 
		" was cleared and ready to song!" << std::endl;
}

void Flute::prepareInstrument()
{
	clearSpitValve();
}
