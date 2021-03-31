#include "Element.hpp"

Element::Element(string name, int type) {
	this->name = name;
	this->type = type;
}

string Element::getName() {
	return this->name;
}

string Element::getType() {
 return "actor";
}
	