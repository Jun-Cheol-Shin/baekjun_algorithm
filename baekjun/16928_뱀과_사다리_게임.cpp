#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int answer;
bool check[101];

void bfs(const vector<vector<int>>& vec)
{
	queue<pair<int,int>> q;
	q.push({1, 0});
	check[1] = true;

	while (!q.empty())
	{
		int curr = q.front().first;
		int count = q.front().second;
		q.pop();

		if (curr == 100)
		{
			answer = count;
			return;
		}

		for (int i = 1; i <= 6; ++i)
		{
			int x = curr + i;
			if (x > 100) continue;

			if (vec[x].size() > 0) x = vec[x][0];

			if (!check[x])
			{
				q.push({ x, count + 1 });
				check[x] = true;
			}
		}
	}
}

int main()
{
	memset(check, false, sizeof(check));
	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(101);

	for (int i = 0; i < n + m; ++i)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
	}

	bfs(vec);
	cout << answer;


	return 0;
}