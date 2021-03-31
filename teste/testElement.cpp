#include "../inc/Element.hpp"
#include <gtest/gtest.h>

TEST(ElementCreationTest, ElementCreation) {
	Element element("ex_element",1);

	EXPECT_EQ("ex_element", element.getName());
	EXPECT_EQ("Actor", element.getType());
}

TEST(ElementCreationTest, ElementCreation2) {
	Element element("ex_element2",2);

	EXPECT_EQ("ex_element2", element.getName());
	EXPECT_EQ("Object", element.getType());
}

TEST(ElementCreationTest, ElementCreation3) {
	Element element("ex_element3",1);

	EXPECT_EQ("ex_element3", element.getName());
	EXPECT_EQ("Actor", element.getType());
}