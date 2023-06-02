#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(CheckCount, Same)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "ABC";
	EXPECT_EQ(60, similarityChecker.CheckCount(input1, input2));
}

TEST(CheckCount, DiffWithTwiceLength)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "ABCABC";
	EXPECT_EQ(0, similarityChecker.CheckCount(input1, input2));
}

TEST(CheckCount, DiffInput1Long)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABCAB";
	string input2 = "ABC";
	EXPECT_EQ((1 - (5-3)/3)*60, similarityChecker.CheckCount(input1, input2));
}

TEST(CheckCount, DiffInput2Long)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "ABCAB";
	EXPECT_EQ((1 - (5 - 3) / 3) * 60, similarityChecker.CheckCount(input1, input2));
}