#include <iostream>
using namespace std;
#include <cstring>
int d[1001][10];

#define DIV 10007


// 1 + 1 + 1 + 1 ...
// 9 + 8 + 7 + 6 ...
// 55 + 45 + 36 + 28 + 21 + 15 + 10 ...

int main()
{
	for (int i = 0; i < 10; ++i) d[1][i] = 1;

	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = j; k < 10; ++k)
			{
				d[i][j] = (d[i][j] + d[i - 1][k]) % DIV;
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < 10; ++i)
	{
		answer = (answer + d[n][i]) % DIV;
	}

	cout << answer << endl;
}