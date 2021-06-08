#include <iostream>
using namespace std;
#include <cstring>

int d[11];

int solved(int n)
{
	if (n == 1) return d[n] = 1;
	else if (n == 2) return d[n] = 2;
	else if (n == 3) return d[n] = 4;

	if (d[n] != -1) return d[n];
	else return d[n] = solved(n - 1) + solved(n - 2) + solved(n - 3);
}

int main()
{
	int n;
	memset(d, -1, sizeof(d));
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int number;
		cin >> number;
		cout << solved(number) << "\n";
	}
}