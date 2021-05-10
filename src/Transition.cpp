#include "Transition.hpp"
#include "ActivityDiagram.hpp"

Transition::Transition(string name, string src, string dest, string prob) {
	this->name = name;
	this->src = src;
	this->dest = dest;
	this->prob =  prob;
}

string Transition::getName() {
	return this->name;
}

string Transition::getSrc() {
	return this->src;
}

string Transition::getDest() {
	return this->dest;
}

string Transition::toXML(int level) {
	return ActivityDiagram::toXML(this, level);
}

string Transition::getProb() {
	return this->prob;
}