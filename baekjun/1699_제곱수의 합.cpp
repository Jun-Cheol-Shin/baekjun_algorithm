#include <iostream>
using namespace std;
#include <cstring>
int d[100001];

int main()
{
	memset(d, -1, sizeof(d));
	int n;
	cin >> n;

	d[0] = 0;
	d[1] = 1;

	// 3 => 1 1 1
	// 4 => 4
	// 5 => 1 1 1 1 , 4 1
	// 6 => 1 1 1 1 1 1, 4 1 1
	// 7 => 4 1 1 1
	// 8 => 4 4
	// 9 => 9
	// 10 => 9, 1
	// 11 => 9 1 1

	for (int i = 2; i <= n; ++i)
	{
		d[i] = i;
		for (int j = 2; j * j <= i; ++j)
		{
			d[i] = min(d[i - j * j] + 1, d[i]);
		}
	}

	cout << d[n] << endl;

	return 0;
}