#ifndef ACTIVITY_DIAGRAM_H
#define ACTIVITY_DIAGRAM_H

#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
#include <map>
#include "Element.hpp"
#include "Transition.hpp"

using namespace std;

class ActivityDiagram {
	public:
		ActivityDiagram(string);
		string getName();
		void addElement(string, int);
		void addTransition(string, string, string,string);
		string toXML();
		int exportXML();
		Element* getElement(string);
		Transition getTransition(string);
		bool checkName(string);

	private:
		string name;
		map<string, Element*> elements;
		map<string, Transition> transitions;
		bool hasStart;
		bool hasFinal;
};

#endif