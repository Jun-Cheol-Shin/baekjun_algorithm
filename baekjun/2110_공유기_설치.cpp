#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

int main()
{
	int n, c;
	cin >> n >> c;

	vector<int> vec(n);

	int low = 1, high = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
		high = max(high, vec[i]);
	}

	sort(vec.begin(), vec.end(), less<int>());

	while (low <= high)
	{
		int mid = (low + high) / 2;
		int count = 1;
		int start = 0;
		int plus = 1;

		for (int i = 0; i < n - 1; i++)
		{
			if (abs(vec[start] - vec[start + plus]) >= mid)
			{
				start = start + plus;
				plus = 1;

				count++;
			}

			else
			{
				plus++;
			}
		}

		if (count >= c)
		{
			low = mid + 1;
		}

		else
		{
			high = mid - 1;
		}

		//printf("mid : %d, count : %d, low : %d, high : %d\n", mid, count, low, high);
	}

	cout << high;


	return 0;
}