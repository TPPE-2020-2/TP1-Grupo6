#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>

using namespace std;

class Transition {
	public:
		Transition(string,string,string);
		string getName();
		string getSrc();
		string getDest();
		string toXML(int);

	private:
		string name;
		string src;
		string dest;
};

#endif