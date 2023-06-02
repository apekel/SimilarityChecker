#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int CheckCount(const string& input1, const std::string& input2)
	{
		if (IsSame(input1, input2))
		{
			return MAX_SCORE_OF_COUNT_CHECK;
		}

		if (IsMoreThanTwiceLength(input1, input2))
		{
			return ZERO_SCORE;
		}

		int longInput = input2.length();
		int shortInput = input1.length();

		if (IsInput1Longer(input1, input2))
		{
			longInput = input1.length();
			shortInput = input2.length();
		}

		return (2 * shortInput - longInput) * 60 / shortInput;
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

private:
	const int MAX_SCORE_OF_COUNT_CHECK = 60;
	const int ZERO_SCORE = 0;
};