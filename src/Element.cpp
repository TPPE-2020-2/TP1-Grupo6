#include "Element.hpp"
#include "ActivityDiagram.hpp"
#include <stdexcept>
#include <iostream>

Element::Element(string name) {
	this->name = name;
}

string Element::getName() {
	return this->name;
}

bool Element::checkSourceAvailability() {
	return true;
}

bool Element::checkDestinationAvailability() {
	return true;
}

string Element::toXML(int level) {
	return ActivityDiagram::toXML(this, level);
}

void Element::addTransition(int type){
	if(!type){ // 0 == source / 1 == destination
		if(this->checkSourceAvailability()){
			this->sourceTransitions++;
		} else {
			throw std::invalid_argument("ActivityDiagramRuleException");
		}
	} else if(this->checkDestinationAvailability()){
		this->destinationTransitions++;
	} else {
		throw std::invalid_argument("ActivityDiagramRuleException");
	}
}

string Element::getType() { return "sample";}
