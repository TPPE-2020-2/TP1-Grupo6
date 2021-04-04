#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "Element.hpp"

using namespace std;

class Activity : public Element {
	public:
		Activity(string);
		string getType();
};

#endif