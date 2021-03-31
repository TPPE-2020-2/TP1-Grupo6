#include "../inc/SequenceDiagram.hpp"
#include <gtest/gtest.h>

TEST(SequenceDiagramCreationTest, DiagramCreation) {
	SequenceDiagram diagram("my_diagram");

	EXPECT_EQ("my_diagram", diagram.getName());
}