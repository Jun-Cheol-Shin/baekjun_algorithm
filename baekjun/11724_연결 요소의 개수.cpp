#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001

bool visited[MAX] = { false, };
int n, m;

void solved(const vector<vector<int>>& vec, int curr)
{
	for (int i = 0; i < vec[curr].size(); ++i)
	{
		int c = vec[curr][i];
		if (!visited[c])
		{
			visited[c] = true;
			solved(vec, c);
		}
	}
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> vec(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}


	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			++answer;
			solved(vec, i);
		}
	}

	cout << answer;

	return 0;
}