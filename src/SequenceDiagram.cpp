#include "SequenceDiagram.hpp"

// SequenceDiagramXML::SequenceDiagramXML() {}

SequenceDiagramXML::Message::Message(string name){
  this->name = name;
  this->orig = "";
  this->dest = "";
  this->prob = numeric_limits<double>::quiet_NaN();
}

void SequenceDiagramXML::Message::setOrig(SequenceDiagramXML seq, string orig_lifeline){
  vector<string> all_lifelines = seq.getAllLifelines();

  if(find(all_lifelines.begin(),all_lifelines.end(), orig_lifeline) != all_lifelines.end()){
    this->orig = orig_lifeline;
  }
  else{
    throw "MessageFormatException";
  }
}

void SequenceDiagramXML::Message::setDest(SequenceDiagramXML sd, string dest_lifeline){
  std::vector<string> all_lifelines = sd.getAllLifelines();

  if(find(all_lifelines.begin(),all_lifelines.end(), dest_lifeline) != all_lifelines.end()){
    this->dest = dest_lifeline;
  }
  else{
    throw "MessageFormatException";
  }
}

void SequenceDiagramXML::Message::setProb(double prob){
  this->prob = prob;
}


string SequenceDiagramXML::Message::getName(){
  return this->name;
}

string SequenceDiagramXML::Message::getOrig(){
  return this->orig;
}

string SequenceDiagramXML::Message::getDest(){
  return this->dest;
}

double SequenceDiagramXML::Message::getProb(){
  return this->prob;
}

SequenceDiagramXML::Fragment::Fragment(string name){
  this->name = name;
}

void SequenceDiagramXML::Fragment::setSeqDiagram(SequenceDiagramXML sd, string seq_diagram){
  vector<string> all_names = sd.getAllDiagramName();
  
  if(find(all_names.begin(), all_names.end(), seq_diagram) != all_names.end()){
    this->seq_diagram_name = seq_diagram;
  }
  else{
    throw "EmptyOptionalFragment";
  }
}

string SequenceDiagramXML::Fragment::getSeqDiagram(){
  return this->seq_diagram_name;
}

string SequenceDiagramXML::Fragment::getName(){
  return this->name;
}

SequenceDiagramXML::SequenceDiagram::SequenceDiagram(string name) {
  this->name = name;	
}

string SequenceDiagramXML::SequenceDiagram::getName() {
	return this->name;
}

void SequenceDiagramXML::SequenceDiagram::addLifelines(string lifeline){
  this->lifelines.push_back(lifeline);
}

void SequenceDiagramXML::SequenceDiagram::addMessage(SequenceDiagramXML::Message message){
  if(message.getName().empty() || message.getOrig().empty() || message.getDest().empty() || isnan(message.getProb())){
    throw "MessageFormatException";
  }
  else{
    this->messages.push_back(message);
    //cout << "addMessage() this->messages.size() " << this->messages.size() << endl;
  }
}

void SequenceDiagramXML::SequenceDiagram::addFragment(SequenceDiagramXML::Fragment fragment){
  if(fragment.getName().empty() || fragment.getSeqDiagram().empty()){
    throw "EmptyOptionalFragment";
  }
  else{
    this->fragments.push_back(fragment);
  }
}

vector<string> SequenceDiagramXML::SequenceDiagram::getLifelines(){
  return this->lifelines;
}

vector<SequenceDiagramXML::Message> SequenceDiagramXML::SequenceDiagram::getMessages(){
  //cout << "getMessages() this->messages.size() " << this->messages.size() << endl;
  return this->messages;
}

vector<SequenceDiagramXML::Fragment> SequenceDiagramXML::SequenceDiagram::getFragments(){
  return this->fragments;
}

std::vector<string> SequenceDiagramXML::getAllLifelines(){
  std::vector<string> all_lifelines;
  for(SequenceDiagramXML::SequenceDiagram* sd: this->getAllDiagram()){
    for(string& s: sd->getLifelines()){
      all_lifelines.push_back(s);
    }
  }

  return all_lifelines;
}

std::vector<SequenceDiagramXML::Message> SequenceDiagramXML::getAllMessages(){
  std::vector<SequenceDiagramXML::Message> all_message;
  for(SequenceDiagramXML::SequenceDiagram* s: this->getAllDiagram()){
    //cout << s->getName() << endl;
    for(SequenceDiagramXML::Message& m: s->getMessages()){
      all_message.push_back(m);
    }
  }
  return all_message;
}

std::vector<SequenceDiagramXML::Fragment> SequenceDiagramXML::getAllFragments(){
  std::vector<SequenceDiagramXML::Fragment> all_fragment;
  for(SequenceDiagramXML::SequenceDiagram* s: this->getAllDiagram()){
    for(SequenceDiagramXML::Fragment& f: s->getFragments()){
      all_fragment.push_back(f);
    }
  }
  return all_fragment;
}

vector<string> SequenceDiagramXML::getAllDiagramName(){
  vector<string> all_names;
  for(SequenceDiagramXML::SequenceDiagram* s: this->getAllDiagram()){
    all_names.push_back(s->getName());
  }

  return all_names;
}

vector<SequenceDiagramXML::SequenceDiagram*> SequenceDiagramXML::getAllDiagram(){
  return this->seq_diagrams;
}

void SequenceDiagramXML::addDiagram(SequenceDiagramXML::SequenceDiagram* qqn) {
  this->seq_diagrams.push_back(qqn);
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
