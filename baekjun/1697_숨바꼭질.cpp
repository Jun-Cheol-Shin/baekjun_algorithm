#include <iostream>
#include <queue>
#include <cstring>

#include <algorithm>
using namespace std;

#define MAX 100001
#define LIMIT 100000

vector<int> answer_vec;
bool check[MAX] = { false, };

int solved(int goal, int start)
{
	int answer = 0;

	queue<pair<int,int>> q;
	q.push({ start, -1 });
	check[start] = true;

	vector<pair<int, int>> vec;
	vec.push_back({ start, -1 });
	int parent = -1;

	while (!q.empty())
	{
		int size = q.size();

		for (int i = 1; i <= size; ++i)
		{
			int cur = q.front().first;
			int p = q.front().second;
			q.pop();

			if (cur == goal)
			{
				answer_vec.push_back(cur);
				int next_index = p;

				while (next_index != -1)
				{
					answer_vec.push_back(vec[next_index].first);
					next_index = vec[next_index].second;
				}

				return answer;
			}

			if (0 < cur && !check[cur - 1])
			{
				vec.push_back({ cur - 1, parent + 1 });
				q.push({ cur - 1, parent + 1 });
				check[cur - 1] = true;
			}
			if (LIMIT > cur && !check[cur + 1])
			{
				vec.push_back({ cur + 1, parent + 1 });
				q.push({ cur + 1, parent + 1 });
				check[cur + 1] = true;
			}
			if (LIMIT >= cur * 2 && !check[cur * 2])
			{
				vec.push_back({ cur * 2, parent + 1 });
				q.push({ cur * 2, parent + 1 });
				check[cur * 2] = true;
			}
			++parent;
		}

		++answer;
	}
	
	return answer;
}

int main()
{
	int n, k;
	cin >> n >> k;

	memset(check, false, sizeof(check));

	cout << solved(k, n) << "\n";
	reverse(answer_vec.begin(), answer_vec.end());
	for (int i = 0; i < answer_vec.size(); ++i) cout << answer_vec[i] << " ";

	return 0;
}