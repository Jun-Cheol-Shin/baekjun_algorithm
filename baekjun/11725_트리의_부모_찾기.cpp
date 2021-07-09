#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

bool visit[MAX] = { false, };

void BFS(const vector<vector<int>>& vec, vector<int>& answer, int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < vec[curr].size(); ++i)
		{
			int child = vec[curr][i];

			if (!visit[child])
			{
				q.push(child);
				visit[child] = true;
				answer[child] = curr;
			}
		}
	}

}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> vec(n + 1);
	vector<int> answer(n + 1);

	for (int i = 0; i < n - 1; ++i)
	{
		int left, right;
		cin >> left >> right;

		vec[left].push_back(right);
		vec[right].push_back(left);
	}

	BFS(vec, answer, 1);

	for (int i = 2; i <= n; ++i) cout << answer[i] << "\n";

	return 0;
}