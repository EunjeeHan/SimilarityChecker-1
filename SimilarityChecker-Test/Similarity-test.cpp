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
	assertInvalidArgument(string("1A"), string("AB"));
}

TEST_F(CheckerFixture, SameLengthTest) {
	vector<string> input = { "ASD", "DSA" };
	EXPECT_EQ(60, checker.checkLength(input[0], input[1]));
}
