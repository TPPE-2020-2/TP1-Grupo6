#ifndef STARTNODE_H
#define STARTNODE_H

#include "Element.hpp"

using namespace std;

class StartNode : public Element {
	public:
		StartNode(string);
		string getType();

	protected:
		bool checkSourceAvailability() override;
		bool checkDestinationAvailability() override;
};

#endif