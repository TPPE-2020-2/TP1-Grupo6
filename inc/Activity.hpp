#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "Element.hpp"
#include "SequenceDiagram.hpp"

using namespace std;

class Activity : public Element {
	public:
		Activity(string);
		string getType();
		void setDiagram(SequenceDiagramXML *diagram);
		SequenceDiagramXML* getDiagram();

	private:
		SequenceDiagramXML *diagram;
};

#endif