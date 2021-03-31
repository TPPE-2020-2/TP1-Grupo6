#include "../inc/Element.hpp"
#include <gtest/gtest.h>

TEST(ElementCreationTest, ElementCreation) {
	Element element("ex_element","ex_type");

	EXPECT_EQ("ex_element", element.getName());
	EXPECT_EQ("ex_type", element.getType());
}

TEST(ElementCreationTest, ElementCreation2) {
	Element element("ex_element2","ex_type2");

	EXPECT_EQ("ex_element2", element.getName());
	EXPECT_EQ("ex_type2", element.getType());
}

TEST(ElementCreationTest, ElementCreation3) {
	Element element("ex_element3","ex_type3");

	EXPECT_EQ("ex_element3", element.getName());
	EXPECT_EQ("ex_type3", element.getType());
}