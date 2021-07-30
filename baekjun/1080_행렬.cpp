#include <iostream>
using namespace std;

#include <vector>
int n, m;

#define LIMIT_X 3
#define LIMIT_Y 3

bool possible(int y, int x)
{
	return y + LIMIT_Y <= n && x + LIMIT_X <= m;
}
bool diffrent(const vector<vector<int>>& vec, const vector<vector<int>>& answer, int y, int x)
{
	for (int i = y; i < y + LIMIT_Y; ++i)
	{
		for (int j = x; j < x + LIMIT_X; ++j)
		{
			if (vec[i][j] != answer[i][j]) return true;
		}
	}

	return false;
}
bool check(const vector<vector<int>>& vec, const vector<vector<int>>& answer)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (vec[i][j] != answer[i][j]) return false;
		}
	}

	return true;
}
void change(vector<vector<int>>& vec, int y, int x)
{
	for (int i = y; i < y + LIMIT_Y; ++i)
	{
		for (int j = x; j < x + LIMIT_X; ++j)
		{
			vec[i][j] == 0 ? vec[i][j] = 1 : vec[i][j] = 0;
		}
	}
}

void solved(vector<vector<int>>& vec, const vector<vector<int>>& answer)
{
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (possible(i, j) && vec[i][j] != answer[i][j])
			{
				change(vec, i, j);
				++ans;
			}

			if (check(vec, answer))
			{
				cout << ans;
				return;
			}
		}
	}

	cout << "-1";
}

int main()
{
	cin >> n >> m;

	vector<vector<int>> vec(n);
	vector<vector<int>> answer(n);

	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;

		vector<int> tmp(m);
		for (int j = 0; j < m; ++j)
		{
			tmp[j] = a[j] - '0';
		}
		vec[i] = tmp;
	}

	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;

		vector<int> tmp(m);
		for (int j = 0; j < m; ++j)
		{
			tmp[j] = a[j] - '0';
		}
		answer[i] = tmp;
	}

	solved(vec, answer);

	return 0;
}