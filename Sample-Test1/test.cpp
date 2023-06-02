#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(CheckCount, Same)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "ABC";
	EXPECT_EQ(60, similarityChecker.CheckCount(input1, input2));
}

TEST(CheckCount, Diff1)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "ABCABC";
	EXPECT_EQ(0, similarityChecker.CheckCount(input1, input2));
}

TEST(CheckCount, Diff2)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABCAB";
	string input2 = "ABC";
	EXPECT_EQ((1 - (5-3)/3)*60, similarityChecker.CheckCount(input1, input2));
}

TEST(CheckCount, Diff3)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "ABCAB";
	EXPECT_EQ((1 - (5 - 3) / 3) * 60, similarityChecker.CheckCount(input1, input2));
}