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
	}
}
	