#include "StartNode.hpp"


StartNode::StartNode(string name) : Element(name) {}

bool StartNode::checkSourceAvailability(){
	if(this->transitions == 0){
		return true;
	} else {
		return false;	
	}
}

bool StartNode::checkDestinationAvailability(){
	return false;
}

string StartNode::getType() {
	return "StartNode";
}