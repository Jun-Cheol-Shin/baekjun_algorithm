#include <iostream>
#include <cstring>
using namespace std;
#define MAX 9

bool visited[MAX] = { false, };
int vec[MAX] = { 0, };
int n, m;

// 백 트래킹....
void solved(int val)
{
	if (val == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			vec[val] = i;
			solved(val + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	solved(0);
}