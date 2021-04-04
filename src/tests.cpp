#include "ActivityDiagram.hpp"
#include "StartNode.hpp"
#include "FinalNode.hpp"
#include "DecisionNode.hpp"
#include "MergeNode.hpp"
#include "Transition.hpp"
#include "Activity.hpp"
#include <gtest/gtest.h>
#include <fstream>
#include <ostream>

TEST(ActivityDiagramCreationTest, DiagramCreation) {
	ActivityDiagram diagram("my_diagram");

	EXPECT_EQ("my_diagram", diagram.getName());
}

TEST(ActivityDiagramCreationTest, DiagramCreation2) {
	ActivityDiagram diagram("my_second_diagram");

	EXPECT_EQ("my_second_diagram", diagram.getName());
}

TEST(ActivityDiagramCreationTest, DiagramCreation3) {
	ActivityDiagram diagram("my_last_diagram");

	EXPECT_EQ("my_last_diagram", diagram.getName());
}

TEST(StartNodeCreationTest, StartNodeCreation) {
	StartNode startNode("my_startNode");

	EXPECT_EQ("my_startNode", startNode.getName());
}

TEST(StartNodeCreationTest, StartNodeCreation2) {
	StartNode startNode("my_startNode2");

	EXPECT_EQ("my_startNode2", startNode.getName());
}

TEST(StartNodeCreationTest, StartNodeCreation3) {
	StartNode startNode("my_startNode3");

	EXPECT_EQ("my_startNode3", startNode.getName());
}

TEST(DecisionNodeCreationTest, DecisionNodeCreation) {
	DecisionNode decisionNode("my_decisionNode");

	EXPECT_EQ("my_decisionNode", decisionNode.getName());
}

TEST(DecisionNodeCreationTest, DecisionNodeCreation2) {
	DecisionNode decisionNode("my_decisionNode2");

	EXPECT_EQ("my_decisionNode2", decisionNode.getName());
}

TEST(DecisionNodeCreationTest, DecisionNodeCreation3) {
	DecisionNode decisionNode("my_decisionNode3");

	EXPECT_EQ("my_decisionNode3", decisionNode.getName());
}

TEST(MergeNodeCreationTest, MergeNodeCreation) {
	MergeNode mergeNode("my_mergeNode");

	EXPECT_EQ("my_mergeNode", mergeNode.getName());
}

TEST(MergeNodeCreationTest, MergeNodeCreation2) {
	MergeNode mergeNode("my_mergeNode2");

	EXPECT_EQ("my_mergeNode2", mergeNode.getName());
}

TEST(MergeNodeCreationTest, MergeNodeCreation3) {
	MergeNode mergeNode("my_mergeNode3");

	EXPECT_EQ("my_mergeNode3", mergeNode.getName());
}

TEST(FinalNodeCreationTest, FinalNodeCreation) {
	FinalNode finalNode("final_node");

	EXPECT_EQ("final_node", finalNode.getName());
}

TEST(FinalNodeCreationTest, FinalNodeCreation2) {
	FinalNode finalNode("ln");

	EXPECT_EQ("ln", finalNode.getName());
}

TEST(FinalNodeCreationTest, FinalNodeCreation3) {
	FinalNode finalNode("begone");

	EXPECT_EQ("begone", finalNode.getName());
}

TEST(StartNodeXMLTest, StartNodeXML) {
	StartNode startNode("my_element");

	EXPECT_EQ("<StartNode name=\"my_element\" />", startNode.toXML());
}

TEST(StartNodeXMLTest, StartNodeXML2) {
	StartNode startNode("the_beginning_of_the_end");

	EXPECT_EQ("<StartNode name=\"the_beginning_of_the_end\" />", startNode.toXML());
}

TEST(StartNodeXMLTest, StartNodeXML3) {
	StartNode startNode("wololooo");

	EXPECT_EQ("<StartNode name=\"wololooo\" />", startNode.toXML(0));
}

