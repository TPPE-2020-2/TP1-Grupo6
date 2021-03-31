#include "Element.hpp"

Element::Element(string name, string type) {
	this->name = name;
	this->type = type;
}

string Element::getName() {
	return this->name;
}

string Element::getType() {
	return this->type;
}

string Element::toXML(int level) {
	std::stringstream strStream;

	for(int c = 0; c < level; c++)
		strStream << '\t';

	strStream << "<" << this->type << " name=\"" << this->name << "\" />";

	return strStream.str();
}