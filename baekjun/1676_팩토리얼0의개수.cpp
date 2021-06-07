#include <iostream>
using namespace std;
#include <vector>

int main()
{

	vector<int> vec;
	int n;
	cin >> n;
	vec.push_back(1);

	// 자릿수
	int digit = 1;

	// 팩토리얼 구하기 시작!
	for (int i = 2; i <= n; ++i)
	{
		int mult = 0;
		int c = 0;

		for (c = 0; c < digit; ++c)
		{
			// 20 12
			mult = vec[c] * i + mult;

			vec[c] = mult % 10;
			mult /= 10;
		}

		while (mult)
		{
			// 2
			vec.push_back(mult % 10);
			mult /= 10;
			++digit;
		}
	}

	int answer = 0;

	for (int i = 0; i < digit; ++i)
	{
		if (vec[i] != 0) break;
		else ++answer;
	}

	cout << answer;

	return 0;
}