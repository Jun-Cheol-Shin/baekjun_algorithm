#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}


	return 0;
}