TEST(DecisionNodeXMLTest, DecisionNodeXML) {
	DecisionNode decisionNode("decision1");

	EXPECT_EQ("<DecisionNode name=\"decision1\" />", decisionNode.toXML());
}

TEST(DecisionNodeXMLTest, DecisionNodeXML2) {
	DecisionNode decisionNode("precise_decision");

	EXPECT_EQ("<DecisionNode name=\"precise_decision\" />", decisionNode.toXML());
}

TEST(DecisionNodeXMLTest, DecisionNodeXML3) {
	DecisionNode decisionNode("hairy_decision");

	EXPECT_EQ("<DecisionNode name=\"hairy_decision\" />", decisionNode.toXML());
}

TEST(MergeNodeXMLTest, MergeNodeXML) {
	MergeNode mergeNode("messy_merge");

	EXPECT_EQ("<MergeNode name=\"messy_merge\" />", mergeNode.toXML());
}

TEST(MergeNodeXMLTest, MergeNodeXML2) {
	MergeNode mergeNode("git_merge_master");

	EXPECT_EQ("<MergeNode name=\"git_merge_master\" />", mergeNode.toXML());
}

TEST(MergeNodeXMLTest, MergeNodeXML3) {
	MergeNode mergeNode("merging");

	EXPECT_EQ("<MergeNode name=\"merging\" />", mergeNode.toXML());
}

TEST(FinalNodeXMLTest, FinalNodeXML) {
	FinalNode finalNode("final_node");

	EXPECT_EQ("<FinalNode name=\"final_node\" />", finalNode.toXML());
}

TEST(FinalNodeXMLTest, FinalNodeXML2) {
	FinalNode finalNode("the_end_of_the_beginning");

	EXPECT_EQ("<FinalNode name=\"the_end_of_the_beginning\" />", finalNode.toXML());
}

TEST(FinalNodeXMLTest, FinalNodeXML3) {
	FinalNode finalNode("third_time_is_the_charm");

	EXPECT_EQ("<FinalNode name=\"third_time_is_the_charm\" />", finalNode.toXML());
}

TEST(ElementExceptionTest, StartNodeException) {
	ActivityDiagram diagram("test_diagram");

	diagram.addElement("start", 1);
	diagram.addElement("activity1", 2);

	try {
		diagram.addTransition("faulty_transition", "activity1", "start");
		FAIL();
	} catch(std::invalid_argument &e) {
		EXPECT_STREQ("ActivityDiagramRuleException", e.what());
	}
}

TEST(ElementExceptionTest, MergeNodeException) {
	ActivityDiagram diagram("test_diagram");

	diagram.addElement("start", 1);
	diagram.addElement("activity1", 2);
	diagram.addElement("merge1", 4);
	diagram.addElement("activity2", 2);
	diagram.addElement("activity3", 2);

	diagram.addTransition("transition1", "start", "activity1");
	diagram.addTransition("transition2", "activity1", "merge1");
	diagram.addTransition("transition3", "merge1", "activity2");

	try {
		diagram.addTransition("faulty_transition", "merge1", "activity3");
		FAIL();
	} catch(std::invalid_argument &e) {
		EXPECT_STREQ("ActivityDiagramRuleException", e.what());
	}
}

TEST(ElementExceptionTest, FinalNodeException) {
	ActivityDiagram diagram("test_diagram");

	diagram.addElement("start", 1);
	diagram.addElement("final", 5);
	diagram.addElement("activity1", 2);

	diagram.addTransition("transition1", "start", "final");

	try {
		diagram.addTransition("faulty_transition", "final", "activity1");
		FAIL();
	} catch(std::invalid_argument &e) {
		EXPECT_STREQ("ActivityDiagramRuleException", e.what());
	}
}

