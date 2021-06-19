#include <iostream>
using namespace std;
#define MAX 9

int arr[MAX] = { 0, };
bool visited[MAX] = { false, };
int n, m;

void solved(int a, int value)
{
	if (m == value)
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
		if (!visited[i])
		{
			visited[i] = true;
			arr[value] = i;
			solved(i, value + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	solved(1, 0);

	return 0;
}