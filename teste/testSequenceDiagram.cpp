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
  SequenceDiagramXML::SequenceDiagram sequenceDiagram("my_sequenceDiagram");
  sequenceDiagram.addLifelines("lifeline");
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
  SequenceDiagramXML::SequenceDiagram sequenceDiagram("my_sequenceDiagram");
  SequenceDiagramXML::Fragment fragment("my_fragment");
  diagram.addDiagram(sequenceDiagram);
  fragment.setSeqDiagram(diagram, "my_sequenceDiagram");

  EXPECT_EQ("my_fragment", fragment.getName());
  EXPECT_EQ("my_sequenceDiagram", fragment.getSeqDiagram());
}

TEST(SequenceDiagramCreationTest, SequenceDiagramCreation) {
  SequenceDiagramXML diagram;
  SequenceDiagramXML::SequenceDiagram sequenceDiagram("my_sequenceDiagram");
  sequenceDiagram.addLifelines("lifeline");
  diagram.addDiagram(sequenceDiagram);
  SequenceDiagramXML::Message message("my_message");
  message.setOrig(diagram, "lifeline");
  message.setDest(diagram, "lifeline");
  message.setProb(1.0);
  SequenceDiagramXML::Fragment fragment("my_fragment");
  fragment.setSeqDiagram(diagram, "my_sequenceDiagram");
  
  sequenceDiagram.addMessage(message);
  sequenceDiagram.addFragment(fragment);

  std::vector<string> lifelinesMock;
  lifelinesMock.push_back("lifeline");

  for(int i=0; i<lifelinesMock.size(); i++) {
    EXPECT_EQ(lifelinesMock[i], sequenceDiagram.getLifelines()[i]);
  }


  std::vector<SequenceDiagramXML::Message> messagesMock;
  messagesMock.push_back(message);

  for(int i=0; i<messagesMock.size(); i++) {
    EXPECT_EQ(messagesMock[i].getName(), sequenceDiagram.getMessages()[i].getName());
  }


  std::vector<SequenceDiagramXML::Fragment> fragmensMock;
  fragmensMock.push_back(fragment);

  for(int i=0; i<fragmensMock.size(); i++) {
    EXPECT_EQ(fragmensMock[i].getName(), sequenceDiagram.getFragments()[i].getName());
  }
}

TEST(SequenceDiagramXMLCreationTest, SequenceDiagramXMLCreationTest1) {
	SequenceDiagramXML diagram;
  SequenceDiagramXML::SequenceDiagram sequenceDiagram("my_sequenceDiagram");
  sequenceDiagram.addLifelines("lifeline");
  SequenceDiagramXML::Message message("my_message");
  message.setOrig(diagram, "lifeline");
  message.setDest(diagram, "lifeline");
  message.setProb(1.0);
  SequenceDiagramXML::Fragment fragment("my_fragment");
  cout << "\n\n\nUHJIRFDESIHUJRFDEHIUJRFGD\n\n\n";
  fragment.setSeqDiagram(diagram, "my_sequenceDiagram");
  sequenceDiagram.getMessages();
  sequenceDiagram.addMessage(message);
  sequenceDiagram.addFragment(fragment);
  diagram.addDiagram(sequenceDiagram);

  SequenceDiagramXML::SequenceDiagram sequenceDiagram2("my_sequenceDiagram2");
  sequenceDiagram2.addLifelines("lifeline2");
  SequenceDiagramXML::Message message2("my_message2");
  message2.setOrig(diagram, "lifeline2");
  message2.setDest(diagram, "lifeline2");
  message2.setProb(0.0);
  SequenceDiagramXML::Fragment fragment2("my_fragment2");
  fragment2.setSeqDiagram(diagram, "my_sequenceDiagram2");
  sequenceDiagram2.addMessage(message2);
  sequenceDiagram2.addFragment(fragment2);
  diagram.addDiagram(sequenceDiagram2);

  
  std::vector<string> lifelinesMock;
  lifelinesMock.push_back("lifeline");
  lifelinesMock.push_back("lifeline2");

  for(int i=0; i<lifelinesMock.size(); i++) {
    // EXPECT_EQ(lifelinesMock[i], diagram.getAllLifelines()[i]);
  }

  std::vector<SequenceDiagramXML::Message> messagesMock;
  messagesMock.push_back(message);
  messagesMock.push_back(message2);

  // diagram.getAllMessages(); 
  for(int i=0; i<messagesMock.size(); i++) {
    // cout << "FORORONK  " << diagram.getAllMessages().size() << endl;
    // EXPECT_EQ(messagesMock[i].getName(), diagram.getAllMessages()[i].getName());
  }


  std::vector<SequenceDiagramXML::Fragment> fragmensMock;
  fragmensMock.push_back(fragment);
  fragmensMock.push_back(fragment2);

  for(int i=0; i<fragmensMock.size(); i++) {
    // EXPECT_EQ(fragmensMock[i].getName(), diagram.getAllFragments()[i].getName());
  }

}


TEST(MessageCreationTest, MessageCreation1) {
	SequenceDiagramXML diagram;
	SequenceDiagramXML::Message message("my_message");
  SequenceDiagramXML::Fragment fragment("my_fragment");
  SequenceDiagramXML::SequenceDiagram sequenceDiagram("my_sequenceDiagram");
  sequenceDiagram.addLifelines("lifeline");
  diagram.addDiagram(sequenceDiagram);

	message.setOrig(diagram, "lifeline");
  // cout << message.getName() << endl;

	EXPECT_EQ("my_message", message.getName());
}