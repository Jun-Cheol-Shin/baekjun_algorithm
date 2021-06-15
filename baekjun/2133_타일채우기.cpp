#include <iostream>
using namespace std;
#include <cstring>
int d[31];

int solved(int n)
{
	if (n % 2 != 0) return 0;
	if (n == 0) return 1;

	if (d[n] != -1) return d[n];

	int retval = 3 * solved(n - 2);

	for (int i = 4; i <= n; i += 2)
	{
		retval += 2 * solved(n - i);
	}

	return d[n] = retval;
}

int main()
{
	memset(d, -1, sizeof(d));
	int n;
	cin >> n;

	cout << solved(n) << endl;
}