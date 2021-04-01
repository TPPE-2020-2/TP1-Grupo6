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
			return "Lifeline";

		case 2:
			return "Optional";
		
		case 3:
			return "Message";

		case 4:
			return "Reply";

		case 5:
			return "Alternative Frame";
	}
}

string Element::toXML() {
	// std::stringstream strStream;

    // for(int c = 0; c < level; c++)
    //     strStream << '\t';

    // strStream << "<Transition name=\"" << this->name << "\" src=\"" << this->src <<"\" dest=\"" << this->dest <<"\" />";

    // return strStream.str();

	return "";
}
	