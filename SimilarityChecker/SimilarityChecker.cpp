#include <stdexcept>
using namespace std;

class SimilarityChecker
{
public:
	void check(const string& str1, const string& str2)
	{
		for (char ch : str1)
		{
			if (ch < 'A' || ch > 'Z')
			{
				throw invalid_argument("Must be alphabet");
			}
		}		
		for (char ch : str2)
		{
			if (ch < 'A' || ch > 'Z')
			{
				throw invalid_argument("Must be alphabet");
			}
		}		
	}
};