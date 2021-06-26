#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int n, m;

void solved(int curr, int sum, vector<int> vec)
{
	if (sum == n)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
		answer++;
		return;
	}

	for (int i = curr; i <= m; ++i)
	{
		if (sum + i <= n)
		{
			vec.push_back(i);
			solved(i, sum + i, vec);
			vec.pop_back();
		}
	}
}

int main()
{
	vector<int> vec;
	cin >> n >> m;
	solved(1, 0, vec);

	cout << "\n";
	cout << "°³¼ö : " << answer;

	return 0;
}