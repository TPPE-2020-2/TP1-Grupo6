#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <ostream>
#include <sstream>

using namespace std;

class Element {
	public:
		Element(string,string);
		string getName();
		string toXML(int level = 0);
		string getType();

	private:
		string name;
		string type;
};

#endif