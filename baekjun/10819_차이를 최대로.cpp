#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int answer = 0;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];
	sort(vec.begin(), vec.end());

	do 
	{
		int sum = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			int ab = abs(vec[i] - vec[i + 1]);
			sum += ab;
		}
		answer = max(sum, answer);
	} while (next_permutation(vec.begin(), vec.end()));

	cout << answer;

	return 0;
}