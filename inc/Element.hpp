#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

using namespace std;

class Element {
	public:
		Element(string,string);
		string getName();
		string toXML();
		string getType();

	private:
		string name;
		string type;
};

#endif