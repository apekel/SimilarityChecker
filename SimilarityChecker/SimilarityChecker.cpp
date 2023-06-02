#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int CheckCount(const string& input1, const std::string& input2)
	{
		if (input1.length() == input2.length())
		{
			return 60;
		}

		if (input1.length() >= input2.length() * 2 ||
			input2.length() >= input1.length() * 2)
		{
			return 0;
		}

		if (input1.length() > input2.length())
		{
			return (1 - (input1.length() - input2.length()) / input2.length()) * 60;
		}
		else
		{
			return (1 - (input2.length() - input1.length()) / input1.length()) * 60;
		}
	}
};