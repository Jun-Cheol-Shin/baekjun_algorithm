#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool check[27];
int answer = 0;
int r, c;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool possible(int x, int y)
{
	return y >= 0 && x >= 0 && y < r && x < c;
}

void solved(const vector<vector<char>>& vec, int x, int y, int count)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (possible(nx, ny))
		{
			char val = vec[ny][nx];
			
			if (!check[val - 'A'])
			{
				check[val - 'A'] = true;
				solved(vec, nx, ny, count + 1);
				check[val - 'A'] = false;
			}
		}
	}

	answer = max(count, answer);
}

int main()
{
	memset(check, false, sizeof(check));
	cin >> r >> c;

	vector<vector<char>> vec(r);

	for (int i = 0; i < r; ++i)
	{
		vector<char> tmp(c);
		for (int j = 0; j < c; ++j)
		{
			cin >> tmp[j];
		}
		vec[i] = tmp;
	}

	check[vec[0][0] - 'A'] = true;
	solved(vec, 0, 0, 1);
	cout << answer;

	return 0;
}