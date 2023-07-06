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

	void check(const string& str1, const string& str2)
	{
		assertInvalidArgument(str1, str2);
	}
};