#include "../inc/SequenceDiagram.hpp"
#include <vector>
#include <gtest/gtest.h>

// TEST(SequenceDiagramCreationTest, DiagramCreation) {
// 	SequenceDiagramXML diagram();

// 	EXPECT_EQ("my_diagram", diagram.getName());
// }

TEST(MessageCreationTest, MessageCreation) {
  SequenceDiagramXML diagram;
	SequenceDiagramXML::Message message("my_message");
  SequenceDiagramXML::SequenceDiagram* sequenceDiagram = new SequenceDiagramXML::SequenceDiagram("my_sequenceDiagram");
  sequenceDiagram->addLifelines("lifeline");
  diagram.addDiagram(sequenceDiagram);
	message.setOrig(diagram, "lifeline");
  message.setDest(diagram, "lifeline");
  message.setProb(1.0);

  EXPECT_EQ("lifeline", message.getOrig());
  EXPECT_EQ("lifeline", message.getDest());
  EXPECT_EQ(1.0, message.getProb());
	EXPECT_EQ("my_message", message.getName());
}

TEST(FragmentCreationTest, FragmentCreation) {
  SequenceDiagramXML diagram;
  SequenceDiagramXML::SequenceDiagram *sequenceDiagram = new SequenceDiagramXML::SequenceDiagram("my_sequenceDiagram");
  SequenceDiagramXML::Fragment fragment("my_fragment");
  diagram.addDiagram(sequenceDiagram);
  fragment.setSeqDiagram(diagram, "my_sequenceDiagram");

  EXPECT_EQ("my_fragment", fragment.getName());
  EXPECT_EQ("my_sequenceDiagram", fragment.getSeqDiagram());
}

TEST(SequenceDiagramCreationTest, SequenceDiagramCreation) {
  SequenceDiagramXML diagram;
  SequenceDiagramXML::SequenceDiagram* sequenceDiagram = new SequenceDiagramXML::SequenceDiagram("my_sequenceDiagram");
  sequenceDiagram->addLifelines("lifeline");
  diagram.addDiagram(sequenceDiagram);
  SequenceDiagramXML::Message *message = new SequenceDiagramXML::Message("my_message");
  message->setOrig(diagram, "lifeline");
  message->setDest(diagram, "lifeline");
  message->setProb(1.0);
  SequenceDiagramXML::Fragment fragment("my_fragment");
  fragment.setSeqDiagram(diagram, "my_sequenceDiagram");
  
  sequenceDiagram->addMessage(*message);
  sequenceDiagram->addFragment(fragment);

  std::vector<string> lifelinesMock;
  lifelinesMock.push_back("lifeline");

  for(int i=0; i<lifelinesMock.size(); i++) {
    EXPECT_EQ(lifelinesMock[i], sequenceDiagram->getLifelines()[i]);
  }


  std::vector<SequenceDiagramXML::Message> messagesMock;
  messagesMock.push_back(*message);

  for(int i=0; i<messagesMock.size(); i++) {
    EXPECT_EQ(messagesMock[i].getName(), sequenceDiagram->getMessages()[i].getName());
  }


  std::vector<SequenceDiagramXML::Fragment> fragmensMock;
  fragmensMock.push_back(fragment);

  for(int i=0; i<fragmensMock.size(); i++) {
    EXPECT_EQ(fragmensMock[i].getName(), sequenceDiagram->getFragments()[i].getName());
  }
}

TEST(SequenceDiagramXMLCreationTest, getAllLifelinesTest){
  SequenceDiagramXML diagram;
  SequenceDiagramXML::SequenceDiagram *seq_diagram = new SequenceDiagramXML::SequenceDiagram("my_seq_diagram");
  seq_diagram->addLifelines("ll");
  seq_diagram->addLifelines("ll.1");

  SequenceDiagramXML::SequenceDiagram *seq_diagram2 = new SequenceDiagramXML::SequenceDiagram("my_seq_diagram2");
  seq_diagram->addLifelines("ll2");
  seq_diagram->addLifelines("ll2.1");

  diagram.addDiagram(seq_diagram);
  diagram.addDiagram(seq_diagram2);

  vector<string> mock_response = {"ll", "ll.1", "ll2", "ll2.1"};
  vector<string> response = diagram.getAllLifelines();

  
  
  for(int i = 0; i < mock_response.size(); i++){
    EXPECT_EQ(mock_response[i], response[i]);
  }
}

