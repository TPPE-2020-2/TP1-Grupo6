#include "Activity.hpp"

Activity::Activity(string name) : Element(name) {
	this->diagram = NULL;
}

string Activity::getType() {
	return "Activity";
}

void Activity::setDiagram(SequenceDiagramXML *diagram) {
	this->diagram = diagram;
}

SequenceDiagramXML* Activity::getDiagram() {
	return this->diagram;
}