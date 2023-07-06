#include <stdexcept>
using namespace std;

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

	bool isLongerThanTwice(const string& str1, const string& str2)
	{
		if (str1.length() >= str2.length() * 2)
		{
			return true;
		}
		return false;
	}

	int getPartialPoint(const string& str1, const string& str2)
	{
		int gap = str1.length() - str2.length();				
		return (1 - (double)gap / str2.length()) * 60;
	}

	int checkLength(const string& str1, const string& str2)
	{
		assertInvalidArgument(str1, str2);

		if (str1.length() == str2.length())
		{
			return 60;
		}

		if (str1.length() > str2.length())
		{
			if (isLongerThanTwice(str1, str2))
			{
				return 0;
			}
			return getPartialPoint(str1, str2);
		}

		if (str1.length() < str2.length())
		{
			if (isLongerThanTwice(str2, str1))
			{
				return 0;
			}
			return getPartialPoint(str2, str1);
		}

		return -1;
	}
};