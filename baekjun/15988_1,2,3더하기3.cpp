#include <iostream>
using namespace std;
#include <cstring>
int d[1000001];


#define DIV 1000000009

long long solved(int n)
{
	if (n == 1) return 1;			// 1
	else if (n == 2) return 2;		// 1 + 1, 2
	else if (n == 3) return 4;		// 1 + 1 + 1, 2 + 1, 1 + 2, 3

	if (d[n] != -1) return d[n];
	else return d[n] = (solved(n - 1) + solved(n - 2) + solved(n - 3)) % DIV;
}


int main()
{
	memset(d, -1, sizeof(d));

	int T;
	cin >> T;
	int number;

	while (T--)
	{
		cin >> number;
		cout << solved(number) << "\n";
	}
}