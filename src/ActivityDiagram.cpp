#include "ActivityDiagram.hpp"

ActivityDiagram::ActivityDiagram(string name) {
	this->name = name;
}

string ActivityDiagram::getName() {
	return this->name;
}

void ActivityDiagram::addElement(string name, string type) {
	this->elements.insert(pair<string, Element>(name, Element(name, type)));
}

Element ActivityDiagram::getElement(string name) {
	return this->elements.find(name)->second;
}
