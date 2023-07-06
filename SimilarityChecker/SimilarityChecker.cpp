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

	bool isBiggerThanTwice(const string& str1, const string& str2)
	{
		if (str1.length() >= str2.length() * 2)
		{
			return true;
		}
		return false;
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
			if (isBiggerThanTwice(str1, str2))
			{
				return 0;
			}
		}

		if (str1.length() < str2.length())
		{
			if (isBiggerThanTwice(str2, str1))
			{
				return 0;
			}
		}

		return -1;
	}
};