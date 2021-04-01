#ifndef STARTNODE_H
#define STARTNODE_H

#include "Element.hpp"


using namespace std;

class StartNode : public Element {
	public:
		StartNode(string);
		string getType();

	private:
		bool checkSourceAvailability();
		bool checkDestinationAvailability();
};

#endif