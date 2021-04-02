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

  // ASSERT_THAT(lifelinesMock, sequenceDiagram.getLifelines());
  for(int i=0; i<lifelinesMock.size(); i++) {
    EXPECT_EQ(lifelinesMock[i], sequenceDiagram.getLifelines()[i]);
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