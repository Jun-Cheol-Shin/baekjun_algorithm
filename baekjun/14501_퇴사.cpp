#include <iostream>
#include <vector>
using namespace std;
#define MAX 16

bool visited[MAX] = { false, };
int limit;
int n;
int answer = 0;

void solved(const vector<pair<int, int>>& vec, int sum, int daysum)
{
	if (daysum >= limit)
	{
		answer = max(answer, sum);
		return;
	}

	for (int i = daysum; i <= n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;

			if (i + vec[i].first > limit)
			{
				solved(vec, sum, i + vec[i].first);
			}
			else
			{
				solved(vec, sum + vec[i].second, i + vec[i].first);
			}

			visited[i] = false;
		}
	}


}

int main()
{
	cin >> n;
	vector<pair<int, int>> vec(n + 1);
	for (int i = 1; i <= n; ++i) cin >> vec[i].first >> vec[i].second;

	limit = n + 1;

	solved(vec, 0, 1);

	cout << answer;

	return 0;
}