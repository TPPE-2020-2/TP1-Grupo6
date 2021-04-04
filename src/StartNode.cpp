#include "StartNode.hpp"

StartNode::StartNode(string name) : Element(name) {}

string StartNode::getType() {
	return "StartNode";
}

bool StartNode::checkDestinationAvailability() {
	return false;
}

bool StartNode::checkSourceAvailability() {
	if(this->sourceTransitions == 0) {
		return true;
	} else {
		return false;	
	}
}