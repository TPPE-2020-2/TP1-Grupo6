#include "ActivityDiagram.hpp"
#include <gtest/gtest.h>

TEST(ActivityDiagramTest, DiagramCreation) {
	ActivityDiagram diagram("my_diagram");

	EXPECT_EQ("my_diagram", diagram.getName());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}