#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(pair<int, int> left, pair<int, int> right)
{
	if (left.second == right.second)
	{
		return left.first < right.first;
	}

	return left.second < right.second;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i].first >> vec[i].second;
	}

	sort(vec.begin(), vec.end(), func);

	int end = 0;
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		if (end == 0 || end <= vec[i].first)
		{
			end = vec[i].second;
			++answer;
		}
	}

	cout << answer;
	return 0;
}