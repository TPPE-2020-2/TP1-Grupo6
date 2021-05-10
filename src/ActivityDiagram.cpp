#include "ActivityDiagram.hpp"
#include "StartNode.hpp"
#include "MergeNode.hpp"
#include "FinalNode.hpp"
#include "DecisionNode.hpp"
#include "Activity.hpp"
#include <stdexcept>
#include <iostream>
#include "Exporter.hpp"

bool ActivityDiagram::checkName(string name)
{
	if(this->elements.find(name) == this->elements.end()){
		return true;
	} else {
		return false;
	}
}

ActivityDiagram::ActivityDiagram(string name) {
	this->name = name;
	this->hasStart = false;
	this->hasFinal = false;
}

string ActivityDiagram::getName() {
	return this->name;
}

void ActivityDiagram::addElement(StartNode name) {
  bool check = this->checkName(name.getNodeName());
  if (check) {
    if (this->hasStart)
      throw std::invalid_argument("ActivityDiagramRuleException");

    this->elements.insert(pair<string, Element*>(
        name.getNodeName(), new StartNode(name.getNodeName())));
    this->hasStart = true;
  } else {
    throw std::invalid_argument("ActivityDiagramRuleException");
  }
}

void ActivityDiagram::addElement(string name) {
  bool check = this->checkName(name);
  if (check) {
    this->elements.insert(pair<string, Element*>(name, new Activity(name)));

  } else {
    throw std::invalid_argument("ActivityDiagramRuleException");
  }
}

void ActivityDiagram::addElement(DecisionNode name) {
  bool check = this->checkName(name.getNodeName());
  if (check) {
    this->elements.insert(pair<string, Element*>(
        name.getNodeName(), new DecisionNode(name.getNodeName())));

  } else {
    throw std::invalid_argument("ActivityDiagramRuleException");
  }
}

void ActivityDiagram::addElement(MergeNode name) {
  bool check = this->checkName(name.getNodeName());
  if (check) {
    this->elements.insert(pair<string, Element*>(
        name.getNodeName(), new MergeNode(name.getNodeName())));

  } else {
    throw std::invalid_argument("ActivityDiagramRuleException");
  }
}

void ActivityDiagram::addElement(FinalNode name) {
  bool check = this->checkName(name.getNodeName());
  if (check) {
    this->elements.insert(pair<string, Element*>(
        name.getNodeName(), new FinalNode(name.getNodeName())));
    this->hasFinal = true;

  } else {
    throw std::invalid_argument("ActivityDiagramRuleException");
  }
}

void ActivityDiagram::addElement(string name, int type) {
	bool check = this->checkName(name);
	if(check){
		switch(type){
			case 1:
				this->addElement(StartNode(name));
				break;
			case 2:
				this->addElement(name);
				break;
			case 3:
				this->addElement(DecisionNode(name));
				break;
			case 4:
				this->addElement(MergeNode(name));
				break;
			case 5:
				this->addElement(FinalNode(name));
				break;
		}
	} else {
		throw std::invalid_argument("ActivityDiagramRuleException");
	}
}

void ActivityDiagram::createElement(string name, int type){
		switch(type){
			case 1:
				if(this->hasStart)
					throw std::invalid_argument("ActivityDiagramRuleException");

				this->elements.insert(pair<string, Element*>(name, new StartNode(name)));
				this->hasStart = true;
				break;
			case 2:
				this->elements.insert(pair<string, Element*>(name, new Activity(name)));
				break;
			case 3:
				this->elements.insert(pair<string, Element*>(name, new DecisionNode(name)));
				break;
			case 4:
				this->elements.insert(pair<string, Element*>(name, new MergeNode(name)));
				break;
			case 5:
				this->elements.insert(pair<string, Element*>(name, new FinalNode(name)));
				this->hasFinal = true;
				break;
		}
}

Element* ActivityDiagram::getElement(string name) {
	return this->elements.find(name)->second;
}

void ActivityDiagram::addTransition(string name, string src, string dest, string prob) {
	auto srcE = this->elements.find(src);
	auto destE = this->elements.find(dest);

	if(srcE == this->elements.end() || destE == this->elements.end()) {
		throw std::invalid_argument("ActivityDiagramRuleException");
	}

	srcE->second->addTransition(0);
	destE->second->addTransition(1);
	this->transitions.insert(pair<string, Transition>(name, Transition(name, src, dest,prob)));
}

Transition ActivityDiagram::getTransition(string name) {
	return this->transitions.find(name)->second;
}

void ActivityDiagram::convertElementsToXML(std::stringstream &strStream){
    for(map<string, Element*>::iterator it=this->elements.begin(); it != this->elements.end(); ++it)
        strStream << this->toXML(it->second, 2) << endl;
}

void ActivityDiagram::convertTransitionsToXML(stringstream &strStream){
    for(map<string, Transition>::iterator it=this->transitions.begin(); it != this->transitions.end(); ++it)
        strStream << this->toXML(&(it->second), 2) << endl;
}

string ActivityDiagram::toXML() {
    std::stringstream strStream;

    strStream << "<ActivityDiagram name=\"" << this->name << "\">" << endl;

    strStream << "\t<ActivityDiagramElements>" << endl;

    this->convertElementsToXML(strStream);

    strStream << "\t</ActivityDiagramElements>" << endl;

    strStream << "\t<ActivityDiagramTransitions>" << endl;

    this->convertTransitionsToXML(strStream);

    strStream << "\t</ActivityDiagramTransitions>" << endl;

    strStream << "</ActivityDiagram>";

    return strStream.str();
}

bool ActivityDiagram::checkActivities() {
	for(map<string, Element*>::iterator it=this->elements.begin(); it != this->elements.end(); ++it)
		if(it->second->getType() == "Activity")
			if(((Activity*) it->second)->getDiagram() == NULL)
				return false;
	return true;
}

void ActivityDiagram::addSequence(SequenceDiagramXML* diagram, string name) {
	Element *e = this->getElement(name);
	if(e->getType() != "Activity")
		throw std::invalid_argument("ActivityDiagramRuleException");

	Activity *activity = (Activity*) e;

	if(activity->getDiagram() == NULL)
		activity->setDiagram(diagram);

	else
		throw std::invalid_argument("ActivityDiagramRuleException");
}

int ActivityDiagram::exportXML(){
	Exporter exporter = Exporter(this);
	return exporter.exportXML();
}

string ActivityDiagram::toXML(Element* e, int level) {
  std::stringstream strStream;

  for(int c = 0; c < level; c++)
      strStream << '\t';

  strStream << "<" << e->getType() << " name=\"" << e->getName() << "\" />";

  return strStream.str();
}

string ActivityDiagram::toXML(Transition* t, int level) {
  std::stringstream strStream;

  for(int c = 0; c < level; c++)
      strStream << '\t';

  strStream << "<Transition name=\"" << t->getName() << "\" src=\"" << t->getSrc() <<"\" dest=\"" << t->getDest() <<"\" prob=\"" << t->getProb() <<"\" />";

  return strStream.str();
}
