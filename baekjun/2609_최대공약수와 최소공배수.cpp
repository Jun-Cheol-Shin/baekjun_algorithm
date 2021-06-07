#include <iostream>
using namespace std;

int GCD(int left, int right)
{
	// 24 18
	// 18 6
	// 6 0
	if (right == 0) return left;
	return GCD(right, left % right);
}

int LCM(int left, int right, int gcd)
{
	return left * right / gcd;
}

int main()
{
	int a, b, gcd;

	cin >> a >> b;

	gcd = GCD(a, b);

	cout << gcd << endl;
	cout << LCM(a, b, gcd) << endl;
}