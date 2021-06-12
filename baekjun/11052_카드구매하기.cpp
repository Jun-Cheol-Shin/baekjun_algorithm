#include <iostream>
using namespace std;
#include <vector>
#include <cstring>

int main()
{
	int n;
	cin >> n;

	vector<int> vec(n + 1);
	for (int i = 1; i <= n; ++i)	cin >> vec[i];


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			// 1장일때 : 1
			// 2장일때 : 1 + 1, 2
			// 3장일때 : 2 + 1, 3, 
			vec[i] = max(vec[i - j] + vec[j], vec[i]);

			//printf("%d장을 구매할 때 : %d\n", i, vec[i]);
		}
	}


	cout << vec[n] << endl;

	return 0;
}