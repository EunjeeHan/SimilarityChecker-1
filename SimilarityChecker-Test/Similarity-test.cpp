#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(SimilarityCheckerTest, ThrowExceptionIfNotAlphabet) {
	SimilarityChecker checker;
	EXPECT_THROW(checker.check(string("1A"), string("AB")), invalid_argument);
}