TEST(SequenceDiagramXMLCreationTest, SequenceDiagramXMLCreationTest1) {
	SequenceDiagramXML* diagram = new SequenceDiagramXML();
  SequenceDiagramXML::Message*message = new SequenceDiagramXML::Message("my_message");
  SequenceDiagramXML::SequenceDiagram* sequenceDiagram = new SequenceDiagramXML::SequenceDiagram("my_sequenceDiagram");
  sequenceDiagram->addLifelines("lifeline");
  diagram->addDiagram(sequenceDiagram);
  //cout << "\n\n\nUHJIRFDESIHUJRFDEHIUJRFGD\n\n\n";
  message->setOrig(*diagram, "lifeline");
  message->setDest(*diagram, "lifeline");
  message->setProb(1.0);
  SequenceDiagramXML::Fragment* fragment = new SequenceDiagramXML::Fragment("my_fragment");
  //cout << "\n\n\nUHJIRFDESIHUJRFDEHIUJRFGD\n\n\n";
  fragment->setSeqDiagram(*diagram, "my_sequenceDiagram");
//  sequenceDiagram.getMessages();
  sequenceDiagram->addMessage(*message);
  sequenceDiagram->addFragment(*fragment);

  SequenceDiagramXML::SequenceDiagram* sequenceDiagram2 = new SequenceDiagramXML::SequenceDiagram("my_sequenceDiagram2");
  sequenceDiagram2->addLifelines("lifeline2");
  diagram->addDiagram(sequenceDiagram2);
  vector<string> hehe = diagram->getAllLifelines();
  
  // Criando mensagem 2
  SequenceDiagramXML::Message* message2 = new SequenceDiagramXML::Message("my_message2");
  message2->setOrig(*diagram, "lifeline2");
  message2->setDest(*diagram, "lifeline2");
  message2->setProb(45.0);

  //Criando Fragmento 2
  SequenceDiagramXML::Fragment* fragment2 = new SequenceDiagramXML::Fragment("my_fragment2");
  fragment2->setSeqDiagram(*diagram, "my_sequenceDiagram2");

  // Adicionando mansagem e fragmento ao diagrama
  sequenceDiagram2->addMessage(*message2);
  sequenceDiagram2->addFragment(*fragment2);

  
  std::vector<string> lifelinesMock;
  lifelinesMock.push_back("lifeline");
  lifelinesMock.push_back("lifeline2");

  vector<string> response_ll = diagram->getAllLifelines();

  for(int i=0; i<lifelinesMock.size(); i++) {
    EXPECT_EQ(lifelinesMock[i], response_ll[i]);
  }

  std::vector<SequenceDiagramXML::Message> messagesMock;
  messagesMock.push_back(*message);
  messagesMock.push_back(*message2);

  vector<SequenceDiagramXML::Message> response_msg = diagram->getAllMessages(); 
  
  for(int i=0; i<messagesMock.size(); i++) {
    EXPECT_EQ(messagesMock[i].getName(), response_msg[i].getName());
    EXPECT_EQ(messagesMock[i].getOrig(), response_msg[i].getOrig());
    EXPECT_EQ(messagesMock[i].getDest(), response_msg[i].getDest());
    EXPECT_EQ(messagesMock[i].getProb(), response_msg[i].getProb());
  }

  //cout << "\n\n\nUHJIRFDESIHUJRFDEHIUJRFGD\n\n\n";

  std::vector<SequenceDiagramXML::Fragment> fragmensMock;
  fragmensMock.push_back(*fragment);
  fragmensMock.push_back(*fragment2);

  vector<SequenceDiagramXML::Fragment> response_frag = diagram->getAllFragments();

  for(int i=0; i<fragmensMock.size(); i++) {
    EXPECT_EQ(fragmensMock[i].getName(), response_frag[i].getName());
  }

}


TEST(MessageCreationTest, MessageCreation1) {
	SequenceDiagramXML diagram;
	SequenceDiagramXML::Message message("my_message");
  SequenceDiagramXML::Fragment fragment("my_fragment");
  SequenceDiagramXML::SequenceDiagram* sequenceDiagram = new SequenceDiagramXML::SequenceDiagram("my_sequenceDiagram");
  sequenceDiagram->addLifelines("lifeline");
  diagram.addDiagram(sequenceDiagram);

	message.setOrig(diagram, "lifeline");
  // cout << message.getName() << endl;

	EXPECT_EQ("my_message", message.getName());
}
