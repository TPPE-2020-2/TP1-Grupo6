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
	this->transitions.insert(pair<string, Transition>(name,Transition(name,src,dest)));
}

Transition ActivityDiagram::getTransition(string name) {
	return this->transitions.find(name)->second;
}

string ActivityDiagram::toXML() {
	std::stringstream strStream;

	strStream << "<ActivityDiagram name=\"" << this->name << "\">" << endl;

	strStream << "\t<ActivityDiagramElements>" << endl;
	for(map<string, Element>::iterator it=this->elements.begin(); it != this->elements.end(); ++it)
		strStream << it->second.toXML(2) << endl;

	strStream << "\t</ActivityDiagramElements>" << endl;

	strStream << "\t<ActivityDiagramTransitions>" << endl;
	for(map<string, Transition>::iterator it=this->transitions.begin(); it != this->transitions.end(); ++it)
		strStream << it->second.toXML(2) << endl;

	strStream << "\t</ActivityDiagramTransitions>" << endl;

	strStream << "</ActivityDiagram>";

	return strStream.str();
}

