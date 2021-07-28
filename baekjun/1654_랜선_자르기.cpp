#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>



int main()
{
	int k, n;
	cin >> k >> n;


	long long left = 1;
	long long right = 0;

	vector<long long> vec(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> vec[i];
		right = max(right, vec[i]);
	}
	sort(vec.begin(), vec.end());


	while (left <= right)
	{
		long long mid = (left + right) / 2;
		int div = 0;

		//cout << mid << "\n";

		for (int i = 0; i < k; ++i)
		{
			div += (vec[i] / mid);
		}

		//cout << div << "\n";

		if (div >= n)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << right;



	return 0;
}