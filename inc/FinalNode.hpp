#ifndef FINALNODE_H
#define FINALNODE_H

#include "Element.hpp"

using namespace std;

class FinalNode : public Element {
	public:
		FinalNode(string);
		string getType();

	protected:
		bool checkSourceAvailability() override;
};

#endif