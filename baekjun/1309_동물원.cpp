#include <iostream>
using namespace std;
#include <cstring>
int d[100001];

#define DIV 9901


int solved(int n)
{
	if (n == 1) return 3;
	else if (n == 2) return 7;
	
	if (d[n] != -1) return d[n];
	else return d[n] = ((2 * solved(n - 1)) + solved(n - 2)) % DIV;
}


int main()
{
	int N;
	cin >> N;
	memset(d, -1, sizeof(d));

	cout << solved(N) << "\n";

	return 0;
}