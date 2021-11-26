#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H


#include <iostream>

enum note { middleC, Csharp, Cflat};

class Instrument
{
	public:
		void play(note) const;
		virtual ~Instrument();
		// No need to write clearSpitValve():
		// 1. Addition element in base interface (annoying)
		// 2. clearing spit valve refers to the entity Wind instruments
};

class Stringed : public Instrument
{
	public:
	virtual void changeString();
};


class Guitar : public Stringed
{
	public:
	void changeString() override;
};

class Violin : public Stringed
{
	public:
	void changeString() override;
};

class Wind : public Instrument
{
	public:
	virtual void clearSpitValve();
};

class Tuba : public Wind
{
	public:
	void clearSpitValve() override;
};

class Flute : public Wind
{
	public:
	void clearSpitValve() override;
};

#endif
