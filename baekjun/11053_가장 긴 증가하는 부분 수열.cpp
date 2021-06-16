#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 1001
int dp[MAX];

int main()
{
	int answer = 1;

	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];


	for (int i = 0; i < n; ++i)
	{
		int value = vec[i];
		if (dp[value] == -1) dp[value] = 1;

		//printf("값 기준 : %d\n", value);
		for (int j = 0; j < i; ++j)
		{
			int val = 1;
			int temp = 0;

			for (int k = j; k < i; ++k)
			{
				if (value > vec[k] && temp < vec[k])
				{
					temp = vec[k];
					val = max(dp[temp] + 1, val);

					//printf("%d와 %d 비교 증가 : %d\n", value, vec[k], val);
				}
			}
			dp[value] = max(val, dp[value]);

			if (answer < dp[value]) answer = dp[value];
		}
	}

	cout << answer << endl;


	return 0;
}