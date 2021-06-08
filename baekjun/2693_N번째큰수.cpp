#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		vector<int> vec(10);
		for (int i = 0; i < 10; ++i) cin >> vec[i];
		sort(vec.begin(), vec.end(), greater<int>());
		
		cout << vec[2] << "\n";
	}
	

	return 0;
}