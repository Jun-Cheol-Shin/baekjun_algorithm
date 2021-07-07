#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

#define MAX 100
bool visited[MAX][MAX] = { false, };
int n, m;

bool check(int y, int x)
{
	return y >= 0 && x >= 0 && y < n && x < m;
}

void solved(vector<vector<int>>& vec, int start_x, int start_y)
{
	queue<pair<int, int>> q;
	q.push({ start_y, start_x });

	while (!q.empty())
	{
		int curr_y = q.front().first;
		int curr_x = q.front().second;
		q.pop();

		visited[curr_y][curr_x] = true;

		for (int i = 0; i < 4; ++i)
		{
			int ny = curr_y + dy[i];
			int nx = curr_x + dx[i];

			if (check(ny, nx) && vec[ny][nx] == 1 && !visited[ny][nx])
			{
				q.push({ ny, nx });
				vec[ny][nx] += vec[curr_y][curr_x];
			}
		}
	}

}

int main()
{
	cin >> n >> m;
	string tmp;
	vector<vector<int>> vec(n);

	for (int i = 0; i < n; ++i)
	{
		vector<int> temp(m);
		cin >> tmp;
		for (int j = 0; j < m; ++j)
		{
			temp[j] = tmp[j] - '0';
		}
		vec[i] = temp;
	}

	solved(vec, 0, 0);

	cout << vec[n - 1][m - 1];

	
	return 0;
}