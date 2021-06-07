#include <iostream>
using namespace std;


int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int LCM(int a, int b)
{
	int gcd = GCD(a, b);

	return a * b / gcd;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << LCM(a, b) << "\n";
	}
}