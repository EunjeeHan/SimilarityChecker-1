#include <stdexcept>
using namespace std;

class SimilarChar
{
public:
	void checkFoundAlphabet(const string& str, int(& foundStr)[26])
	{
		for (char ch : str)
		{
			int index = ch - 'A';
			foundStr[index] = 1;
		}
	}

	int getSameCnt(int foundStr1[26], int foundStr2[26])
	{
		int sameCnt = 0;
		for (int i = 0; i < 26; i++)
		{
			if (foundStr1[i] && foundStr2[i])
			{
				sameCnt++;
			}
		}
		return sameCnt;
	}

	int getTotalCnt(int foundStr1[26], int foundStr2[26])
	{
		int totalCnt = 0;
		for (int i = 0; i < 26; i++)
		{
			if (foundStr1[i] || foundStr2[i])
			{
				totalCnt++;
			}
		}
		return totalCnt;
	}

	bool isSameChar(int foundStr1[26], int foundStr2[26])
	{
		int sameCnt = getSameCnt(foundStr1, foundStr2);
		int totalCnt = getTotalCnt(foundStr1, foundStr2);

		if (sameCnt == totalCnt) return true;
		return false;
	}

	bool isDiffChar(int foundStr1[26], int foundStr2[26])
	{
		int sameCnt = getSameCnt(foundStr1, foundStr2);

		if (sameCnt == 0) return true;
		return false;
	}

	int getPartialPoint(int foundStr1[26], int foundStr2[26])
	{
		int sameCnt = getSameCnt(foundStr1, foundStr2);
		int totalCnt = getTotalCnt(foundStr1, foundStr2);

		return ((double)sameCnt / totalCnt) * 40;
	}

	int checkAlphabet(const string& str1, const string& str2)
	{
		int foundStr1[26] = { 0, };
		int foundStr2[26] = { 0, };
		checkFoundAlphabet(str1, foundStr1);		
		checkFoundAlphabet(str2, foundStr2);

		if (isSameChar(foundStr1, foundStr2)) return MAX_CHAR_POINT;
		if (isDiffChar(foundStr1, foundStr2)) return MIN_CHAR_POINT;

		return getPartialPoint(foundStr1, foundStr2);
	}
private:
	const int MAX_CHAR_POINT = 40;
	const int MIN_CHAR_POINT = 0;
};

class SimilarityChecker
{
public:
	void assertInvalidArgument(const string& str1, const string& str2)
	{
		for (char ch : str1)
		{
			if (ch >= 'A' && ch <= 'Z')
				continue;
			throw invalid_argument("Must be alphabet");
		}		
		for (char ch : str2)
		{
			if (ch >= 'A' && ch <= 'Z')
				continue;
			throw invalid_argument("Must be alphabet");
		}
	}

	int getLengthPoint(const string& str1, const string& str2)
	{
		int gap = str1.length() - str2.length();				
		return (1 - (double)gap / str2.length()) * MAX_LENGTH_POINT;
	}
	
	bool isEqualAndLongerForFirstString(const string& str1, const string& str2)
	{
		return str1.length() >= str2.length();
	}

	int checkLength(const string& str1, const string& str2)
	{
		assertInvalidArgument(str1, str2);
				
		if (isEqualAndLongerForFirstString(str1, str2))
		{
			return getLengthPoint(str1, str2);
		}
		
		return getLengthPoint(str2, str1);
	}

private:
	const int MAX_LENGTH_POINT = 60;	
};