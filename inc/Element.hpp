#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <ostream>
#include <sstream>
#include <iostream>

using namespace std;

class Element {
	public:
		Element(string);
		string getName();
		string toXML(int level = 0);
		virtual string getType();
		void addTransition(int);


	protected:
		virtual bool checkSourceAvailability();
		virtual bool checkDestinationAvailability();

		int sourceTransitions, destinationTransitions;
		string name;
};

#endif
