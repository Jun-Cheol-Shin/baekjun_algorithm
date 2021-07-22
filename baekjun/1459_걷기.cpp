#include <iostream>
using namespace std;

int main()
{
	long long int x, y, w, s, answer;
	cin >> x >> y >> w >> s;

	answer = 0;

	if (w * 2 <= s)
	{
		answer = (x + y) * w;
	}

	else
	{
		if (x > y)
		{
			answer = y * s + (x - y) * w;
		}
		else
		{
			answer = x * s + (y - x) * w;
		}
	}

	cout << answer;

	return 0;
}