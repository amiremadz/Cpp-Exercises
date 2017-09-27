//============================================================================
// Name        : multiple_inheritance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class MusicalInstrument {
public:
	virtual void play() { cout << "Playing instrument ..." << endl; }
	virtual void reset() { cout << "Resetting instrument ..." << endl; }
public:
	virtual ~MusicalInstrument() {}
};

class Machine {
public:
	virtual void start() { cout << "Starting machine ..." << endl; }
	virtual void reset() { cout << "Resetting machine ..." << endl; }
public:
	virtual ~Machine() {}
};

class Synthesizer: public Machine, public MusicalInstrument{
public:
	~Synthesizer() {}
};

int main() {

	Synthesizer *pSynth = new Synthesizer();

	pSynth->play();
	pSynth->start();

	//pSynth->reset(); // does not work: ambiguous method

	pSynth->Machine::reset();
	pSynth->MusicalInstrument::reset();

	delete pSynth;

	return 0;
}
