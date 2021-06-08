#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> vec;
	for (int i = 1; i <= n; ++i)
	{
		if (n % i == 0) vec.push_back(i);
	}

	if (vec.size() < k) cout << "0" << "\n";
	else cout << vec[k - 1] << "\n";

	return 0;
}