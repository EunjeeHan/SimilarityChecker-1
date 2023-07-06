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
			checker.check(str1, str2);
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

	int ret = checker.check(input[0], input[1]);
	EXPECT_EQ(60, ret);	
}
