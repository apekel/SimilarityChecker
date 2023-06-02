#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int CheckCount(const string& input1, const std::string& input2)
	{
		if (IsSame(input1, input2))
		{
			return 60;
		}

		if (IsMoreThanTwiceLength(input1, input2))
		{
			return 0;
		}

		if (IsInput1Longer(input1, input2))
		{
			return (1 - (input1.length() - input2.length()) / input2.length()) * 60;
		}
		else
		{
			return (1 - (input2.length() - input1.length()) / input1.length()) * 60;
		}
	}
	bool IsSame(const string& input1, const std::string& input2)
	{
		return input1.length() == input2.length();
	}

	bool IsMoreThanTwiceLength(const string& input1, const std::string& input2)
	{
		return input1.length() >= input2.length() * 2 ||
			input2.length() >= input1.length() * 2;
	}

	bool IsInput1Longer(const string& input1, const std::string& input2)
	{
		return input1.length() > input2.length();
	}

};