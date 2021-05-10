#ifndef EXPORTER_H
#define EXPORTER_H

#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
#include "ActivityDiagram.hpp"


using namespace std;

class Exporter {
	public:
		Exporter(ActivityDiagram *);
		int exportXML();

	private:
	ActivityDiagram * origem;

};

#endif