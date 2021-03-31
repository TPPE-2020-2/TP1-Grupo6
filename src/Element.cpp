#include "Element.hpp"

Element::Element(string name, string type) {
	this->name = name;
	this->type = type;
}

string Element::getName() {
	return "ex_element";
}

string Element::getType() {
 return "ex_type";
}
	