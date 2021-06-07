#include <iostream>
using namespace std;

int main()
{
	int min, max;
	cin >> min >> max;

	bool* num = new bool[max + 1];
	num[1] = false;
	for (int i = 2; i < max + 1; ++i)
	{
		num[i] = true;
	}

	// 에라토스테네스의 체로 구하자

	for (int i = 2; i + i <= max; ++i)
	{
		if (num[i])
		{
			for (int j = i + i; j <= max; j += i)
			{
				num[j] = false;
			}
		}
	}

	for (int i = min; i <= max; ++i)
	{
		if (num[i]) cout << i << "\n";
	}

	delete[] num;
}