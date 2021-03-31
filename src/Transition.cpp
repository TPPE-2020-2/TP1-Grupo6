#include "Transition.hpp"

Transition::Transition(string name, string src, string dest) {
	this->name = name;
	this->src = src;
	this->dest = dest;
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

    return "<Transition name = my_transition src = my_src_element dest = my_dest_element />";
}