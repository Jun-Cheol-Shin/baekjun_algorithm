#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

#define MAX 21
#define BABYSHARK 2

int n;
pair<int, int> start;
bool check[MAX][MAX];


void func(const vector<vector<int>>& vec)
{
	cout << "\n";
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

bool possible(int y, int x)
{
	return y >= 0 && x >= 0 && y < n && x < n;
}

int getDist(pair<int, int> axis)
{
	return abs(start.first - axis.first) + abs(start.second - axis.second);
}

bool sortFunc(pair<int, int> left, pair<int, int> right)
{
	if (left.first == right.first)
	{
		return left.second < right.second;
	}

	return left.first < right.first;
}

void getResult(vector<vector<int>>& vec, vector<pair<int,int>>& result, int& eat)
{
	eat += 1;
	sort(result.begin(), result.end(), sortFunc);

	pair<int, int> val = result[0];
	start = { val.first, val.second };
	vec[val.first][val.second] = 0;
}

int BFS(vector<vector<int>>& vec, int shark, int& eat)
{
	memset(check, false, sizeof(check));

	queue<pair<pair<int, int>, int>> q;
	q.push({ start, 0 });
	check[start.first][start.second] = true;

	vector<pair<int, int>> result;

	int flag = 0;

	while (!q.empty())
	{
		int cy = q.front().first.first;
		int cx = q.front().first.second;

		int count = q.front().second;

		q.pop();

		if (vec[cy][cx] > 0 && shark > vec[cy][cx])
		{
			if (flag == 0)
			{
				flag = count;
				result.push_back({ cy,cx });
			}

			else if (flag >= count)
			{
				result.push_back({ cy,cx });
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (possible(ny, nx) && !check[ny][nx] && vec[ny][nx] <= shark)
			{
				check[ny][nx] = true;
				q.push({ {ny,nx}, count + 1 });
			}
		}

	}


	if (result.size() > 0)
	{
		getResult(vec, result, eat);
		return flag;
	}

	else return -1;
}

int solved(vector<vector<int>>& vec)
{
	int answer = 0;
	int shark = BABYSHARK;
	int eat = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int result = BFS(vec, shark, eat);

			if (result == -1) return answer;
			else answer += result;

			if (eat >= shark)
			{
				shark++;
				eat = 0;
			}

			//printf("ÀÌµ¿ È½¼ö : %d, »ó¾î Å©±â : %d, ¸ÔÀº È½¼ö : %d\n", answer, shark, eat);
			//func(vec);
		}
	}

	return answer;
}

int main()
{
	cin >> n;
	vector<vector<int>> vec(n);

	for (int i = 0; i < n; ++i)
	{
		vector<int> tmp(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> tmp[j];
			if (tmp[j] == 9)
			{
				start = { i,j };
				tmp[j] = 0;
			}
		}
		vec[i] = tmp;
	}

	cout << solved(vec);


	return 0;
}