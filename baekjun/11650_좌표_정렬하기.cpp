#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i].first >> vec[i].second;

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; ++i)
	{
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
	
	

	return 0;
}