TEST(TransitionCreationTest, TransitionCreation) {
	Transition transition("my_transition", "my_src_element","my_dest_element");

	EXPECT_EQ("my_transition", transition.getName());
	EXPECT_EQ("my_src_element", transition.getSrc());
	EXPECT_EQ("my_dest_element", transition.getDest());
}

TEST(TransitionCreationTest, TransitionCreation2) {
	Transition transition("my_transition2", "my_src_element2","my_dest_element2");

	EXPECT_EQ("my_transition2", transition.getName());
	EXPECT_EQ("my_src_element2", transition.getSrc());
	EXPECT_EQ("my_dest_element2", transition.getDest());
}

TEST(TransitionCreationTest, TransitionCreation3) {
	Transition transition("my_transition3", "my_src_element3","my_dest_element3");

	EXPECT_EQ("my_transition3", transition.getName());
	EXPECT_EQ("my_src_element3", transition.getSrc());
	EXPECT_EQ("my_dest_element3", transition.getDest());
}

TEST(TransitionXMLTest, TransitionXML) {
	Transition transition("my_transition", "my_src_element","my_dest_element");

	EXPECT_EQ("<Transition name=\"my_transition\" src=\"my_src_element\" dest=\"my_dest_element\" />", transition.toXML(0));
}

TEST(TransitionXMLTest, TransitionXML2) {
	Transition transition("my_transition2", "my_src_element2","my_dest_element2");

	EXPECT_EQ("<Transition name=\"my_transition2\" src=\"my_src_element2\" dest=\"my_dest_element2\" />", transition.toXML(0));
}

TEST(TransitionXMLTest, TransitionXML3) {
	Transition transition("my_transition3", "my_src_element3","my_dest_element3");

	EXPECT_EQ("<Transition name=\"my_transition3\" src=\"my_src_element3\" dest=\"my_dest_element3\" />", transition.toXML(0));
}

TEST(DiagramElementAdditionTest, DiagramElementAddition) {
	ActivityDiagram diagram("my_diagram");
	diagram.addElement("start", 1);

	Element *element = diagram.getElement("start");

	EXPECT_EQ("start", element->getName());
}

TEST(DiagramElementAdditionTest, DiagramElementAddition2) {
	ActivityDiagram diagram("my_diagram");
	diagram.addElement("start", 1);
	diagram.addElement("activity", 3);

	Element *element = diagram.getElement("activity");

	EXPECT_EQ("activity", element->getName());
}

TEST(DiagramElementAdditionTest, DiagramElementAddition3) {
	ActivityDiagram diagram("my_diagram");
	diagram.addElement("merge", 4);

	Element *element = diagram.getElement("merge");

	EXPECT_EQ("merge", element->getName());
}

