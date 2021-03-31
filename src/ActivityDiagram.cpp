#include "ActivityDiagram.hpp"

ActivityDiagram::ActivityDiagram(string name) {
	this->name = name;
}

string ActivityDiagram::getName() {
	return this->name;
}

void ActivityDiagram::addElement(string name, string type) {
	return;
}

Element ActivityDiagram::getElement(string name) {
	return Element("start", "StartNode");
}
