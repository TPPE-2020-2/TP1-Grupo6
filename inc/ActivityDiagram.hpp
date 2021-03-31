#ifndef ACTIVITY_DIAGRAM_H
#define ACTIVITY_DIAGRAM_H

#include <string>
#include <ostream>
#include <sstream>
#include <map>
#include "Element.hpp"
#include "Transition.hpp"

using namespace std;

class ActivityDiagram {
	public:
		ActivityDiagram(string);
		string getName();
		void addElement(string, string);
		void addTransition(string, string, string);
		string toXML();
		int exportXML();
		Element getElement(string);
		Transition getTransition(string);

	private:
		string name;
		map<string, Element> elements;
		map<string, Transition> transitions;
};

#endif