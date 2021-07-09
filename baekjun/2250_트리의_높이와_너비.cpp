#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
#define LMT 10001

bool visit[LMT] = { false, };
int lev = 1;
pair<int, int> answer = { 1,1 };

int findRoot(const vector<vector<int>>& vec, int n)
{
	int root = -1;

	while (1)
	{
		bool flag = false;

		for (int i = n; i > 0; --i)
		{
			for (int j = 0; j < 2; ++j)
			{
				if (vec[i][j] == root || root == -1)
				{
					flag = true;
					root = i;
				}
			}
		}

		if (!flag) break;
	}

	return root;
}

void solved(const vector<vector<int>>& vec, const vector<int>& level, int root)
{
	queue<int> q;
	q.push(root);
	visit[root] = true;

	int floor = 2;

	while (!q.empty())
	{
		int size = q.size();
		int lev_min = 987654321;
		int lev_max = 0;

		for (int i = 0; i < size; ++i)
		{
			int curr = q.front();
			q.pop();

			for (int j = 0; j < 2; ++j)
			{
				int val = vec[curr][j];
				if (val != -1 && !visit[val])
				{
					visit[val] = true;
					q.push(val);
					lev_min = min(level[val], lev_min);
					lev_max = max(level[val], lev_max);
				}
			}
		}

		int tmp = lev_max - lev_min + 1;
		if (tmp > answer.second) answer = { floor, tmp };

		floor++;
	}
}

void setInOrder(const vector<vector<int>>& vec, vector<int>& level, int root)
{
	if (root == -1 || root == INF) return;

	setInOrder(vec, level, vec[root][0]);
	level[root] = lev++;
	setInOrder(vec, level, vec[root][1]);
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> vec(n + 1);
	vector<int> level(n + 1);

	for (int i = 0; i < n; ++i)
	{
		int parent, l, r;
		cin >> parent >> l >> r;

		vec[parent].push_back(l);
		vec[parent].push_back(r);
	}

	int root = findRoot(vec, n);

	setInOrder(vec, level, root);
	solved(vec, level, root);
	//cout << "최상단 노드 : " << root << "\n";
	cout << answer.first << " " << answer.second;

	return 0;
}