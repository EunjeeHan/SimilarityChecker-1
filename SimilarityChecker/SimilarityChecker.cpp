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

	int checkAlphabet(const string& str1, const string& str2)
	{
		int foundStr1[26] = { 0, };
		int foundStr2[26] = { 0, };
		checkFoundAlphabet(str1, foundStr1);		
		checkFoundAlphabet(str2, foundStr2);

		int sameCnt = getSameCnt(foundStr1, foundStr2);
		int totalCnt = getTotalCnt(foundStr1, foundStr2);

		if (sameCnt == totalCnt) return 40;
		if (sameCnt == 0) return 0;
		return -1;
	}
private:
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