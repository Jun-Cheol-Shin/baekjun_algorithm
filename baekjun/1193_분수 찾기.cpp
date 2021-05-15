#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N; 
	cin >> N;

	// 1/1
	// 1/2, 2/1
	// 3/1, 2/2, 1/3
	// 1/4, 2/3, 3/2, 4/1
	// 5/1, 4/2, 3/3, 2/4, 1/5
	// 1/6, 2/5, 3/4, 4/3, 5/2, 6/1

	// 시작 = 짝수일땐 분모가 count, 홀수일땐 분자가 count
	// 끝  = 짝수일땐 분자가 count, 홀수일땐 분모가 count

	int c = 1;
	int count = 1;
	int denominator = 1;			// 분모
	int numerator = 1;				// 분자

	for (int i = 1; i < N; ++i)
	{
		// 끝날 때
		if (c == count)
		{
			// 초기화
			c = 1;
			++count;
			if (count & 1)
			{
				numerator = count;
				denominator = 1;
			}
			else
			{
				numerator = 1;
				denominator = count;
			}
		}

		else
		{
			++c;
			if (count & 1)
			{
				++denominator;
				--numerator;
			}

			else
			{
				--denominator;
				++numerator;
			}
		}
	}


	string answer;

	answer += to_string(numerator);
	answer += "/";
	answer += to_string(denominator);

	cout << answer << endl;

	return 0;
}