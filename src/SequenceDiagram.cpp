#include "SequenceDiagram.hpp"

SequenceDiagram::SequenceDiagram(string name) {
	
}

string SequenceDiagram::getName() {
	return "my_diagram";
}

// string SequenceDiagram::toXML() {
//     std::stringstream strStream;

//     strStream << "<ActivityDiagram name=\"" << this->name << "\">" << endl;

//     strStream << "\t<ActivityDiagramElements>" << endl;
//     for(map<string, Element>::iterator it=this->elements.begin(); it != this->elements.end(); ++it)
//         strStream << it->second.toXML(2) << endl;

//     strStream << "\t</ActivityDiagramElements>" << endl;

//     strStream << "\t<ActivityDiagramTransitions>" << endl;
//     for(map<string, Transition>::iterator it=this->transitions.begin(); it != this->transitions.end(); ++it)
//         strStream << it->second.toXML(2) << endl;

//     strStream << "\t</ActivityDiagramTransitions>" << endl;

//     strStream << "</ActivityDiagram>";

//     return strStream.str();
// }

// int SequenceDiagram::exportXML(){
// 	std::ofstream out;
// 	auto xml = this->toXML();
// 	out.open("ActivityDiagram.xml");
// 	out << xml;
// 	out.close();
// 	return 1;
// }