#ifndef SEQUENCE_DIAGRAM_H
#define SEQUENCE_DIAGRAM_H

#include <map>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Element.hpp"

using namespace std;

//#define Message SequenceDiagramXML::Message;
//#define Fragment SequenceDiagramXML::Fragment;
//#define SequenceDiagram SequenceDiagramXML::SequenceDiagram;



class SequenceDiagramXML {
	public:
  // SequenceDiagramXML();

    // Sub-classes
    class Message{
      public:
        // Constructor
        Message(string);

        // Set Functions]
        void setOrig(SequenceDiagramXML,string);
        void setDest(SequenceDiagramXML,string);
        void setProb(double);

        // Get Functions
        string getName();
        string getOrig();
        string getDest();
        double getProb();

      private:
        string name;
        string orig;
        string dest;
        double prob;
    };

    class Fragment{
      public:
        // Constructor
        Fragment(string);

        // Set Functions
        void setSeqDiagram(SequenceDiagramXML,string);

        // Get Functions
        string getSeqDiagram();
        string getName();

      private:
        string name;
        string seq_diagram_name;
    };

    class SequenceDiagram{
      public:
        // Constructor
        SequenceDiagram(string);

        // Set Functions
        void addLifelines(string);
        void addMessage(Message);
        void addFragment(Fragment);

        // Get Functions
        string getName();
        vector<string> getLifelines();
        vector<Message> getMessages();
        vector<Fragment> getFragments();

      private:
        string name;
        vector<string> lifelines;
        vector<Message> messages;
        vector<Fragment> fragments;
    };

    // Get Functions
    vector<string> getAllLifelines();
    vector<Message> getAllMessages();
    vector<Fragment> getAllFragments();
    vector<string> getAllDiagramName();
    vector<SequenceDiagram*> getAllDiagram();
    void addDiagram(SequenceDiagram*);
    int exportXML();

    // XML Functions
		string toXML();
		// int exportXML();

	private:
    vector<SequenceDiagram*> seq_diagrams;
};

#endif
