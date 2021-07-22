#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
#define MAX_CAPACITY 100001

int dp[MAX][MAX_CAPACITY];

int main()
{
	vector<pair<int, int>> vec;

	int n, k;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int w, v;
		cin >> w >> v;
		vec.push_back({ w,v });
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j - vec[i - 1].first >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec[i - 1].first] + vec[i - 1].second);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k] << "\n";


	return 0;
}