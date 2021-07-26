#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];

	int answer = 0;

	int coin = n - 1;

	while (k)
	{
		if (vec[coin] > k) coin--;


		else
		{
			k -= vec[coin];
			answer++;
		}
	}

	cout << answer;

	return 0;
}