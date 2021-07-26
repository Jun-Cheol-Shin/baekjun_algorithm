#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

bool waterCheck[51][51];
bool check[51][51];
int r, c;
int answer = INT_MAX;

vector<pair<int, int>> water;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool possible(int y, int x)
{
	return y >= 0 && x >= 0 && y < r && x < c;
}

void print(const vector<vector<char>>& vec)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << vec[i][j];
		}
		cout << "\n";
	}
}

void waterFull(vector<vector<char>>& vec)
{
	memset(waterCheck, false, sizeof(waterCheck));
	queue<pair<int, int>> q;

	for (int i = 0; i < water.size(); ++i)
	{
		q.push({ water[i].first, water[i].second });
		waterCheck[water[i].first][water[i].second] = true;
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

			if (possible(ny, nx) && !waterCheck[ny][nx] && (vec[ny][nx] == '.' || vec[ny][nx] == 'S'))
			{
				vec[ny][nx] = '*';
				waterCheck[ny][nx] = true;
				water.push_back({ ny,nx });
			}
		}
	}
}

void bfs(vector<vector<char>>& vec, pair<int, int> start, pair<int, int> end)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({start, 0});
	check[start.first][start.second] = true;

	int wave = 1;
	waterFull(vec);

	while (!q.empty())
	{
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int count = q.front().second;

		q.pop();

		if (wave <= count)
		{
			waterFull(vec);
			wave++;
		}

		if (cy == end.first && cx == end.second)
		{
			cout << count;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (possible(ny, nx) && !check[ny][nx] && (vec[ny][nx] == '.' || vec[ny][nx] == 'D'))
			{
				vec[cy][cx] = '.';
				check[ny][nx] = true;
				q.push({ { ny,nx }, count + 1 });
			}
		}

		//print(vec);
		//cout << "\n";
	}

	cout << "KAKTUS";
}

int main()
{
	memset(check, false, sizeof(check));

	cin >> r >> c;
	vector<vector<char>> vec(r);

	pair<int, int> start;
	pair<int, int> end;

	for (int i = 0; i < r; ++i)
	{
		vector<char> tmp(c);
		for (int j = 0; j < c; ++j)
		{
			cin >> tmp[j];

			if (tmp[j] == 'S')
			{
				start = { i,j };
			}

			else if (tmp[j] == 'D')
			{
				end = { i,j };
			}
			
			else if (tmp[j] == '*')
			{
				water.push_back({ i,j });
			}
		}
		vec[i] = tmp;
	}

	bfs(vec, start, end);
	//answer == INT_MAX ? cout << "KAKTUS" : cout << answer;


	return 0;
}