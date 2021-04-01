#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <ostream>
#include <sstream>

using namespace std;

class Element {
	public:
		Element(string);
		string getName();
		string toXML(int level = 0);
		virtual string getType();
		bool checkSourceAvailability();
		bool checkDestinationAvailability();
		void addTransition(int);
		int getTransitions();
	protected:
		int transitions;
		string name;
};

#endif