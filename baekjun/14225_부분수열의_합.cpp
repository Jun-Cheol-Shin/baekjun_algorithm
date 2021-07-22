#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
bool check[20 * 100000 + 1];

void solved(const vector<int>& vec, int sum, int count)
{
	if (count == n)
	{
		check[sum] = true;
		return;
	}

	solved(vec, sum + vec[count], count + 1);
	solved(vec, sum, count + 1);
}

int main()
{
	memset(check, false, sizeof(check));
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];
	solved(vec, 0, 0);

	for (int i = 1; i <= 20 * 100000; ++i)
	{
		if (!check[i])
		{
			cout << i;
			return 0;
		}
	}

	return 0;
}