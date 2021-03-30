#ifndef ACTIVITY_DIAGRAM_H
#define ACTIVITY_DIAGRAM_H

#include <string>

using namespace std;

class ActivityDiagram {
	public:
		ActivityDiagram(string);
		string getName();
		string toXML();
		int exportXML();

	private:
		string name;
};

#endif