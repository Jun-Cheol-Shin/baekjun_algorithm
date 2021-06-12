#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n;

	cin >> n;

	vector<int> vec(n + 1);

	for (int i = 1; i <= n; ++i) cin >> vec[i];


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			vec[i] = min(vec[i - j] + vec[j], vec[i]);
		}
	}

	cout << vec[n];

	return 0;
}