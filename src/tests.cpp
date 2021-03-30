#include "ActivityDiagram.hpp"
#include <gtest/gtest.h>

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

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}