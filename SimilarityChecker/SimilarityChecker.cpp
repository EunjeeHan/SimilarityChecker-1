#include <stdexcept>
using namespace std;

class SimilarityChecker
{
public:
	void check(const string& str1, const string& str2)
	{
		throw invalid_argument("Must be alphabet");
	}
};