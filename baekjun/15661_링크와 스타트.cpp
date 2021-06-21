#include <iostream>
#include <vector>
using namespace std;
#define MAX 22

bool visited[MAX] = { false, };
int answer = 987654321;
int n;

void solved(const vector<vector<int>>& vec, int curr, int count, int limit)
{
	if (count == limit)
	{
		int link = 0, start = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (visited[i] && visited[j])
				{
					link += vec[i][j];
					link += vec[j][i];
				}
				else if (!visited[i] && !visited[j])
				{
					start += vec[i][j];
					start += vec[j][i];
				}
			}
		}

		answer = min(answer, abs(link - start));
		return;
	}

	for (int i = curr; i < n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			solved(vec, i + 1, count + 1, limit);
			visited[i] = false;
		}
	}
}

int main()
{
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

	for (int i = 1; i < n; ++i)
	{
		solved(vec, 0, 0, i);
	}

	cout << answer;

	return 0;
}