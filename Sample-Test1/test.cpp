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
	EXPECT_EQ(((2 * 3 - 5) * 60) / 3, similarityChecker.CheckCount(input1, input2));
}

TEST(CheckCount, DiffInput2Long)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "ABCAB";
	EXPECT_EQ(((2 * 3 - 5) * 60) / 3, similarityChecker.CheckCount(input1, input2));
}
TEST(CheckAlphabet, Same1)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "CBA";
	EXPECT_EQ(40, similarityChecker.CheckAlphabet(input1, input2));
}

TEST(CheckAlphabet, Same2)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "ABCAB";
	EXPECT_EQ(40, similarityChecker.CheckAlphabet(input1, input2));
}

TEST(CheckAlphabet, Diff1)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "DEF";
	EXPECT_EQ(0, similarityChecker.CheckAlphabet(input1, input2));
}

TEST(CheckAlphabet, Diff2)
{
	SimilarityChecker similarityChecker;
	string input1 = "ABC";
	string input2 = "AAAAA";
	EXPECT_EQ(1/3*40, similarityChecker.CheckAlphabet(input1, input2));
}
