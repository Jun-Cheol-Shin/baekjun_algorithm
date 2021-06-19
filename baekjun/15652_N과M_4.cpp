#include <iostream>
using namespace std;
#define MAX 9

int arr[MAX] = { 0, };
bool visited[MAX] = { false, };
int n, m;

void solved(int val, int a)
{
	if (val == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = a; i <= n; ++i)
	{
		arr[val] = i;
		solved(val + 1, i);
	}
}

int main()
{
	cin >> n >> m;
	solved(0, 1);

	return 0;
}