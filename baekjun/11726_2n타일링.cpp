#include <iostream>
#include <cstring>
using namespace std;
#define DIV 10007
int d[1001];

int solved(int n)
{
	if (n == 1) return d[n] = 1;
	if (n == 2) return d[n] = 2;

	if (d[n] != -1) return d[n];
	else return d[n] = (solved(n - 1) + solved(n - 2)) % DIV;
}

int main()
{
	int n;
	cin >> n;

	memset(d, -1, sizeof(d));
	cout << solved(n);
}