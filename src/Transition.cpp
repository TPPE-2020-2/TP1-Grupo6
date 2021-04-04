#include "Transition.hpp"

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
	std::stringstream strStream;

    for(int c = 0; c < level; c++)
        strStream << '\t';

    strStream << "<Transition name=\"" << this->name << "\" src=\"" << this->src <<"\" dest=\"" << this->dest <<"\" prob=\"" << this->prob <<"\" />";

    return strStream.str();
}