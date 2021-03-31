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

void ActivityDiagram::addTransition(string name, string src, string dest) {

}

Transition ActivityDiagram::getTransition(string name) {
	return Transition("my_transition","my_src","my_dest");
}

