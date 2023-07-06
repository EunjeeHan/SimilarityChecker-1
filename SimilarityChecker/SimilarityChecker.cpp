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

	int getSamePoint(const string& str1, const string& str2)
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
			return getSamePoint(str1, str2);
		}
		
		return getSamePoint(str2, str1);
	}
private:
	const int MAX_LENGTH_POINT = 60;
};