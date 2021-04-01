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
			return "Actor";

		case 2:
			return "Object";
		
		case 3:
			return "Message";

		case 4:
			return "Reply";

		case 5:
			return "Alternative Frame";

		case 6:
			return "Lifeline";
	}
}
	