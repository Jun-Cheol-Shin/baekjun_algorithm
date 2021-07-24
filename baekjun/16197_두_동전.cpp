#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

bool check[21][21][21][21];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int answer = INT_MAX;
int n, m;

bool range(int y, int x)
{
	return x >= 0 && y >= 0 && y < n && x < m;
}

void solved(const vector<vector<char>>& vec, vector<pair<int,int>>& coin, int count)
{
	if (count >= 10) return;
	if (coin[0].first == coin[1].first && coin[0].second == coin[1].second) return;

	int y = coin[0].first, x = coin[0].second;
	int yy = coin[1].first, xx = coin[1].second;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i], nx = x + dx[i];
		int nyy = yy + dy[i], nxx = xx + dx[i];

		if (!range(ny, nx) && !range(nyy, nxx)) continue;

		else if (!range(ny, nx) || !range(nyy, nxx)) {
			answer = min(count + 1, answer);
			continue;
		}

		else
		{
			if (vec[ny][nx] != '#' && vec[nyy][nxx] != '#')
			{
				if (!check[ny][nx][nyy][nxx])
				{
					coin[0] = { ny,nx };
					coin[1] = { nyy, nxx };
					check[ny][nx][nyy][nxx] = true;
					solved(vec, coin, count + 1);
					check[ny][nx][nyy][nxx] = false;
					coin[0] = { y,x };
					coin[1] = { yy,xx };
				}
			}

			else if (vec[nyy][nxx] != '#')
			{
				if (!check[y][x][nyy][nxx])
				{
					coin[1] = { nyy,nxx };
					check[y][x][nyy][nxx] = true;
					solved(vec, coin, count + 1);
					check[y][x][nyy][nxx] = false;
					coin[1] = { yy,xx };
				}
			}

			else if (vec[ny][nx] != '#')
			{
				if (!check[ny][nx][yy][xx])
				{
					coin[0] = { ny,nx };
					check[ny][nx][yy][xx] = true;
					solved(vec, coin, count + 1);
					check[ny][nx][yy][xx] = false;
					coin[0] = { y,x };
				}
			}

			else continue;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(check, false, sizeof(check));

	cin >> n >> m;

	vector<pair<int, int>> coin;
	vector<vector<char>> vec(n);

	for (int i = 0; i < n; ++i)
	{
		vector<char> tmp(m);
		for (int j = 0; j < m; ++j)
		{
			cin >> tmp[j];

			if (tmp[j] == 'o') coin.push_back({ i,j });			// y,x
		}
		vec[i] = tmp;
	}


	check[coin[0].first][coin[0].second][coin[1].first][coin[1].second] = true;

	solved(vec, coin, 0);
	answer != INT_MAX ? cout << answer : cout << "-1";


	return 0;
}