#include <iostream>
#include <string>
using namespace std;

/*	
	어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
	등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
	N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 
*/

bool han(int X);

int main()
{
	int N;
	cin >> N;

	int answer = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (han(i)) ++answer;
	}

	printf("%d", answer);

	return 0;
}

bool han(int X)
{
	if (X < 100) return true;

	else
	{
		string number = to_string(X);
		int comp = (number[0] - '0') - (number[1] - '0');

		for (int i = 1; i < number.length() - 1; ++i)
		{
			if (comp != (number[i] - '0') - (number[i + 1] - '0'))
			{
				return false;
			}
		}
	}

	return true;
}