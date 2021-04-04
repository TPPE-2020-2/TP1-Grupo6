#include "Activity.hpp"

Activity::Activity(string name) : Element(name) {}

string Activity::getType() {
	return "Activity";
}

