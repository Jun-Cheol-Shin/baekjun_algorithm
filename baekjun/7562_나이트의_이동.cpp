#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 300

bool visited[MAX][MAX] = { false, };

int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

bool check(int x, int y, int n)
{
	return x >= 0 && y >= 0 && x < n&& y < n;
}

void print(const vector<vector<int>>& vec, int n)
{
	cout << "\n";
	cout << "°á°ú!" << "\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}

int solved(vector<vector<int>>& vec, int sy, int sx, int goal_y, int goal_x, int n)
{
	int answer = 0;

	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = true;

	while (!q.empty())
	{
		int curr_y = q.front().first;
		int curr_x = q.front().second;

		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int ny = curr_y + dy[i];
			int nx = curr_x + dx[i];

			if (check(ny, nx, n) && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				q.push({ ny, nx });
				vec[ny][nx] = vec[curr_y][curr_x] + 1;
				//print(vec, n);
			}
		}
	}

	return vec[goal_y][goal_x];
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		memset(visited, false, sizeof(visited));
		int n;
		cin >> n;
		vector<vector<int>> vec(n);
		for (int j = 0; j < n; ++j)
		{
			vector<int> temp(n, 0);
			vec[j] = temp;
		}

		int y, x, goal_y, goal_x;
		cin >> y >> x >> goal_y >> goal_x;

		cout << solved(vec, y, x, goal_y, goal_x, n) << "\n";
	}

	return 0;
}