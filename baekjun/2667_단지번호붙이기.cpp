#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 26

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

bool visited[MAX][MAX] = { false, };

bool check(int y, int x, int limit)
{
	return y >= 0 && x >= 0 && y < limit && x < limit;
}

int BFS(const vector<vector<int>>& vec, int y, int x, int n)
{
	int count = 1;

	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty())
	{
		int curr_y = q.front().first;
		int curr_x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int next_y = curr_y + dy[i];
			int next_x = curr_x + dx[i];

			if (check(next_y, next_x, n) && !visited[next_y][next_x] && vec[next_y][next_x] == 1)
			{
				visited[next_y][next_x] = true;
				q.push({ next_y, next_x });
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> vec(n);
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;

		for (int j = 0; j < n; ++j)	vec[i].push_back(tmp[j] - '0');
	}

	vector<int> answer;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(vec[i][j] == 1 && !visited[i][j]) answer.push_back(BFS(vec, i, j, n));
		}
	}

	sort(answer.begin(), answer.end());
	int size = answer.size();

	cout << size << "\n";
	for (int i = 0; i < size; ++i) cout << answer[i] << "\n";

	return 0;
}