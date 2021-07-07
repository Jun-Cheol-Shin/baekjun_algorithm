#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define LMT 101

bool visited[LMT][LMT] = { false, };
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

bool isPossible(int cy, int cx, int ly, int lx)
{
	return cy >= 0 && cx >= 0 && cy < ly && cx < lx;
}

void solved(vector<vector<int>>& vec, int x, int y)
{
	int finish_y = y - 1;
	int finish_x = x - 1;

	int answer = 987654321;

	deque<pair<pair<int, int>, int>> d;
	d.push_back({ { 0, 0 }, 0 });
	visited[0][0] = true;

	while (!d.empty()) 
	{
		int cy = d.front().first.first;
		int cx = d.front().first.second;
		int count = d.front().second;

		d.pop_front();

		if (cy == finish_y && cx == finish_x)
		{
			cout << count << "\n";
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (isPossible(ny, nx, y, x) && !visited[ny][nx])
			{
				if (vec[ny][nx] == 0) d.push_front({ { ny,nx }, count });
				else if (vec[ny][nx] == 1) d.push_back({ { ny,nx }, count + 1 });
				visited[ny][nx] = true;
			}
		}
	}

	cout << answer << "\n";
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(m);

	for (int i = 0; i < m; ++i)
	{
		vector<int> temp(n);
		string a;
		cin >> a;

		for (int j = 0; j < n; ++j)
		{
			temp[j] = a[j] - '0';
		}

		vec[i] = temp;
	}

	solved(vec, n, m);


	return 0;
}