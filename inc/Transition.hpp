#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>
#include <ostream>
#include <sstream>

using namespace std;

class Transition {
	public:
		Transition(string,string,string,string);
		string getName();
		string getSrc();
		string getDest();
		string toXML(int level = 0);
		string getProb();

	private:
		string name;
		string src;
		string dest;
		string prob;
};

#endif