#include <iostream>
using namespace std;

// 4, 2
int GCD(int a, int b)
{
	if (b == 0) return a;

	return GCD(b, a % b);
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int answer = -1;
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int limit = LCM(M, N);

		while (x < limit || y < limit)
		{
			if (x == y)
			{
				answer = x;
				break;
			}

			if (x > y) y += N;
			else x += M;
		}

		// 3, 13, 23 33
		// 9, 21, 33

		cout << answer << endl;
	}

	return 0;
}