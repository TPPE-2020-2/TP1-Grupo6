#include "testElement.cpp"
#include "testActivityDiagram.cpp"
#include "testSequenceDiagram.cpp"

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}