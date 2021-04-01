#ifndef SEQUENCE_DIAGRAM_H
#define SEQUENCE_DIAGRAM_H

#include <map>
#include <string>
#include <vector>
#include "Element.hpp"

using namespace std;

class SequenceDiagram {
	public:
		SequenceDiagram(string);
		string getName();
		// string toXML();
		// int exportXML();

	private:
	map<string, Element> lifelines;
	map<string, Element> fragments;
	map<string, Element> optionals;
	map<string, Element> messages;
	map<string, Element> replies;
	vector<map<string, Element>> sequenceDiarams;
};

#endif