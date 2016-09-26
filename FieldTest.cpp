/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
	ASSERT_EQ(EMPTY_HIDDEN, minefield.get(5,5));

}
TEST(FieldTest, customField)
{
	Field minefield = Field(4);
	minefield.placeMine(4,4);
	ASSERT_EQ(MINE_HIDDEN ,minefield.get(4,4));
}
TEST(FieldTest, isSafe)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ(1, minefield.get(4,5) );
	ASSERT_EQ(0, minefield.get(1,1));

}
TEST(FieldTest, isSafeOutOFBOUNDS)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ(1, minefield.get(1,11));

}
TEST(FieldTest, revealAdjacent)
{
	Field minefield;
	
	minefield.placeMine(5,6);
	minefield.placeMine(4,5);	
	minefield.revealAdjacent(5,5);	
	ASSERT_EQ( MINE_SHOWN, minefield.get(5,6) );
	ASSERT_EQ(EMPTY_SHOWN, minefield.get(5,4));
	ASSERT_EQ(MINE_SHOWN, minefield.get(4,5));
	ASSERT_EQ(EMPTY_SHOWN, minefield.get(6,5));

}
