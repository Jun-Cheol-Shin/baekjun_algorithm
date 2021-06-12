#include <iostream>
using namespace std;
#include <vector>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector <vector<int>> vec;

	for (int i = 0; i < n; ++i)
	{
		vector<int> v;
		for (int j = 0; j <= i; ++j)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}
		vec.push_back(v);
	}


	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			vec[i][j] += max(vec[i + 1][j], vec[i + 1][j + 1]);

			//cout << vec[i][j] << endl;
		}
	}

	cout << vec[0][0] << "\n";

	return 0;
}