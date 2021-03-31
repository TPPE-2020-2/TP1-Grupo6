#include "Transition.hpp"

Transition::Transition(string name, string src, string dest) {
	this->name = name;
	this->src = src;
	this->dest = dest;
}

string Transition::getName() {
	return "my_transition";
}

string Transition::getSrc() {
	return "my_src_element";
}

string Transition::getDest() {
	return "my_dest_element";
}

string Transition::toXML(int level) {

    return "<Transition name = my_transition src = my_src_element dest = my_dest_element />";
}