#include "Element.hpp"

Element::Element(string name, int type) {
	this->name = name;
	this->type = type;
}

string Element::getName() {
	return this->name;
}

string Element::getType() {
	switch(this->type) {
		case 1:
			return "StartNode";

		case 2:
			return "Activity";

		case 3:
			return "DecisionNode";

		case 4:
			return "MergeNode";

		case 5:
			return "FinalNode";
	}
}

string Element::toXML(int level) {
	std::stringstream strStream;

	for(int c = 0; c < level; c++)
		strStream << '\t';

	strStream << "<" << this->getType() << " name=\"" << this->name << "\" />";

	return strStream.str();
}