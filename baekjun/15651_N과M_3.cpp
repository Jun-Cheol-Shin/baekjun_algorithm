#include <iostream>
using namespace std;

#define MAX 8

int m, n;
int arr[MAX] = { 0, };

void solved(int value)
{
	if (value == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << " ";
		}

		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		arr[value] = i;
		solved(value + 1);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	solved(0);
	
	return 0;
}