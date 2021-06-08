#include <iostream>
using namespace std;
#include <cstring>
#define MAX 10000

bool check[10001];

void setPrime()
{
	check[0] = false;
	check[1] = false;

	for (int i = 2; i * i <= MAX; ++i)
	{
		for (int j = i + i; j <= MAX; j += i)
		{
			check[j] = false;
		}
	}
}


int main()
{
	memset(check, true, sizeof(check));
	setPrime();

	int a, b;
	cin >> a >> b;

	int sum = 0;
	int min = b;

	for (int i = a; i <= b; ++i)
	{
		if (check[i])
		{
			sum += i;
			if (min > i) min = i;
		}
	}

	if (sum == 0) cout << "-1";
	else cout << sum << "\n" << min;

	return 0;
}