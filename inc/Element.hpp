#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

using namespace std;

class Element {
	public:
		Element(string,int);
		string getName();
		string toXML();
		string getType();

	private:
		string name;
		int type;
};

#endif