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

	int checkLength(const string& str1, const string& str2)
	{
		assertInvalidArgument(str1, str2);

		if (str1.length() == str2.length())
		{
			return 60;
		}
		else if (str1.length() > str2.length())
		{
			if (str1.length() >= str2.length() * 2)
			{
				return 0;
			}			
		}
		else if (str1.length() < str2.length())
		{
			if (str2.length() >= str1.length() * 2)
			{
				return 0;
			}
		}

		return -1;
	}
};