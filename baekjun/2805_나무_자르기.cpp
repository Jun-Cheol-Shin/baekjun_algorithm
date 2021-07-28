#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	long long max_tree = 0;
	long long min_tree = 1;

	vector<long long> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
		max_tree = max(vec[i], max_tree);
	}

	while (min_tree <= max_tree)
	{
		long long mid = (min_tree + max_tree) / 2;
		long long take = 0;

		for (int i = 0; i < n; ++i)
		{
			if (vec[i] - mid > 0)
			{
				take += (vec[i] - mid);
			}
		}

		if (take >= m)
		{
			min_tree = mid + 1;
		}

		else
		{
			max_tree = mid - 1;
		}
		
		//printf("max : %d , min : %d take : %d\n", max_tree, min_tree, take);
	}

	cout << max_tree;



	return 0;
}