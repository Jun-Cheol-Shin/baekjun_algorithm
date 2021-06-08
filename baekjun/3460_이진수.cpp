#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	// 
	// 0 1 1 1

	while (T--)
	{
		int n;
		cin >> n;

		int digit = 0;
		// 13  1 1 0 1
		// 1
		// 0
		// 1
		// 1
		while (n)
		{
			int val = n % 2;

			if (val == 1) printf("%d ", digit);
			++digit;
			n /= 2;
		}
	}

	return 0;
}