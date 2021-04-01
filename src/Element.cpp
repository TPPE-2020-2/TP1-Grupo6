#include "Element.hpp"
#include <stdexcept>

Element::Element(string name) {
	this->name = name;
}

string Element::getName() {
	return this->name;
}

int Element::getTransitions(){
	return this->transitions;
}

string Element::toXML(int level) {
	std::stringstream strStream;

	for(int c = 0; c < level; c++)
		strStream << '\t';

	strStream << "<" << this->getType() << " name=\"" << this->name << "\" />";

	return strStream.str();
}

bool Element::checkSourceAvailability(){
	return true;
}

bool Element::checkDestinationAvailability(){
	return true;
}

void Element::addTransition(int type){
	if(!type){ // 0 == source / 1 == destination
		if(this->checkSourceAvailability()){
			this->transitions++;
		} else {
			throw std::invalid_argument("ActivityDiagramRuleException");
		}
	} else if(this->checkDestinationAvailability()){
		this->transitions++;
	} else {
		throw std::invalid_argument("ActivityDiagramRuleException");
	}
}

string Element::getType() { return "sample";}