/*TEST(DiagramElementAdditionTest, DiagramElementAddition2) {
	ActivityDiagram diagram("my_diagram");
	diagram.addElement("end", 5);

	Element element = diagram.getElement("end");

	EXPECT_EQ("end", element.getName());
	EXPECT_EQ("FinalNode", element.getType());
}

TEST(DiagramElementAdditionTest, DiagramElementAddition3) {
	ActivityDiagram diagram("my_diagram");
	diagram.addElement("decision", 3);

	Element element = diagram.getElement("decision");

	EXPECT_EQ("decision", element.getName());
	EXPECT_EQ("DecisionNode", element.getType());
}

TEST(DiagramTransitionAdditionTest, DiagramTransitionAddition) {
	ActivityDiagram diagram("my_diagram");
	diagram.addTransition("my_transition", "my_src","my_dest");

	Transition transition = diagram.getTransition("my_transition");

	EXPECT_EQ("my_transition", transition.getName());
	EXPECT_EQ("my_src", transition.getSrc());
	EXPECT_EQ("my_dest", transition.getDest());
}

TEST(DiagramTransitionAdditionTest, DiagramTransitionAddition2) {
	ActivityDiagram diagram("my_diagram2");
	diagram.addTransition("my_transition2", "my_src2","my_dest2");

	Transition transition = diagram.getTransition("my_transition2");

	EXPECT_EQ("my_transition2", transition.getName());
	EXPECT_EQ("my_src2", transition.getSrc());
	EXPECT_EQ("my_dest2", transition.getDest());
}

TEST(DiagramTransitionAdditionTest, DiagramTransitionAddition3) {
	ActivityDiagram diagram("my_diagram3");
	diagram.addTransition("my_transition3", "my_src3","my_dest3");

	Transition transition = diagram.getTransition("my_transition3");

	EXPECT_EQ("my_transition3", transition.getName());
	EXPECT_EQ("my_src3", transition.getSrc());
	EXPECT_EQ("my_dest3", transition.getDest());
}

TEST(DiagramXMLTest, DiagramXML) {
	ActivityDiagram diagram("diagrama_mio");

	diagram.addElement("partida", 1);
	diagram.addElement("finale", 5);

	diagram.addTransition("transition1", "partida", "finale");

	EXPECT_EQ("<ActivityDiagram name=\"diagrama_mio\">\n\t<ActivityDiagramElements>\n\t\t<FinalNode name=\"finale\" />\n\t\t<StartNode name=\"partida\" />\n\t</ActivityDiagramElements>\n\t<ActivityDiagramTransitions>\n\t\t<Transition name=\"transition1\" src=\"partida\" dest=\"finale\" />\n\t</ActivityDiagramTransitions>\n</ActivityDiagram>",
			  diagram.toXML()
			 );
}

TEST(DiagramXMLTest, DiagramXML2) {
	ActivityDiagram diagram("diagram");

	diagram.addElement("start", 1);
	diagram.addElement("activity1", 2);
	diagram.addElement("end", 5);

	diagram.addTransition("transition1", "partida", "activity1");
	diagram.addTransition("transition2", "activity2", "end");

	EXPECT_EQ("<ActivityDiagram name=\"diagram\">\n\t<ActivityDiagramElements>\n\t\t<Activity name=\"activity1\" />\n\t\t<FinalNode name=\"end\" />\n\t\t<StartNode name=\"start\" />\n\t</ActivityDiagramElements>\n\t<ActivityDiagramTransitions>\n\t\t<Transition name=\"transition1\" src=\"partida\" dest=\"activity1\" />\n\t\t<Transition name=\"transition2\" src=\"activity2\" dest=\"end\" />\n\t</ActivityDiagramTransitions>\n</ActivityDiagram>",
			  diagram.toXML()
			 );
}

TEST(DiagramXMLTest, DiagramXML3) {
	ActivityDiagram diagram("diagram");

	diagram.addElement("start", 1);
	diagram.addElement("activity1", 2);
	diagram.addElement("activity2",2);
	diagram.addElement("end", 5);

	diagram.addTransition("transition1", "partida", "activity1");
	diagram.addTransition("transition2", "activity1", "activity2");
	diagram.addTransition("transition2", "activity2", "end");

	EXPECT_EQ("<ActivityDiagram name=\"diagram\">\n\t<ActivityDiagramElements>\n\t\t<Activity name=\"activity1\" />\n\t\t<Activity name=\"activity2\" />\n\t\t<FinalNode name=\"end\" />\n\t\t<StartNode name=\"start\" />\n\t</ActivityDiagramElements>\n\t<ActivityDiagramTransitions>\n\t\t<Transition name=\"transition1\" src=\"partida\" dest=\"activity1\" />\n\t\t<Transition name=\"transition2\" src=\"activity1\" dest=\"activity2\" />\n\t</ActivityDiagramTransitions>\n</ActivityDiagram>",
			  diagram.toXML()
			 );
}

TEST(DiagramExportXMLTest, DiagramExportXML) {
	std::ifstream in;
	ActivityDiagram diagram("diagram");

	diagram.addElement("start", 1);
	diagram.addElement("activity1", 2);
	diagram.addElement("activity2", 2);
	diagram.addElement("end", 5);

	diagram.addTransition("transition1", "partida", "activity1");
	diagram.addTransition("transition2", "activity1", "activity2");
	diagram.addTransition("transition2", "activity2", "end");

	diagram.exportXML();

	in.open("ActivityDiagram.xml");
	auto ss = ostringstream{};
	ss << in.rdbuf();
		
	EXPECT_EQ("<ActivityDiagram name=\"diagram\">\n\t<ActivityDiagramElements>\n\t\t<Activity name=\"activity1\" />\n\t\t<Activity name=\"activity2\" />\n\t\t<FinalNode name=\"end\" />\n\t\t<StartNode name=\"start\" />\n\t</ActivityDiagramElements>\n\t<ActivityDiagramTransitions>\n\t\t<Transition name=\"transition1\" src=\"partida\" dest=\"activity1\" />\n\t\t<Transition name=\"transition2\" src=\"activity1\" dest=\"activity2\" />\n\t</ActivityDiagramTransitions>\n</ActivityDiagram>",
		ss.str()
	);
}

TEST(DiagramExportXMLTest, DiagramExportXML2) {
	std::ifstream in;
	ActivityDiagram diagram("diagram2");

	diagram.addElement("start", 1);
	diagram.addElement("activity1", 2);
	diagram.addElement("activity2", 2);
	diagram.addElement("end", 5);

	diagram.addTransition("transition1", "partida", "activity1");
	diagram.addTransition("transition2", "activity1", "activity2");
	diagram.addTransition("transition2", "activity2", "end");

	diagram.exportXML();

	in.open("ActivityDiagram.xml");
	auto ss = ostringstream{};
	ss << in.rdbuf();
		
	EXPECT_EQ("<ActivityDiagram name=\"diagram2\">\n\t<ActivityDiagramElements>\n\t\t<Activity name=\"activity1\" />\n\t\t<Activity name=\"activity2\" />\n\t\t<FinalNode name=\"end\" />\n\t\t<StartNode name=\"start\" />\n\t</ActivityDiagramElements>\n\t<ActivityDiagramTransitions>\n\t\t<Transition name=\"transition1\" src=\"partida\" dest=\"activity1\" />\n\t\t<Transition name=\"transition2\" src=\"activity1\" dest=\"activity2\" />\n\t</ActivityDiagramTransitions>\n</ActivityDiagram>",
		ss.str()
	);
}

TEST(DiagramExportXMLTest, DiagramExportXML3) {
	std::ifstream in;
	ActivityDiagram diagram("diagram3");

	diagram.addElement("start", 1);
	diagram.addElement("activity1", 2);
	diagram.addElement("activity2", 2);
	diagram.addElement("end", 5);

	diagram.addTransition("transition1", "partida", "activity1");
	diagram.addTransition("transition2", "activity1", "activity2");
	diagram.addTransition("transition2", "activity2", "end");

	diagram.exportXML();

	in.open("ActivityDiagram.xml");
	auto ss = ostringstream{};
	ss << in.rdbuf();
		
	EXPECT_EQ("<ActivityDiagram name=\"diagram3\">\n\t<ActivityDiagramElements>\n\t\t<Activity name=\"activity1\" />\n\t\t<Activity name=\"activity2\" />\n\t\t<FinalNode name=\"end\" />\n\t\t<StartNode name=\"start\" />\n\t</ActivityDiagramElements>\n\t<ActivityDiagramTransitions>\n\t\t<Transition name=\"transition1\" src=\"partida\" dest=\"activity1\" />\n\t\t<Transition name=\"transition2\" src=\"activity1\" dest=\"activity2\" />\n\t</ActivityDiagramTransitions>\n</ActivityDiagram>",
		ss.str()
	);
}*/

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}