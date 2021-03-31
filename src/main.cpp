#include <iostream>
#include <string>
#include "ActivityDiagram.hpp"

using namespace std;

int main() {
	int choice;
	string diagramName;

	cout << "Insert the diagram name: ";
	cin >> diagramName;

	ActivityDiagram diagram(diagramName);

	while(1) {
		cout << "Choose the desired action:" << endl;
		cout << "\t1. Add element" << endl;
		cout << "\t2. Add transition" << endl;
		cout << "\t3. Export diagram" << endl;

		cin >> choice;

		switch(choice) {
			case 1: {
				string name;
				int type;

				cout << "Insert the element name: ";
				cin >> name;
				cout << "Choose the element type: " << endl;
				cout << "\t1. StartNode" << endl;
				cout << "\t2. Activity" << endl;
				cout << "\t3. DecisionNode" << endl;
				cout << "\t4. MergeNode" << endl;
				cout << "\t5. FinalNode" << endl;
				cin >> type;

				diagram.addElement(name, type);
				break;
			}

			case 2: {
				string name, src, dest;

				cout << "Insert the transition name: ";
				cin >> name;
				cout << "Insert the transition source: ";
				cin >> src;
				cout << "Insert the transition destination: ";
				cin >> dest;

				diagram.addTransition(name, src, dest);
				break;
			}

			case 3:
				diagram.exportXML();

			default:
				break;
		}
	}

	return 0;
}