#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>> virus;

bool check[9][9];
bool wallCheck[9][9];
bool spreadCheck[9][9];

int answer = 0;
int n, m;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool possible(int y, int x)
{
	return y >= 0 && x >= 0 && y < n && x < m;
}

int checkSafe(const vector<vector<int>>& vec, int y, int x)
{
	int retval = 1;

	queue<pair<int, int>> q;
	q.push({ y,x });
	check[y][x] = true;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (possible(ny, nx) && !check[ny][nx] && vec[ny][nx] == 0)
			{
				q.push({ ny,nx });
				check[ny][nx] = true;
				++retval;
			}
		}
	}

	return retval;
}

void spread(const vector<vector<int>>& vec)
{
	memset(spreadCheck, false, sizeof(spreadCheck));

	vector<vector<int>> tmp = vec;
	queue<pair<int, int>> q;

	for (int i = 0; i < virus.size(); ++i)
	{
		q.push({ virus[i].first, virus[i].second });
		spreadCheck[virus[i].first][virus[i].second] = true;
	}

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (possible(ny, nx) && !spreadCheck[ny][nx] && tmp[ny][nx] == 0)
			{
				tmp[ny][nx] = 2;
				spreadCheck[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}

	int count = 0;
	memset(check, false, sizeof(check));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!check[i][j] && tmp[i][j] == 0)
			{
				count += checkSafe(tmp, i, j);
			}
		}
	}

	answer = max(count, answer);
}


void Wall(vector<vector<int>>& vec, int count)
{
	if (count == 3)
	{
		spread(vec);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (vec[i][j] == 0 && !wallCheck[i][j])
			{
				vec[i][j] = 1;
				wallCheck[i][j] = true;

				Wall(vec, count + 1);

				vec[i][j] = 0;
				wallCheck[i][j] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	vector<vector<int>> vec(n);

	for (int i = 0; i < n; ++i)
	{
		vector<int> tmp(m);
		for (int j = 0; j < m; ++j)
		{
			cin >> tmp[j];
			if (tmp[j] == 2) virus.push_back({ i,j });
		}
		vec[i] = tmp;
	}

	memset(wallCheck, false, sizeof(wallCheck));
	Wall(vec, 0);
	cout << answer;

	return 0;
}