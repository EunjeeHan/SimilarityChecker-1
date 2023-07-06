#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

class CheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
	void assertInvalidArgument(string str1, string str2)
	{
		try
		{
			checker.checkLength(str1, str2);
			FAIL();
		}
		catch (exception e)
		{
			// PASS
		}
	}
};

TEST_F(CheckerFixture, ThrowExceptionIfNotAlphabet) {
	assertInvalidArgument("1A", "AB");
}

TEST_F(CheckerFixture, SameLengthTest) {
	EXPECT_EQ(60, checker.checkLength("ASD", "DSA"));
}

TEST_F(CheckerFixture, MoreThanTwiceTest) {
	EXPECT_EQ(0, checker.checkLength("A", "BB"));
}

TEST_F(CheckerFixture, LessThanTwiceAndFirstIsLongerTest) {
	EXPECT_EQ(20, checker.checkLength("AAABB", "BAA"));
	EXPECT_EQ(45, checker.checkLength("AAABB", "BAAB"));	
}

TEST_F(CheckerFixture, LessThanTwiceAndSecondIsLongerTest) {
	EXPECT_EQ(20, checker.checkLength("BAA", "AAABB"));
	EXPECT_EQ(45, checker.checkLength("BAAB", "AAABB"));
	EXPECT_EQ(30, checker.checkLength("AA", "AAE"));
}
