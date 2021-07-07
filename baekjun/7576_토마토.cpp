#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1000
bool visited[MAX][MAX] = { false, };

int dy[4] = { 1, 0, 0, -1 };
int dx[4] = { 0, 1, -1, 0 };

int n, m;

bool check(int y, int x)
{
	return y >= 0 && x >= 0 && y < n && x < m;
}

void solved(vector<vector<int>>& vec, const vector<pair<int, int>>& start)
{
	//int answer = 0;

	queue<pair<int, int>> q;

	for (int i = 0; i < start.size(); ++i) q.push({ start[i].first, start[i].second });

	
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (check(ny, nx) && !visited[ny][nx] && vec[ny][nx] == 0)
			{
				vec[ny][nx] = vec[cy][cx] + 1;
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

int getAnswer(const vector<vector<int>>& vec)
{
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (vec[i][j] == 0)
				return -1;
			answer = max(answer, vec[i][j] - 1);
		}
	}

	return answer;
}

int main()
{
	int answer = -1;
	cin >> m >> n;

	vector<pair<int, int>> start;
	vector<vector<int>> vec(n);

	for (int i = 0; i < n; ++i)
	{
		vector<int> temp(m);
		for (int j = 0; j < m; ++j)
		{
			cin >> temp[j];
			if (temp[j] == 1)
			{
				start.push_back({ i, j });
			}
		}
		vec[i] = temp;
	}

	solved(vec, start);

	// 배열 상황 보기
	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < m; ++j)
	//	{
	//		cout << vec[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	cout << getAnswer(vec);

	return 0;
}