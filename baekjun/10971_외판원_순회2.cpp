#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 11

bool visit[MAX] = { false, };
int answer = 987654321;
int sum = 0;
int n;

void solved(const vector<vector<int>> vec, int curr, int start, int count, int sum)
{
	if (count == n && start == curr)
	{
		answer = min(answer, sum);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (vec[curr][i] == 0) continue;

		if (!visit[i])
		{
			visit[i] = true;
			sum += vec[curr][i];

			if (sum < answer)
			{
				solved(vec, i, start, count + 1, sum);
			}
			visit[i] = false;
			sum -= vec[curr][i];
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<vector<int>> vec(n);

	for (int i = 0; i < n; ++i)
	{
		vector<int> temp(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> temp[j];
		}
		vec[i] = temp;
	}

	for(int i = 0; i < n; ++i)
	{
		solved(vec, i, i, 0, 0);
	}

	cout << answer;

	return 0;
}