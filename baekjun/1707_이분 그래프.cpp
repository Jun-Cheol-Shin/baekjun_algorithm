#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 20001
bool visited[MAX] = { false, };

bool solved(const vector<vector<int>>& vec, vector<int> check, int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	check[start] = 1;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		int curr_check = check[curr];

		for (int i = 0; i < vec[curr].size(); ++i)
		{
			int tmp = vec[curr][i];

			if (!visited[tmp] && check[tmp] == 0)
			{
				switch (curr_check)
				{
				case 1:
					check[tmp] = 2;
					break;
				case 2:
					check[tmp] = 1;
					break;
				}

				visited[tmp] = true;
				q.push(tmp);
			}

			if (curr_check != 0 && curr_check == check[tmp]) return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	bool flag = false;
	int k;
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		flag = false;
		memset(visited, false, sizeof(visited));
		int v, e;
		cin >> v >> e;
		vector<vector<int>> vec(v + 1);
		vector<int> check(v + 1, 0);

		for (int i = 0; i < e; ++i)
		{
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}

		for (int i = 1; i <= v; ++i)
		{
			if (!solved(vec, check, i)) flag = true;
		}

		if (flag) cout << "NO" << "\n";
		else cout << "YES" << "\n";

	}

	return 0;
}