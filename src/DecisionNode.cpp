#include "DecisionNode.hpp"

DecisionNode::DecisionNode(string name) : Element(name) {}

string DecisionNode::getType() {
	return "DecisionNode";
} 

bool DecisionNode::checkDestinationAvailability() {
	if(this->destinationTransitions)
		return false;
	return true;
}