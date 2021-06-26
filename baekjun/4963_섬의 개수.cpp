#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 50
int dy[8] = { 1, 0, 0, -1, 1, 1, -1, -1 };
int dx[8] = { 0, 1, -1, 0, 1, -1, 1, -1 };

bool visited[MAX][MAX] = { false, };

bool check(int y, int x, int limit_y, int limit_x)
{
	return y >= 0 && x >= 0 && y < limit_y && x < limit_x;
}

void solved(const vector<vector<int>>& vec, int y, int x, int ly, int lx)
{
	queue<pair<int,int>> q;
	q.push({ y,x });

	while (!q.empty())
	{
		int curr_y = q.front().first;
		int curr_x = q.front().second;

		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int next_y = curr_y + dy[i];
			int next_x = curr_x + dx[i];

			if (check(next_y, next_x, ly, lx) && !visited[next_y][next_x] && vec[next_y][next_x] == 1)
			{
				q.push({ next_y, next_x });
				visited[next_y][next_x] = true;
			}
		}
	}
}

int main()
{

	while (1)
	{
		int count = 0;
		int y, x;
		cin >> x >> y;
		if (y == 0 && x == 0) break;

		memset(visited, false, sizeof(visited));

		vector<vector<int>> vec(y);
		for (int i = 0; i < y; ++i)
		{
			vector<int> tmp(x);
			for (int j = 0; j < x; ++j)
			{
				cin >> tmp[j];
			}
			vec[i] = tmp;
		}

		for (int i = 0; i < y; ++i)
		{
			for (int j = 0; j < x; ++j)
			{
				if (!visited[i][j] && vec[i][j] == 1)
				{
					count++;
					solved(vec, i, j, y, x);
				}
			}
		}

		cout << count << "\n";

	}

	return 0;
}