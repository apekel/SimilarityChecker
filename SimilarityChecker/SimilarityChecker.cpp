#include <string>
#include <vector>
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

	int CheckAlphabet(const string& input1, const std::string& input2)
	{
		int SameAlphabetCount = GetSameAlphabetCount(input1, input2);

		if (SameAlphabetCount == ALPLABET_COUNT)
			return MAX_SCORE_OF_ALPHABET_CHECK;
		return SameAlphabetCount / GetAlphabetCount(input1 + input2) * MAX_SCORE_OF_ALPHABET_CHECK;
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
        
	vector<int> GetAlphabetCountArray(const string& string)
        {
                vector<int> result;
                for (int i = 0; i < ALPLABET_COUNT; i++)
                {
                        if (string.find('A'+i)!=-1)
                        {
                                result.push_back(1);
                        }
                        else
                        {
                                result.push_back(0);
                        }
                }
                return result;
        }

        int GetAlphabetCount(const string& string)
        {
                int result = 0;
                for (int i = 0; i < ALPLABET_COUNT; i++)
                {
                        if (string.find('A' + i)!=-1)
                        {
                                result++;
                        }
                }
                return result;
        }

        int GetSameAlphabetCount(const string& input1, const string& input2)
        {
                int result = 0;
                vector<int> alphabetCount1 = GetAlphabetCountArray(input1);
                vector<int> alphabetCount2 = GetAlphabetCountArray(input2);
                for (int i = 0; i < ALPLABET_COUNT; i++)
                {
                        if ((alphabetCount1[i] == 1) && (alphabetCount2[i] == 1))
                        {
                                result++;
                        }
                }
                return result;
        }

private:
	const int MAX_SCORE_OF_COUNT_CHECK = 60;
	const int MAX_SCORE_OF_ALPHABET_CHECK = 40;
	const int ZERO_SCORE = 0;
	const int ALPLABET_COUNT = 'Z' - 'A' + 1;
};
