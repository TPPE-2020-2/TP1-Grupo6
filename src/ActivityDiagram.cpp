#include "ActivityDiagram.hpp"

ActivityDiagram::ActivityDiagram(string name) {
	this->name = name;
}

string ActivityDiagram::getName() {
	return this->name;
}