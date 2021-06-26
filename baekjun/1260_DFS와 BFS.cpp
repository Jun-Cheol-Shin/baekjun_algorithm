#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1001

bool visited[MAX] = { false, };
int arr[MAX][MAX] = { 0, };
int n, m, v;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		cout << curr << " ";

		for (int i = 1; i <= n; ++i)
		{
			if (!visited[i] && arr[curr][i] == 1)
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
	cout << "\n";
}

void dfs(int start)
{
	visited[start] = true;
	cout << start << " ";

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i] && arr[start][i])
		{
			dfs(i);
		}
	}
}

int main()
{
	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(v);
	cout << "\n";
	memset(visited, false, sizeof(visited));

	bfs(v);
	
	return 0;
}