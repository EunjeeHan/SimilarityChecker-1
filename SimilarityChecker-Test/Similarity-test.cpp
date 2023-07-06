#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(SimilarityCheckerTest, ThrowExceptionIfNotAlphabet) {
	SimilarityChecker checker;
	try
	{
		checker.check(string("1A"), string("AB"));
		FAIL();
	}
	catch (exception e)
	{
		// PASS
	}
}