#include "ActivityDiagram.hpp"
#include "Element.hpp"
#include "Transition.hpp"
#include <gtest/gtest.h>
#include <fstream>

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

TEST(ElementCreationTest, ElementCreation) {
	Element element("ex_element", 1);

	EXPECT_EQ("ex_element", element.getName());
	EXPECT_EQ("StartNode", element.getType());
}

TEST(ElementCreationTest, ElementCreation2) {
	Element element("ex_element2", 2);

	EXPECT_EQ("ex_element2", element.getName());
	EXPECT_EQ("Activity", element.getType());
}

TEST(ElementCreationTest, ElementCreation3) {
	Element element("ex_element3", 3);

	EXPECT_EQ("ex_element3", element.getName());
	EXPECT_EQ("DecisionNode", element.getType());
}

TEST(ElementXMLTest, ElementXML) {
	Element element("my_element", 1);

	EXPECT_EQ("<StartNode name=\"my_element\" />", element.toXML());
}

TEST(ElementXMLTest, ElementXML2) {
	Element element("endnode", 5);

	EXPECT_EQ("\t<FinalNode name=\"endnode\" />", element.toXML(1));
}

TEST(ElementXMLTest, ElementXML3) {
	Element element("arrival", 4);

	EXPECT_EQ("<MergeNode name=\"arrival\" />", element.toXML());
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

	Element element = diagram.getElement("start");

	EXPECT_EQ("start", element.getName());
	EXPECT_EQ("StartNode", element.getType());
}

TEST(DiagramElementAdditionTest, DiagramElementAddition2) {
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
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}