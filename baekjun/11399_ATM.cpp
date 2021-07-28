#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(pair<int, int> left, pair<int, int> right)
{
	return left.second < right.second;
}

int main()
{
	int n, answer, number;
	cin >> n;

	vector<pair<int,int>> vec(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> number;
		vec[i].first = i;
		vec[i].second = number;
	}

	sort(vec.begin(), vec.end(), func);

	answer = 0;

	for (int i = 1; i <= n; ++ i)
	{
		for (int j = 1; j <= i; ++j)
		{
			answer += vec[j].second;
		}
	}

	cout << answer;

	return 0;
}