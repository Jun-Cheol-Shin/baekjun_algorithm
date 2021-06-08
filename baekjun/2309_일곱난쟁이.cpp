#include <iostream>
using namespace std;
#include <vector>
#include <set>
#define LIMIT 100

set<int> solved(const vector<int>& vec)
{
	int sum = 0;
	set<int> s;

	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec.size() && j != i; ++j)
		{
			s.clear();
			sum = 0;
			for (int k = 0; k < vec.size(); ++k)
			{
				if (k != j && k != i)
				{
					s.insert(vec[k]);
					sum += vec[k];
				}
			}

			if (sum == LIMIT) return s;
		}
	}

	return s;
}

int main()
{
	vector<int> vec(9);
	for (int i = 0; i < 9; ++i) cin >> vec[i];

	set<int> answer = solved(vec);

	for (auto iter : answer)
	{
		printf("%d\n", iter);
	}
}