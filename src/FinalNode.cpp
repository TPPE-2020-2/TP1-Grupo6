#include "FinalNode.hpp"

FinalNode::FinalNode(string name) : Element(name) {}

bool FinalNode::checkSourceAvailability(){
	return false;
}

string FinalNode::getType() {
	return "FinalNode";
}

