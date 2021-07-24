#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


bool check[201][201];

int answer;
int n;
int dy[6] = { -1, 1, -2, 2, -1, 1 };
int dx[6] = { -2, -2, 0, 0, 2, 2 };

bool possible(int r1, int c1)
{
	return r1 >= 0 && c1 >= 0 && r1 < n && c1 < n;
}

void bfs(int r1, int c1, int r2, int c2)
{
	queue<pair<pair<int, int>,int>> q;
	check[c1][r1] = true;
	q.push({ {c1, r1}, 0 });

	while (!q.empty())
	{
		int cy = q.front().first.first;
		int cx = q.front().first.second;

		int count = q.front().second;

		q.pop();

		if (cy == c2 && cx == r2)
		{
			answer = count;
			return;
		}

		for (int i = 0; i < 6; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (possible(nx, ny) && !check[ny][nx])
			{
				q.push({ {ny,nx}, count + 1 });
				check[ny][nx] = true;
			}
		}
	}
}


int main()
{
	memset(check, false, sizeof(check));

	cin >> n;

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	bfs(r1, c1, r2, c2);

	answer == 0 ? cout << "-1" : cout << answer;

	return 0;
}