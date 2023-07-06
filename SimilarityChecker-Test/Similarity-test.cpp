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