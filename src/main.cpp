#include <iostream>
#include <string>
#include "ActivityDiagram.hpp"

using namespace std;

int main() {
	string diagramName = "nome do diagrama";
	string startNode = "nome do nodo inicial";
	string activityNode = "nome da atividade";
	string decisionNode = "nome do nodo de decisao";
	string mergeNode = "nome do nodo de fusao";
	string finalNode = "nomde do nodo final";

	ActivityDiagram diagram(diagramName);
	diagram.addElement(startNode,1);
	diagram.addElement(activityNode,2);
	diagram.addElement(decisionNode,3);
	diagram.addElement(mergeNode,4);
	diagram.addElement(finalNode,5);

	diagram.addTransition("nome da transicao",startNode,activityNode,"valor de probabilidade");
	diagram.addTransition("nome da transicao2",activityNode,decisionNode,"valor de probabilidade");

	diagram.exportXML();

	return 0;
}